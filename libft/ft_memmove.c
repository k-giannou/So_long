/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:16 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/10 16:00:42 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	if (dest == src || !n)
		return (dest);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			*((char *)dest + n - 1) = *((char *)src + n -1);
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};

	ft_memmove(s, s + 2, 2);
	printf("memove %s\n", s);
	return (0);
}
*/
/*#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *dest = malloc(30);
    char src[] = "Hello World";
    void *destv = dest;
    const void *srcv = src;

    printf("%s\n", (char *)ft_memmove(destv, srcv, 5));
    return(0);
}*/
