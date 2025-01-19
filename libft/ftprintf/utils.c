/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:45:42 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/18 17:53:46 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sum(long n)
{
	int	sum;

	sum = 1;
	if (n < 0)
	{
		sum = 2;
		n = n * (-1);
	}
	while (n / 10 != 0)
	{
		n = n / 10;
		sum ++;
	}
	return (sum);
}

void	ft_put_hex(unsigned int num, const char c, int *i)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, c, i);
		ft_put_hex(num % 16, c, i);
	}
	else
	{
		if (num <= 9)
			*i += ft_print_c(num + 48);
		else if (c == 'x')
			*i += ft_print_c(num - 10 + 'a');
		else if (c == 'X')
			*i += ft_print_c(num - 10 + 'A');
	}
}

void	ft_put_p(unsigned long long p, int *i)
{
	if (p >= 16)
	{
		ft_put_p(p / 16, i);
		ft_put_p(p % 16, i);
	}
	else
	{
		if (p <= 9)
			*i += ft_print_c(p + '0');
		else
			*i += ft_print_c(p - 10 + 'a');
	}
}

void	ft_putnbr(long n, int *i)
{
	if (n < 0)
	{
		*i += ft_print_c('-');
		n = n * (-1);
		ft_putnbr(n, i);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10, i);
		ft_putnbr(n % 10, i);
	}
	else
		*i += ft_print_c(n + 48);
}
