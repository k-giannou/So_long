/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:06:10 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/14 15:27:32 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	void	*dest;

	if (nmemb && size > ((size_t) - 1) / nmemb)
		return (NULL);
	i = nmemb * size;
	dest = (void *)malloc(i);
	if (!dest)
		return (0);
	ft_bzero(dest, i);
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*dest;

	dest = ft_calloc(5, 1);
	printf("%s\n", dest);
	free (dest);
	return (0);
}*/
