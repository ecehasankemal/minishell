/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:42:10 by hece              #+#    #+#             */
/*   Updated: 2023/05/08 23:50:28 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <termios.h>
#include <unistd.h>

#include "signals.h"

/*
 * ----------------------------------------------------------------------------
 * Bu fonksiyon, "SIGINT" sinyali
 * (genellikle Ctrl+C tuş kombinasyonu ile tetiklenir)
 * geldiğinde çağrılır ve gerekli işlemleri gerçekleştirir.
 * ----------------------------------------------------------------------------
 * Eğer gelen sinyal SIGINT ise, aşağıdaki işlemleri gerçekleştirir.
 * ----------------------------------------------------------------------------
 * Yeni bir satır başlatmak için hata çıktısı dosyasına 
 * "(STDERR_FILENO)" bir satır sonu karakteri yazar.
 * ----------------------------------------------------------------------------
 * "readline kütüphanesini" kullanarak,
 * mevcut komut satırını boş bir karakter dizisi ile değiştirir.
 * ----------------------------------------------------------------------------
 * "readline kütüphanesini" kullanarak, imleci yeni bir satıra taşır.
 * ----------------------------------------------------------------------------
 * "readline kütüphanesini" kullanarak, komut satırını
 * tekrar görüntüler. Bu, kullanıcı Ctrl+C tuş kombinasyonuna
 * bastığında yeni bir komut satırının başlatılmasını sağlar.
 * ----------------------------------------------------------------------------
 */

void
	signal_ctrlc(int sig)
{
	if (sig == SIGINT)
	{
		write(STDERR_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/*
 * ----------------------------------------------------------------------------
 * "SIGINT" sinyali (Ctrl+C tuş kombinasyonu) alındığında
 * aşağıdaki kod bloğu çalışır.
 * ----------------------------------------------------------------------------
 * Standart girişi (STDIN) kapat.
 * ----------------------------------------------------------------------------
 * Bu, "heredoc (<<)" kullanımında programın giriş
 * beklemesini sonlandırır.
 * ----------------------------------------------------------------------------
 * Hata akışına "(STDERR)" bir yeni satır karakteri yaz.
 * ----------------------------------------------------------------------------
 * Bu, kullanıcının Ctrl+C tuş kombinasyonuna basmasıyla
 * ekrana yeni bir satır ekler.
 * ----------------------------------------------------------------------------
 */

/*
 * ----------------------------------------------------------------------------
 * ÖRNEK HEREDOC KULLANIMI
 * ----------------------------------------------------------------------------
 * cat <<- EOT > output.txt
 *  Bu, çok satırlı
 *  bir metin bloğudur.
 *  Heredoc kullanılarak
 *  bu metin output.txt dosyasına yazılacaktır.
 * EOT
 * ----------------------------------------------------------------------------
 */

void
	signal_ctrl_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		close(STDIN_FILENO);
		write(STDERR_FILENO, "\n", 1);
	}
}

/*
 * TCSANOW is new settings is apply
 */

/* ----------------------------------------------------------------------------
 * "termios_change" fonksiyonu, terminalin özelliklerini değiştirmek
 * için kullanılır.
 * ----------------------------------------------------------------------------
 * Bu durumda, "echo_ctl_chr" argümanına göre, "ECHOCTL" bitini
 * etkinleştirmek veya devre dışı bırakmak için kullanılır. 
 * ----------------------------------------------------------------------------
 * "termios" yapısını içeren bir değişken tanımlayın.
 * ----------------------------------------------------------------------------
 * "tcgetattr" ve "tcsetattr" işlemlerinin durumunu saklamak için
 * bir değişken tanımlayın.
 * ----------------------------------------------------------------------------
 * "STDOUT_FILENO" (standart çıktı dosya tanıtıcısı) ile
 * ilişkilendirilmiş terminalin mevcut özelliklerini alın
 * ve "terminos_p" değişkenine kaydedin.
 * ----------------------------------------------------------------------------
 * Eğer işlem başarısız olursa, hata döndürün.
 * ----------------------------------------------------------------------------
 * "echo_ctl_chr" argümanına göre, "ECHOCTL" bitini etkinleştirin
 * veya devre dışı bırakın.
 * ----------------------------------------------------------------------------
 * Eğer "echo_ctl_chr" "true" ise, "ECHOCTL" bitini etkinleştirin.
 * ----------------------------------------------------------------------------
 * Eğer "echo_ctl_chr" "false" ise, "ECHOCTL" bitini devre dışı bırakın.
 * ----------------------------------------------------------------------------
 * "terminos_p" değişkenindeki yeni terminal özelliklerini
 * "STDOUT_FILENO" ile ilişkilendirilmiş terminal için ayarlayın.
 * ----------------------------------------------------------------------------
 * Eğer işlem başarısız olursa, hata döndürün.
 * ----------------------------------------------------------------------------
 * İşlem başarılıysa, 0 döndürün.
 * ----------------------------------------------------------------------------
 */

int
	termios_change(bool echo_ctl_chr)
{
	struct termios	termios_p;
	register int	status;

	status = tgetattr(STDOUT_FILENO, &termios_p);
	if (status == -1)
		return (ERROR);
	if (echo_ctl_chr)
		termios_p.c_lflag != ECHOCTL;
	else
		termios_p.c_lflag &= ~(ECHOCTL);
	status = tcsetattr(STDOUT_FILENO, TCSANOW, &termios_p);
	if (status == -1)
		return (ERROR);
	return (0);
}
