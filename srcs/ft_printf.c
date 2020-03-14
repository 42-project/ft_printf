/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:06:40 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/14 23:31:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_list *list;

	va_start(ap, str);
	if ((list = parsing(ap, str)) == 0)
		return (-1);
	print(list);
	va_end(ap);
	ft_lstclear(&list, &free_arg);
	return (0);
}

// int main()
// {
// char *s = "1234";
// int n = 42;
// ft_printf("1%*.*s34%-3c%-5.*d5%%6\n", 5, 23, "haha", 'a', 2, 241);
// printf("1%*.*s34%-3c%-5.*d5%%6\n", 5, 23, "haha", 'a', 2, 241);

// ft_printf("1%-*.3s34%05d5%%6\n", 3, "241", 241);
// printf("1%-*.3s34%05d5%%6\n", 3, "241", 241);

// ft_printf("%s\n", s);
// ft_printf("%-5.*d\n", 20, 21);
// printf("%-5.*d\n", 20, 21);
// ft_printf("1%*s34%05d5%%6\n", 5, "241", 241);
// printf("1%*s34%05d5%%6\n", 5, "241", 241);

// ft_printf("%16.1x\n", n);
// printf("%16.1x\n", n);
// }
