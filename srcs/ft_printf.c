/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:06:40 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/09 19:31:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

int is_foramt(char c)
{
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	int idx;
	int start;

	idx = 0;
	start = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			start = 1;
		else if (start && ft_strchr("cspdiuxX", str[idx]))
		{
			printf("%d", va_arg(ap, int));
			start = 0;
		}
		else if (start && ft_strchr("-0.*", str[idx]))
		{
		}
		else if (!start)
			write(1, &str[idx], 1);
		else
			break;
		++idx;
	}
	// va_copy();
	va_end(ap);
}

#include <stdio.h>

int main()
{
	// ft_printf("sdad\n", 241, 241);
	printf("%*d\n", 241, 241);
}
