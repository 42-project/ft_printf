/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 18:14:36 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/12 19:19:09 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void init_arg(t_arg *arg)
{
	arg->arg_str = NULL;
	arg->arg_num = 0;
	arg->arg_length = 0;
	arg->flag[0] = 0;
	arg->flag[1] = 0;
	arg->flag[2] = 0;
	arg->width = 0;
	arg->precision = 0;
	arg->specifier = 0;
}

t_list *new_arg(const char *str, int start_idx, int idx)
{
	t_list *ret;
	t_arg *new;

	if ((new = (t_arg *)malloc(sizeof(t_arg))) == 0)
		return (0);
	init_arg(new);
	if ((new->arg_str = ft_substr(str, start_idx, idx - start_idx + 1)) == 0)
		return (0);
	ret = ft_lstnew(new);
	return (ret);
}

void free_arg(void *p)
{
	t_arg *arg;

	arg = (t_arg *)p;
	if (arg->arg_str)
		free(arg->arg_str);
	if (arg->arg_value)
		va_end(arg->arg_value);
	free(arg);
}

void print_struct(void *p)
{
	t_arg *arg;

	arg = (t_arg *)p;
	if (arg->arg_str)
		printf("arg_str : %s\n", arg->arg_str);
	printf("arg_num : %d\n", arg->arg_num);
	if (arg->arg_value)
	{
		printf("arg::::::");
		print_arg(arg, arg->arg_value, arg->specifier);
	}
	printf("arg_length : %u\n", arg->arg_length);
	printf("flag : ");
	for (int i = 0; arg->flag[i]; i++)
		printf("%c ", arg->flag[i]);
	printf("\n");
	printf("width : %d\n", arg->width);
	printf("precision : %d\n", arg->precision);
	printf("specifier : %c\n", arg->specifier);
	printf("\n");
}
