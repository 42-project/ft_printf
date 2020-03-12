/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:48:22 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/12 20:47:39 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int is_in_flag(char *flag, char c)
{
	int idx;

	idx = 0;
	while (flag[idx])
	{
		if (flag[idx] == c)
			return (1);
		++idx;
	}
	return (0);
}

void print_space(unsigned int width)
{
	unsigned int idx;

	idx = 0;
	while (idx < width)
	{
		write(1, " ", 1);
		++idx;
	}
}

void print_zero(unsigned int len)
{
	unsigned int idx;

	idx = 0;
	while (idx < len)
	{
		write(1, "0", 1);
		++idx;
	}
}

void print_unsigned(unsigned long ul, int base)
{
	char c;

	if (ul / base)
		print_unsigned(ul / base, base);
	c = ul % base;
	if (c >= 0 && c <= 9)
		c += '0';
	else
		c += 'a' - 10;
	write(1, &c, 1);
}

void print_char(t_arg *arg, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	if (arg->width > 1 && !is_in_flag(arg->flag, '-'))
		print_space(arg->width - 1);
	write(1, &c, 1);
	if (arg->width > 1 && is_in_flag(arg->flag, '-'))
		print_space(arg->width - 1);
}

void print_string(t_arg *arg, va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	if (arg->precision < arg->arg_length)
	{
		if (arg->width > arg->precision && !is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision);
		write(1, s, arg->precision);
		if (arg->width > arg->precision && is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision);
	}
	else
	{
		if (arg->width > arg->arg_length && !is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->arg_length);
		write(1, s, arg->arg_length);
		if (arg->width > arg->arg_length && is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->arg_length);
	}
}

void print_address(t_arg *arg, va_list ap)
{
	unsigned long ul;

	ul = va_arg(ap, unsigned long);
	if (arg->precision > arg->arg_length)
	{
		if (arg->width > arg->precision && !is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision - 2);
		write(1, "0x", 2);
		print_zero(arg->precision - arg->arg_length + 2);
		print_unsigned(ul, 16);
		if (arg->width > arg->precision && is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision - 2);
	}
	else
	{
		if (arg->width > arg->arg_length && !is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->arg_length);
		write(1, "0x", 2);
		print_unsigned(ul, 16);
		if (arg->width > arg->arg_length && is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->arg_length);
	}
}

void print_int(t_arg *arg, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	printf("%d\n", n);
}

void print_unsigned_int(t_arg *arg, va_list ap)
{
	unsigned int ui;

	ui = va_arg(ap, unsigned int);
	printf("%u\n", ui);
}

void print_hex(t_arg *arg, va_list ap, int upper)
{
	printf("%x\n", va_arg(ap, unsigned int));
}
