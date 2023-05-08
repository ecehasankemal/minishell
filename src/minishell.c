/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:09:04 by hece              #+#    #+#             */
/*   Updated: 2023/05/08 23:21:57 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "global.h"
#include "env.h"
#include "exec.h"
#include "lexer.h"
#include "parser.h"
#include "signals.h"

static inline char	*get_input(void);
static inline void	process_input(char *input);

/* 
 * ----------------------------------------------------------------------------
 * "signal" fonksiyonu, belirtilen sinyal numarası ile eşleşen sinyal
 * işleyicisini ayarlar
 * ----------------------------------------------------------------------------
 * "SIGQUIT" sinyal numarası klavyeden çıkmayı (CTRL + \) temsil eder
 * ve "SIG_IGN", sinyal işleyicisinin yoksayılması anlamına gelir.
 * ----------------------------------------------------------------------------
 * "env_init" fonksiyonu, çevre değişkenlerini ortama yükler
 * ve "g_env" değişkenine değer atar
 * ----------------------------------------------------------------------------
 * "ERROR" değeri, bir hata durumunu temsil eder.
 * ----------------------------------------------------------------------------
 * Sonsuz bir döngü başlatılır
 * ----------------------------------------------------------------------------
 * "Signal" fonksiyonu, belirtilen sinyal numarası ile eşleşen
 * sinyal işleyicisini ayarlar
 * ----------------------------------------------------------------------------
 * "SIGINT" sinyal numarası, CTRL + C ile çıkmayı temsil eder
 * ve "signal_ctrlc" fonksiyonuna bağlı bir işleyici atar.
 * ----------------------------------------------------------------------------
 * "termios_change" fonksiyonu, terminal girdi/çıktısının
 * değiştirilmesini sağlar
 * ----------------------------------------------------------------------------
 * "false" parametresi, terminal ayarlarının değiştirileceğini belirtir.
 * ----------------------------------------------------------------------------
 * "get_input" fonksiyonu, kullanıcı girdisini okur ve bir karakter dizisi
 * olarak döndürür.
 * ----------------------------------------------------------------------------
 * Eğer "input" değeri "NULL" ise, programdan çıkılır.
 * ----------------------------------------------------------------------------
 * "isatty" fonksiyonu, belirtilen dosya tanımlayıcısının bir terminal cihazı
 * olup olmadığını kontrol eder.
 * ----------------------------------------------------------------------------
 * "STDERR_FILENO", standart hata çıkışını temsil eder.
 * ----------------------------------------------------------------------------
 * "termios_change" fonksiyonu, terminal girdi/çıktısının
 * değiştirilmesini sağlar
 * ----------------------------------------------------------------------------
 * "true" parametresi, terminal ayarlarının önceki hallerine
 * geri döneceğini belirtir. Ve döngü kapatılır....
 * ----------------------------------------------------------------------------
 * "process_input" fonksiyonu, kullanıcı girdisini analiz eder ve uygun
 * şekilde işlem yapar.
 * ----------------------------------------------------------------------------
 * "rl_clear_history" fonksiyonu,
 * "readline kütüphanesinin" komut geçmişini temizler.
 * ----------------------------------------------------------------------------
 * "g_env" değişkeni varsa, bellekten temizlenir.
 * ----------------------------------------------------------------------------
 * "exec_exit_status_get" fonksiyonu,
 * son işlem çıkış durumunu döndürür.
 * ----------------------------------------------------------------------------
 */

char	**g_env = NULL;

int
	main(void)
{
	char	*input;

	signal(SIGQUIT, SIG_IGN);
	if (env_init() == ERROR)
		return (EXIT_FAILURE);
	while (42)
	{
		signal(SIGINT, signal_ctrlc);
		termios_change(false);
		input = get_input();
		if (input == NULL)
		{
			if (isatty(STDERR_FILENO))
				ft_putendl_fd("exit", STDERR_FILENO);
			termios_change(true);
			break ;
		}
		process_input(input);
	}
	rl_clear_history();
	if (g_env)
		ft_free_split(&g_env);
	exit(exec_exit_status_get());
}

/*
 * user@computer:~$ == PS1 environment
 */

/*
 * ----------------------------------------------------------------------------
 * "static inline" anahtar kelimeleri, bu fonksiyonun sadece bu dosya içinde
 * kullanılacağını ve derleyici tarafından optimize edilebileceğini
 * belirtir.
 * ----------------------------------------------------------------------------
 * "input" ve "prompt" adında iki karakter işaretçisi tanımlanıyor.
 * ----------------------------------------------------------------------------
 * "env_get_value" fonksiyonu, "PS1" adlı ortam değişkeninin değerini
 * döndürür ve "prompt" işaretçisine atar.
 * ----------------------------------------------------------------------------
 * Eğer "prompt" işaretçisi "NULL" ise, "PROMPT" değeri atanır.
 * ----------------------------------------------------------------------------
 * Eğer standart giriş "(STDIN_FILENO)" terminalden alınıyorsa "(isatty)",
 * "readline" fonksiyonu ile girdi alınır ve "input" işaretçisine atanır.
 * ----------------------------------------------------------------------------
 * Standart giriş terminalden alınmıyorsa, "minishell_get_next_line"
 * fonksiyonu kullanılır.
 * ----------------------------------------------------------------------------
 * Eğer "input" işaretçisi NULL ise, NULL döndürülür.
 * ----------------------------------------------------------------------------
 * Eğer standart giriş terminalden alınıyorsa ve "input" NULL
 * değilse ve "input" dizisi boş değilse, "input" dizisini geçmişe ekler.
 * ----------------------------------------------------------------------------
 * Fonksiyon, "input" işaretçisini döndürür.
 * ----------------------------------------------------------------------------
 */

static inline char
	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = env_get_value("PS1");
	if (prompt == NULL)
		promt = PROMPT;
	if (isatty(STDIN_FILENO))
		input = readline(prompt);
	else
		input = minishell_get_next_line(STDIN_FILENO);
	if (input == NULL)
		return (NULL);
	else if (isatty(STDIN_FILENO) && input && input[0])
		add_history(input);
	return (input);
}

/*
 * signal(SIGINT, SIG_IGN); == you not use ctrl + c so not close process
 */

/*
 * ----------------------------------------------------------------------------
 * "l_token" ve "l_parser" adında iki bağlı liste işaretçisi
 * tanımlanıyor.
 * ----------------------------------------------------------------------------
 * "signal" fonksiyonu, SIGINT sinyalini (ör. Ctrl+C) yoksayacak
 * şekilde ayarlanır.
 * ----------------------------------------------------------------------------
 * "errno" değeri sıfırlanır, hataların takibi için kullanılır.
 * ----------------------------------------------------------------------------
 * "l_token" ve "l_parser" işaretçileri NULL ile başlatılır.
 * ----------------------------------------------------------------------------
 * "lexer" fonksiyonu, kullanıcıdan alınan girdiyi analiz eder ve girdiyi
 * tanımlayıcılar (tokens) listesine dönüştürür.
 * Bu liste "l_token" işaretçisine atanır.
 * ----------------------------------------------------------------------------
 * "input" işaretçisi serbest bırakılır, artık kullanılmayacak.
 * ----------------------------------------------------------------------------
 * Eğer "l_token" işaretçisi "NULL" değilse, "parser" fonksiyonu ile
 * "l_token" listesi işlenir ve "l_parser" listesi oluşturulur.
 * ----------------------------------------------------------------------------
 * Eğer "l_token" ve "l_parser" işaretçileri "NULL" değilse,
 * "exec_recursive" fonksiyonu çağrılır ve komutlar işlenir.
 * ----------------------------------------------------------------------------
 * Eğer "l_parser" işaretçisi "NULL" değilse, listeyi temizler ve
 * kaynakları serbest bırakır.
 * ----------------------------------------------------------------------------
 * Eğer "l_token" işaretçisi "NULL" değilse ve "l_parser" "NULL" ise,
 * "l_token" listesini temizler ve kaynakları serbest bırakır.
 * ----------------------------------------------------------------------------
 */

static inline void
	process_input(char *input)
{
	t_list	*l_token;
	t_list	*l_parser;

	signal(SIGINT, SIG_IGN);
	errno = 0;
	l_token = NULL;
	l_parser = NULL;
	t_token = lexer(input);
	free(input);
	if (l_token != NULL)
		l_parser = parser(t_token);
	if (l_token != NULL && l_parser != NULL)
		exec_recursive(l_parser, false, l_parser);
	if (l_parser != NULL)
		ft_lstclear(&l_parser, c_cmd_destroy);
	else if (l_token != NULL)
		ft_lstclear(&l_token, c_token_destroy);
}
