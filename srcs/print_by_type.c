/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 00:28:38 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/14 23:09:01 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	if (arg->precision > 0 && (unsigned int)arg->precision < arg->arg_length)
	{
		front_space(arg, 1);
		write(1, s, arg->precision);
		back_space(arg, 1);
	}
	else
	{
		front_space(arg, 0);
		write(1, s, arg->arg_length);
		back_space(arg, 0);
	}
}

void print_address(t_arg *arg, va_list ap)
{
	unsigned long ul;

	ul = va_arg(ap, unsigned long);
	front_space(arg, 0);
	write(1, "0x", 2);
	print_number(ul, 16, 0);
	back_space(arg, 0);
}

void print_int(t_arg *arg, va_list ap)
{
	int n;

	n = va_arg(ap, int);
	if ((unsigned int)arg->precision > arg->arg_length)
	{
		front_space(arg, 1);
		if (n < 0)
		{
			write(1, "-", 1);
			print_zero(arg->precision - arg->arg_length + 1);
		}
		else
			print_zero(arg->precision - arg->arg_length);
		if (n < 0)
			print_number((unsigned long)(n * (-1)), 10, 0);
		else
			print_number(n, 10, 0);
		back_space(arg, 1);
	}
	else
	{
		front_space(arg, 0);
		if (n < 0)
			write(1, "-", 1);
		if ((unsigned int)arg->width > arg->arg_length)
			print_zero(arg->width - arg->arg_length);
		if (n < 0)
			print_number((unsigned long)(n * (-1)), 10, 0);
		else
			print_number(n, 10, 0);
		back_space(arg, 0);
	}
}

void print_unsigned(t_arg *arg, va_list ap, int base, int upper)
{
	unsigned int ui;

	ui = va_arg(ap, unsigned int);
	front_space(arg, 0);
	if ((unsigned int)arg->precision > arg->arg_length)
		print_zero(arg->precision - arg->arg_length);
	else if ((unsigned int)arg->width > arg->arg_length)
		print_zero(arg->width - arg->arg_length);
	print_number(ui, base, upper);
	back_space(arg, 0);
}
