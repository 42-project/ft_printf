/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:13:08 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/11 21:56:48 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

#include <stdio.h>

typedef struct s_arg
{
	char *arg_str;
	int arg_num;
	va_list arg_value;
	char flag[3];
	int width;
	int precision;
	char specifier;
} t_arg;

int ft_printf(const char *str, ...);
t_list *parsing(va_list ap, const char *str);

int is_sep(const char *str, int idx, int percent);
int is_flag(char *flag, char c);
int read_arg(va_list ap, t_arg *arg);
int valid_str(void *p);

t_list *new_arg(const char *str, int start_idx, int end_idx);
void free_arg(void *p);
void print_list(void *p);

void print_arg(va_list ap, char specifier);

#endif
