/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:06:40 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/11 21:46:14 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_list *list;

	va_start(ap, str);

	if ((list = parsing(ap, str)) == 0)
		return (0);
	// print(list);
	// va_copy();
	va_end(ap);
	ft_lstclear(&list, &free_arg);
}

#include <stdio.h>

int main()
{
	int n = 241;
	ft_printf("1%*.*s34%c%-5.*d5%%6\n", 5, 3, "haha", 'a', 2, 241);
	// printf("1%*.*s34%05d5%%6\n", 5, 3, "241", 241);
	// printf("1%*.3.1s34%-05d5%%6\n", 5, "241", 241);
	// printf("1%*s34%05d5%%6\n", 5, "241", 241);
	// printf("%d", -16.3);
}
