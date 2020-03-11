/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 19:01:20 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/11 21:48:06 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int is_sep(const char *str, int idx, int percent)
{
	if (ft_strchr("cspdiuxX%", str[idx]) && percent)
		return (1);
	if ((str[idx + 1] == '%' || str[idx + 1] == 0) && str[idx] != '%')
		return (1);
	return (0);
}

int is_flag(char *flag, char c)
{
	int idx;

	idx = 0;
	while (flag[idx])
	{
		if (flag[idx] == c)
			return (0);
		if ((c == '-' && flag[idx] == '0') || (c == '0' && flag[idx] == '-'))
			return (0);
		++idx;
	}
	if (c == '-' || c == '0')
		return (1);
	return (0);
}

int read_arg(va_list ap, t_arg *arg)
{
	if (arg->specifier == 'c')
		va_arg(ap, int);
	else if (arg->specifier == 's')
		va_arg(ap, char *);
	else if (arg->specifier == 'p')
		va_arg(ap, char *);
	else if (arg->specifier == 'd')
		va_arg(ap, int);
	else if (arg->specifier == 'i')
		va_arg(ap, int);
	else if (arg->specifier == 'u')
		va_arg(ap, unsigned int);
	else if (arg->specifier == 'x')
		va_arg(ap, unsigned int);
	else if (arg->specifier == 'X')
		va_arg(ap, unsigned int);
	else
		return (-1);
	return (0);
}

int valid_str(void *p)
{
	t_arg *arg;
	int idx;
	int dot;
	int star;

	arg = (t_arg *)p;
	if (arg->arg_str[0] == '%')
	{
		idx = 0;
		dot = 0;
		star = 0;
		while (arg->arg_str[idx])
		{
			if (arg->arg_str[idx] == '.')
				dot++;
			else if (arg->arg_str[idx] == '*')
				star++;
			++idx;
		}
		if (dot > 1 || star > 2)
			return (-1);
	}
	return (0);
}
