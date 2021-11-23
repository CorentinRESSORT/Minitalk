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
        char    *message;
        int     bit;
        int     byte;
        _Bool    receive;
        _Bool    overflow;
}          t_stack;

t_stack p_print = {{0}, 1 << 6, 0, FALSE, FALSE};

#endif