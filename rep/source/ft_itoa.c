/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cressort <cressort@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 15:38:53 by cressort          #+#    #+#             */
/*   Updated: 2021/11/25 14:50:12 by cressort         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static	int	count_nb(long n)
{
	int	i;

	if (n >= 10)
		i = 1;
	else
		return (1);
	return (i + count_nb(n / 10));
}

static	void	do_itoa(char *str, int nbn, long nb, int pos)
{
	while (nbn)
	{
		str[--nbn] = (nb % 10) + 48;
		nb /= 10;
		if (nbn == 0 && pos < 0)
			str[nbn] = 45;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbn;
	int		pos;
	long	nb;

	nb = (long)n;
	pos = 0;
	nbn = 0;
	if (nb < 0)
	{
		nbn++;
		pos--;
		nb = -nb;
	}
	nbn += count_nb(nb);
	str = malloc(sizeof(char) * (nbn + 1));
	if (str == 0)
		return (NULL);
	str[nbn] = '\0';
	do_itoa(str, nbn, nb, pos);
	return (str);
}
