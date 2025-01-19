/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:15:33 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/13 10:44:42 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendest;

	lendest = ft_strlen(dst);
	if (size <= lendest)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] != '\0' && (lendest + i) < size - 1)
	{
		dst[lendest + i] = src[i];
		i++;
	}
	dst[lendest + i] = '\0';
	return (ft_strlen(src) + lendest);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[4] = "bbbb";
	char	src[] = "AAAAAAAAA";

	printf("%zu %s", ft_strlcat(dest, src, 6), dest);
	return (0);
}*/
