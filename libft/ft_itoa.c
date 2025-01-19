/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiannou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:06:06 by kgiannou          #+#    #+#             */
/*   Updated: 2024/11/11 12:06:39 by kgiannou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft__sum(long n)
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
		sum++;
	}
	return (sum);
}

char	*ft_copy(long num, char *dest, int sum)
{
	while (num > 9)
	{
		dest[sum] = (num % 10) + 48;
		num = num / 10;
		sum--;
	}
	dest[sum] = num + 48;
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		sum;
	int		i;
	long	num;

	num = n;
	sum = ft__sum(num);
	dest = (char *)malloc(sum + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		dest[i++] = '-';
		num = num * (-1);
	}
	dest[sum] = '\0';
	sum--;
	dest = ft_copy(num, dest, sum);
	return (dest);
}
/*
int	main(void)
{
	char	*dest;

	dest = ft_itoa(-50123);
	printf("%s\n", dest);
	free (dest);
	return (0);
}*/
