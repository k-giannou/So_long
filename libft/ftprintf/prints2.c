/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:05:14 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/18 17:12:22 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_p(unsigned long long p)
{
	int	i;

	if (!p)
		return (ft_print_s("(nil)"));
	i = 2;
	write(1, "0x", 2);
	if (p == 0)
		i += ft_print_c('0');
	else
		ft_put_p(p, &i);
	return (i);
}

char	*ft_u_itoa(unsigned int n)
{
	char	*num;
	int		len;
	long	number;

	number = n;
	len = ft_sum(number);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (number != 0)
	{
		num[len - 1] = number % 10 + 48;
		number = number / 10;
		len --;
	}
	return (num);
}

int	ft_print_un(unsigned int num)
{
	int		i;
	char	*n;
	long	number;

	if (num == 0)
		return (ft_print_c(48));
	number = num;
	n = ft_u_itoa(number);
	i = ft_print_s(n);
	free (n);
	return (i);
}
