/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amonem <amonem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:14:50 by amonem            #+#    #+#             */
/*   Updated: 2023/09/25 19:55:32 by amonem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	digitsizechecker(int n)
{
	int	dchecker;

	dchecker = 0;
	if (n <= 0)
		dchecker++;
	while (n != 0)
	{
		n = n / 10;
		dchecker++;
	}
	return (dchecker);
}

char	*ft_itoa(int n)
{
	int		dchec;
	char	*str;
	long	nb;
	int		t;

	nb = n;
	dchec = digitsizechecker(n);
	t = dchec;
	str = (char *)malloc(sizeof(char) * (dchec + 1));
	if (str == NULL)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * (-1);
	}
	if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[--dchec] = (nb % 10) + 48;
		nb = nb / 10;
	}
	str[t] = '\0';
	return (str);
}
