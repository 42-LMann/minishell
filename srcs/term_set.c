#include <termios.h>
#include <libft.h>

void	restore_term_settings(struct termios *termios_p)
{
	tcsetattr(2, TCSANOW, termios_p);
}

void	save_term_settings(struct termios *termios_p)
{
	tcgetattr(2, termios_p);
}

void	set_term_settings(void)
{
	struct termios	termios_p;

	ft_bzero(&termios_p, sizeof(struct termios));
	tcgetattr(2, &termios_p);
	termios_p.c_lflag &= (~ECHOCTL | ISIG);
	tcsetattr(2, TCSANOW, &termios_p);
}