/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:06 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/04 16:11:23 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = 0;
		str++;
		n--;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[15] = "hello world";
	int	i;

	i = 0;
	ft_bzero(str, 3);
	while (i < 11 )
	{
		printf("%c", str[i]);
		i++;
	}
	return (0);
}
*/
