/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:16:26 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/14 15:03:11 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;

	if (!*sub)
		return ((char *)str);
	while (len && *str)
	{
		i = 0;
		while (str[i] == sub[i] && str[i] && len - i)
		{
			if (!sub[i + 1])
				return ((char *)str);
			i++;
		}
		str++;
		len--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	str[30] = "aaabcabcd";
	char	sub[10] = "abcd";

	printf("%s\n", ft_strnstr(str, sub, 9));
	return (0);
}*/
