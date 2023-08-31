/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:43:35 by r-afonso          #+#    #+#             */
/*   Updated: 2023/08/30 14:51:42 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (len);
	else
	{
		while (--size && *(src + index))
		{
			*(dst + index) = *(src + index);
			index++;
		}
		*(dst + index) = '\0';
	}
	return (len);
}

int	ft_atoi(const char *nptr)
{
	int signal;
	int sun;

	sun = 0;
	signal = 1;
	while ((*(nptr) >= 9 && *(nptr) <= 13) || *(nptr) == 32)
		nptr++;
	if (*(nptr) == '+' || *(nptr) == '-')
	{
		if (*(nptr) == '-')
			signal *= -1;
		nptr++;
		if (*(nptr) < 48 && *(nptr) > 57)
			return (0);
	}
	while (*(nptr) >= 48 && *(nptr) <= 57)
	{
		sun = (sun * 10) + *(nptr)-48;
		nptr++;
	}
	return (sun * signal);
}