/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:18:02 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/11 10:21:59 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	const char		*source;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	dst = (unsigned char *) dest;
	source = (const char *) src;
	i = 0;
	while (n > i)
	{
		dst[i] = source[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[30];
	char	src[30] = "zyxwvutsrqponmlkjihgfedcba";
	
	ft_memcpy(dest, src, 0);
	printf("ftmemcpy %s\n", dest);
	return (0);
}
*/
