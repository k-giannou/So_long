/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:02:48 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/11 16:06:48 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(const char *s, char c)
{
	int	sum;
	int	i;

	i = 0;
	sum = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			sum++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (sum);
}

int	ft_fill(char **dest, char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (*s)
	{
		len = 0;
		while (*s != c && *s && ++s)
			len++;
		dest[i] = malloc(len + 1);
		if (!dest[i])
		{
			while (i)
				free (dest[--i]);
			free (dest);
			return (1);
		}
		ft_strlcpy(dest[i++], s - len, len + 1);
		while (*s == c && *s)
			s++;
	}
	dest[i] = 0;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	while (*s == c && *s)
		s++;
	dest = (char **)malloc((ft_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	if (ft_fill(dest, s, c))
		return (NULL);
	return (dest);
}
/*
int	main(void)
{
	char	s[] = "--hello----how--are-you--";
	char	c;
	int	i;
	char	**dest;

	c = '-';
	dest = ft_split(s, c);
	i = 0;
	while (i < 5)
	{
		printf("%s\n", dest[i]);
		free(dest[i]);
		i++;
	}
	free(dest);
	return (0);
}*/
