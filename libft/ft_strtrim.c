/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:19:03 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/11 18:21:26 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		len;
	int		k;

	if (!s1 || !set)
		return (NULL);
	while (ft_check(*s1, set) == 1 && *s1)
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_check(s1[len - 1], set) == 1)
		len--;
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	k = 0;
	while (len > 0)
	{
		dest[k] = *s1;
		k++;
		len--;
		s1++;
	}
	dest[k] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "lorem ipsum dolor sit amet";
	char	set[] = "te";
	char	*dest;

	dest = ft_strtrim(s1, set);
	printf("%s\n", dest);
	free (dest);
	return (0);
}*/
