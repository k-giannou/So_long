/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:25:11 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/18 17:51:11 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_num(int num);
int		ft_sum(long n);
int		ft_formats(va_list args, const char str);
int		ft_printf(const char *str, ...);
int		ft_print_hex(unsigned int num, const char str);
void	ft_put_hex(unsigned int num, const char c, int *i);
int		ft_print_percent(void);
int		ft_print_p(unsigned long long p);
void	ft_put_p(unsigned long long p, int *i);
int		ft_print_un(unsigned int num);
char	*ft_u_itoa(unsigned int n);
void	ft_putnbr(long n, int *i);

#endif
