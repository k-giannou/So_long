/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:26 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/06 15:14:31 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	while (src[sum] != '\0')
		sum++;
	if (!dst || !size)
		return (sum);
	while ((size - 1 > 0) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (sum);
}
/*
#include <stdio.h>

int	main(void)
{
	char	src[6] = "hello";
	char	dest[10];

	printf("%zu\n", ft_strlcpy(dest, src, 5));
	printf ("%s\n", dest);
	return (0);
}*/
