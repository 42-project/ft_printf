/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:50:11 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/12 18:43:25 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int get_address_digit(unsigned long n)
{
	unsigned int digit;

	digit = 1;
	while (n / 16)
	{
		n /= 16;
		++digit;
	}
	return (digit + 2);
}

unsigned int get_unsigned_digit(unsigned int n, unsigned int base)
{
	unsigned int digit;

	digit = 1;
	while (n / base)
	{
		n /= base;
		++digit;
	}
	return (digit);
}

unsigned int get_digit(int n)
{
	if (n < 0)
		return (get_unsigned_digit((unsigned int)(n * (-1)), 10) + 1);
	else
		return (get_unsigned_digit((unsigned int)n, 10));
}
