#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/minitalk.h"

t_stack p_print = {{0}, 1 << 6, 0, FALSE, FALSE}; 

void	onebit(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;
	(void) info;

	if (!p_print.bit)
	{
		p_print.bit = 1 << 6;
		++(p_print.byte);
	}
	p_print.message[p_print.byte] += p_print.bit;
	p_print.bit >>= 1;
	if (p_print.byte == BUFFSIZE - 2 && !p_print.bit)
		p_print.overflow = TRUE;
}

void	zerobit(int sig, siginfo_t *info, void *context)
{
	(void) sig;
	(void) context;

	if (!p_print.bit)
	{
		p_print.bit = 1 << 6;
		++(p_print.byte);
	}
	p_print.bit >>= 1;
	if (p_print.byte == BUFFSIZE - 2 && !p_print.bit)
		p_print.overflow = TRUE;
	else if (!(p_print.message[p_print.byte]) && !p_print.bit)
	{
		kill(getpid(), SIGUSR1);
		p_print.receive = TRUE;
	}	
}

int main(void)
{
	struct sigaction obit;
	struct sigaction zbit;

	obit.sa_sigaction = onebit;
	zbit.sa_sigaction = zerobit;

	if (sigaction(SIGUSR1, &obit, NULL) != 0)
	{
		write(1, "signal error\n", ft_strlen("signal error\n"));
		exit(1);
	}
	if (sigaction(SIGUSR2, &zbit, NULL) != 0)
	{
		write(1, "signal error\n", ft_strlen("signal error\n"));
		exit(1);
	}
    write(1, ft_itoa(getpid()), ft_strlen(ft_itoa(getpid())));
	write(1, "\n", 1);
	while (1)
    {
		pause();
		if (p_print.receive || p_print.overflow)
		{
			write(1, p_print.message, ft_strlen(p_print.message));
			ft_bzero(p_print.message, BUFFSIZE);
			p_print.byte = 0;
			p_print.bit = 1 << 6;
			if (p_print.receive)
				write(1,"\n", 1);	
			p_print.receive = FALSE;
			p_print.overflow = FALSE;
		}
	}
    return(0);
}