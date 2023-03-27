/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <gmiyakaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:46:34 by gmiyakaw          #+#    #+#             */
/*   Updated: 2023/03/15 14:13:17 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
/*--------------------------- STRUCTS -------------------------------*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*----------------------- MALLOC FUNCTIONS --------------------------*/
void	*ft_calloc(size_t count, size_t size);
void	*x_calloc(size_t size);
void	ft_free_array(char **array);

/*----------------------- MEMORY FUNCTIONS --------------------------*/
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t n);
void	*ft_memset(void	*b, int c, size_t n);

/*-------------------- CONVERTION FUNCTIONS -------------------------*/
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
int		ft_tolower(int c);
char	*ft_str_tolower(char *str);
int		ft_toupper(int c);

/*------------------- IDENTIFYING FUNCTIONS -------------------------*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(char c);
int		ft_isprint(int c);
int		ft_is_nbr(char *str);

/*-------------------- WRITE/PRINT FUNCTIONS ------------------------*/
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

/*------------------- STRING HANDLING FUNCTIONS ---------------------*/
char	**ft_split(const char *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcat(char	*dst, const char	*src, size_t destsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_arrlen(char **str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*--------------------- LINKED LIST FUNCTIONS ----------------------*/
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*----------------------- PRINTF FUNCTIONS -------------------------*/
int		ft_printf(const char *input, ...);
size_t	ft_rputnbr(long long int n);
size_t	ft_rputstr(char *s);
size_t	ft_rputnbr_base(long long int n, int base, char *base_str);
size_t	ft_rputaddress(unsigned long long int n, char *base_str);
size_t	ft_rputchar(char c);

#endif
