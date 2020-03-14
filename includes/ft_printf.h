/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:13:08 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/14 23:25:51 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
#define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
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

// ft_printf.c
int ft_printf(const char *str, ...);

// parsing.c
void make_list(t_list **list, const char *str);
int parsing_flags(t_arg *arg, char *str, int *arg_num);
int str_to_list(t_arg *arg);
int arg_to_list(va_list ap, t_arg *arg);
t_list *parsing(va_list ap, const char *str);

// argument.c
void init_arg(t_arg *arg);
t_list *new_arg(const char *str, int start_idx, int end_idx);
void free_arg(void *p);
void print_struct(void *p);

// parsing_util.c
int is_sep(const char *str, int idx, int percent);
int is_flag(char *flag, char c);
int is_precision_arg(char *str);
unsigned int read_arg(va_list ap, t_arg *arg);
int valid_str(void *p);

// digit.c
unsigned int get_address_digit(unsigned long n);
unsigned int get_unsigned_digit(unsigned int n, unsigned int base);
unsigned int get_digit(int n);

// print.c
void print(t_list *list);
void print_arg(t_arg *arg, va_list ap, char specifier);

// print_by_type.c
void print_char(t_arg *arg, va_list ap);
void print_string(t_arg *arg, va_list ap);
void print_address(t_arg *arg, va_list ap);
void print_int(t_arg *arg, va_list ap);
void print_unsigned(t_arg *arg, va_list ap, int base, int upper);

// print_util.c
int is_in_flag(char *flag, char c);
void print_zero(unsigned int len);
void print_number(unsigned long ul, int base, int upper);
void print_space(unsigned int width);
void front_space(t_arg *arg, int precision);
void back_space(t_arg *arg, int precision);

#endif
