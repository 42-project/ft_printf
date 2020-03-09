/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 19:46:36 by jungeun           #+#    #+#             */
/*   Updated: 2020/03/03 19:00:00 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>

// part1

void *ft_memset(void *dest, int value, size_t size);
void ft_bzero(void *dest, size_t n);
void *ft_memcpy(void *dest, const void *src, size_t len);
void *ft_memccpy(void *dest, const void *src, int c, size_t len);
void *ft_memmove(void *dest, const void *src, size_t len);
void *ft_memchr(const void *b, int c, size_t len);
int ft_memcmp(const void *str1, const void *str2, size_t len);

size_t ft_strlen(const char *s);
size_t ft_strlcpy(char *dest, char *src, size_t dest_size);
size_t ft_strlcat(char *dest, const char *src, size_t dest_size);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_strncmp(const char *s1, const char *s2, size_t len);
int ft_atoi(const char *str);

int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

void *ft_calloc(size_t number, size_t size);
char *ft_strdup(const char *str);
char *ft_strtrim(char const *s1, char const *set);

// part2
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(char const *s1, char const *set);
char **ft_split(char const *s, char c);
char *ft_itoa(int n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
void ft_putnbr_fd(int n, int fd);

// bonus
typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

t_list *ft_lstnew(void *content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
void ft_lstiter(t_list *lst, void (*f)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
