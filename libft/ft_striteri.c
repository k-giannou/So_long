/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:23:20 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/13 10:44:06 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>

void	ft_add(unsigned int i, char *c)
{
	*c = *c + 1;
	i++;
}

int	main(void)
{
	char	s[] = "abcde";

	ft_striteri(s, ft_add);
	printf("%s\n", s);
	return (0);
}*/
