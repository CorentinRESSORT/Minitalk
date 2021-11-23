#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "include/minitalk.h"
void my_handler(int signum)
{
    if (signum == SIGUSR1)
    {
        write(1, "1", 1);
    }
    if (signum == SIGUSR2)
    {
        write(1, "0", 1);
    }
}
int main(void)
{
    printf("%d \n",getpid());
    signal(SIGUSR1, my_handler);
    signal(SIGUSR2, my_handler);
    while (1)
    {
        pause();
        if (p_print.receive || p_print.overflow)
        {
            
        }
    }
    return(0);
}