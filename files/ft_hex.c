/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:27:03 by francima          #+#    #+#             */
/*   Updated: 2024/07/23 22:44:16 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexlen(long n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

int	ft_puthex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_puthex(n / 16);
		len += ft_puthex(n % 16);
	}
	else
		len += write(1, &base[n], 1);
	return (len);
}
