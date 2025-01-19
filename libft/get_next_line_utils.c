/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:42:27 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/27 16:58:07 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
char	*ft_join(char *rest, char *cup_buffer)
{
	char	*new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!rest)
	{
		rest = malloc(1);
		rest[0] = '\0';
	}
	if (!rest || !cup_buffer)
		return (NULL);
	new = malloc(ft_strlen(rest) + ft_strlen(cup_buffer) + 1);
	if (!new)
		return (NULL);
	while (rest[i])
		new[k++] = rest[i++];
	i = 0;
	while (cup_buffer[i])
		new[k++] = cup_buffer[i++];
	new[k] = '\0';
	free(rest);
	return (new);
}

int	ft_check(char *cup_buffer, char c)
{
	int	i;

	i = 0;
	while (cup_buffer[i])
	{
		if (cup_buffer[i] == c)
			return (-1);
		i++;
	}
	return (1);
}
