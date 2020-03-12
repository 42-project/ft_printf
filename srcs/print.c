/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:06:17 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/12 19:49:02 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void print_arg(t_arg *arg, va_list ap, char specifier)
{
	if (specifier == 'c')
		print_char(arg, ap);
	else if (specifier == 's')
		print_string(arg, ap);
	else if (specifier == 'p')
		print_address(arg, ap);
	else if (specifier == 'd')
		print_int(arg, ap);
	else if (specifier == 'i')
		print_int(arg, ap);
	else if (specifier == 'u')
		print_unsigned_int(arg, ap);
	else if (specifier == 'x')
		print_hex(arg, ap, 0);
	else if (specifier == 'X')
		print_hex(arg, ap, 1);
}

void print(t_list *list)
{
	t_list *p;
	t_arg *arg;

	p = list;
	while (p)
	{
		arg = (t_arg *)p->content;
		if (arg->arg_num == 0)
			write(1, arg->arg_str, ft_strlen(arg->arg_str));
		else if (arg->specifier == '%')
			write(1, "%", 1);
		else
			print_arg(arg, arg->arg_value, arg->specifier);
		p = p->next;
	}
}
