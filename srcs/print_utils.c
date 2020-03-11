/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:48:22 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/11 21:59:31 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void print_char(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	printf("%c\n", c);
}

void print_int(va_list ap)
{
	int n;

	n = va_arg(ap, int);
	printf("%d\n", n);
}

void print_char_pointer(va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	printf("%s\n", s);
}

void print_unsigned_int(va_list ap)
{
	unsigned int ui;

	ui = va_arg(ap, unsigned int);
	printf("%u\n", ui);
}

void print_arg(va_list ap, char specifier)
{
	if (specifier == 'c')
		print_char(ap);
	else if (specifier == 's')
		print_char_pointer(ap);
	else if (specifier == 'p')
		print_char_pointer(ap);
	else if (specifier == 'd')
		print_int(ap);
	else if (specifier == 'i')
		print_int(ap);
	else if (specifier == 'u')
		print_unsigned_int(ap);
	else if (specifier == 'x')
		print_unsigned_int(ap);
	else if (specifier == 'X')
		print_unsigned_int(ap);
}
