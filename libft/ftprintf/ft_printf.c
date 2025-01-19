/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:37:01 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/18 18:13:59 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (str == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (str == 'p')
		len += ft_print_p(va_arg(args, unsigned long long));
	else if (str == 'd' || str == 'i')
		len += ft_print_num(va_arg(args, int));
	else if (str == 'u')
		len += ft_print_un(va_arg(args, unsigned int));
	else if (str == 'x' || str == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), str);
	else if (str == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;
	int		i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_c(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int	num;
	int	*p;
	int	a;

	num = 42;
	p = &num;
	ft_printf("%c %c %s %s\n", 'o', 'k', "okay", "");
	ft_printf("%p %p %d\n", &num, p, *p);
	printf("%p %p %d\n", &num, p, *p);
	ft_printf("numbers %d %d %d %i\n", 0, -42, 1234567890, -123456789);
	a = ft_printf("%x %X %x %X %x %X\n", 16, 17, 99, 123456789, 987654321, 879);
	printf("i = %d\n", a);
	printf("%s\n", "10, 11, 63, 75BCD15, 3ade68b1, 36F");
}*/
