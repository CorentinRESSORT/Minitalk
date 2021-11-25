#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MINITALK_H
# define MINITALK_H
# define BUFFSIZE 1024

# ifndef TRUE
#   define TRUE 1
# endif

# ifndef FALSE
#   define FALSE 0
#endif

typedef     struct s_stack 
{
        char    message[BUFFSIZE];
        int     bit;
        int     byte;
        _Bool    receive;
        _Bool    overflow;
}          t_stack;



void	zerobit(int sig, siginfo_t *info, void *context);
void	onebit(int sig, siginfo_t *info, void *context);
void my_handler(int signum);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_itoa(int n);
void	*ft_memset(void *s, int c, size_t n);

#endif