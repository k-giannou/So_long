/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:01:13 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/11 09:57:21 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		if (*((unsigned char const *)s + i) == (unsigned char const)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int    main(void)
{
    const char	tab[] = "bonjourno";
    const void	*s;

    s = ft_memchr(tab, 's', 9);
    printf("%s\n", (unsigned char *)s);
    return(0);
}*/
