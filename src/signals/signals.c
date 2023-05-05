#include <signal.h>
#include <stdio.h>
#include <readline/readline.h>
#include <termios.h>
#include <unistd.h>

#include "signals.h"

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
