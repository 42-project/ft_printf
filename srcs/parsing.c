/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:29:19 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/14 23:24:48 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void make_list(t_list **list, const char *str)
{
	t_list *new_list;
	int start_idx;
	int idx;
	int percent;

	start_idx = 0;
	idx = 0;
	percent = 0;
	while (str[idx])
	{
		if (is_sep(str, idx, percent))
		{
			if ((new_list = new_arg(str, start_idx, idx)) == 0)
			{
				ft_lstclear(list, &free_arg);
				return;
			}
			ft_lstadd_back(list, new_list);
			start_idx = idx + 1;
			percent = 0;
		}
		percent = str[idx] == '%' && !percent ? 1 : percent;
		++idx;
	}
}

int parsing_flags(t_arg *arg, char *str, int *arg_num)
{
	int idx;
	int flag_idx;

	idx = 0;
	flag_idx = 0;
	while (str[idx] && !ft_strchr("cspdiuxX%", str[idx]))
	{
		if (str[idx] == '*')
			*arg_num = *arg_num + 1;
		else if (is_flag(arg->flag, str[idx]))
			arg->flag[flag_idx++] = str[idx];
		else if (str[idx] == '.')
		{
			arg->precision = ft_atoi(&str[idx + 1]);
			if (str[idx + 1] == '*')
				*arg_num = *arg_num + 1;
			idx += get_digit(arg->precision) + 1;
			continue;
		}
		else if (str[idx] >= '1' && str[idx] <= '9')
		{
			arg->width = ft_atoi(&str[idx]);
			idx += get_digit(arg->width);
			continue;
		}
		++idx;
	}
	return (idx);
}

int str_to_list(t_arg *arg)
{
	char *str;
	int idx;
	int arg_num;

	str = arg->arg_str;
	if (str[0] != '%')
		return (0);
	arg_num = 0;
	idx = parsing_flags(arg, &arg->arg_str[1], &arg_num) + 1;
	if (str[idx] && ft_strchr("cspdiuxX%", str[idx]))
	{
		arg->specifier = str[idx];
		arg->arg_num = arg_num + 1;
		return (0);
	}
	return (-1);
}

int arg_to_list(va_list ap, t_arg *arg)
{
	if (arg->arg_num == 0 || arg->specifier == '%')
		return (0);
	if (arg->arg_num == 3)
	{
		if ((arg->width = va_arg(ap, int)) < 0)
			arg->width = 0;
		if ((arg->precision = va_arg(ap, int)) < 0)
			arg->precision = 0;
	}
	else if (arg->arg_num == 2)
	{
		if (is_precision_arg(arg->arg_str))
		{
			if ((arg->precision = va_arg(ap, int)) < 0)
				arg->precision = 0;
		}
		else if ((arg->width = va_arg(ap, int)) < 0)
		{
			arg->width = 0;
		}
	}
	va_copy(arg->arg_value, ap);
	if ((arg->arg_length = read_arg(ap, arg)) == 0)
		return (-1);
	return (0);
}

t_list *parsing(va_list ap, const char *str)
{
	t_list *list;
	t_list *p;

	list = NULL;
	make_list(&list, str);
	if (list == 0)
		return (0);
	p = list;
	while (p)
	{
		if (valid_str(p->content) != 0 || str_to_list(p->content) != 0 || arg_to_list(ap, p->content) != 0)
		{
			ft_lstclear(&list, &free_arg);
			return (0);
		}
		p = p->next;
	}
	return (list);
}
