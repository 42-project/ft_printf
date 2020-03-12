/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:13:08 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/12 19:45:43 by jungeun          ###   ########.fr       */
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
	unsigned int arg_length;
	char flag[3];
	int width;
	int precision;
	char specifier;
} t_arg;

int ft_printf(const char *str, ...);
t_list *parsing(va_list ap, const char *str);

int is_sep(const char *str, int idx, int percent);
int is_flag(char *flag, char c);
unsigned int read_arg(va_list ap, t_arg *arg);
int valid_str(void *p);

unsigned int get_address_digit(unsigned long n);
unsigned int get_unsigned_digit(unsigned int n, unsigned int base);
unsigned int get_digit(int n);

t_list *new_arg(const char *str, int start_idx, int end_idx);
void free_arg(void *p);
void print_struct(void *p);

void print(t_list *list);
void print_arg(t_arg *arg, va_list ap, char specifier);

void print_char(t_arg *arg, va_list ap);
void print_string(t_arg *arg, va_list ap);
void print_address(t_arg *arg, va_list ap);
void print_int(t_arg *arg, va_list ap);
void print_unsigned_int(t_arg *arg, va_list ap);
void print_hex(t_arg *arg, va_list ap, int upper);

#endif
