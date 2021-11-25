/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cressort <cressort@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 12:26:03 by cressort          #+#    #+#             */
/*   Updated: 2021/11/25 14:49:52 by cressort         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
