/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:37:47 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/18 17:32:27 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_print_s("(null)"));
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	return (i);
}

int	ft_print_num(int num)
{
	long	number;
	int		i;

	i = 0;
	number = num;
	ft_putnbr(number, &i);
	return (i);
}

int	ft_print_hex(unsigned int num, const char str)
{
	int	i;

	i = 0;
	if (num == 0)
		return (ft_print_c(0 + 48));
	ft_put_hex(num, str, &i);
	return (i);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
