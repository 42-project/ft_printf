/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 21:48:22 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/14 22:50:09 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void print_number(unsigned long ul, int base, int upper)
{
	char c;

	if (ul / base)
		print_number(ul / base, base, upper);
	c = ul % base;
	if (c >= 0 && c <= 9)
		c += '0';
	else
	{
		if (upper)
			c += 'A' - 10;
		else
			c += 'a' - 10;
	}
	write(1, &c, 1);
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

void front_space(t_arg *arg, int precision)
{
	if (precision)
	{
		if (arg->width > arg->precision && !is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision);
	}
	else
	{
		if ((unsigned int)arg->width > arg->arg_length)
			if (!is_in_flag(arg->flag, '-') && !is_in_flag(arg->flag, '0'))
				print_space(arg->width - arg->arg_length);
	}
}

void back_space(t_arg *arg, int precision)
{
	if (precision)
	{
		if (arg->width > arg->precision && is_in_flag(arg->flag, '-'))
			print_space(arg->width - arg->precision);
	}
	else
	{
		if ((unsigned int)arg->width > arg->arg_length)
			if (is_in_flag(arg->flag, '-'))
				print_space(arg->width - arg->arg_length);
	}
}
