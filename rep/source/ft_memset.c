/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cressort <cressort@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:01:39 by cressort          #+#    #+#             */
/*   Updated: 2021/11/25 15:40:00 by cressort         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	char		*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
