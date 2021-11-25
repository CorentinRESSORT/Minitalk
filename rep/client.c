#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/minitalk.h"

void error(char *str)
{
    printf("%s", str);
    exit(1);
}

int ft_atoi(char *str)
{
    int i;
    int ret;

    i = 0;
    ret = 0;
    if (str[i] == '-')
    {
        return (-1);
    }

    while (str[i])    
    {
        if (str[i] > 47 && str[i] < 58)
        {
            ret = ret * 10 + (str[i] - 48);
        }
        else
        {
            return (-1);
        }
        i++;
    }
    return (ret);
}

void send_char(int pid, unsigned char byte)
{
    __uint8_t count;

    count = 1 << 6;
    while (count)
    {
        if (byte & count)
        {
            if (kill(pid, SIGUSR1) < 0)
            {
                error("wrong pid\n");
            }
        }
        else
        {
            if (kill(pid, SIGUSR2) < 0)
            {
                error("wrong pid\n");
            }
        }
        count >>= 1;
        usleep(600);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf(" Syntaxe client ./client [PID] [String]");
        return (1);
    }
    while (*argv[2])
    {
        send_char(ft_atoi(argv[1]), *argv[2]);
        argv[2]++;
    }
    send_char(ft_atoi(argv[1]), 0);
    printf("%d", 1 << 6);
    return (0);
}