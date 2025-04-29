/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:12:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/29 13:19:34 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_printf
{
	char	flag_minus;
	char	flag_0;
	char	flag_plus;
	char	flag_blank;
	char	flag_hash;
	int		field_width;
	int		precision;	
}	t_printf;

/* printf.c*/
int		ft_printf(const char *s, ...);
void	ft_printf_core(const char **s, va_list *args, int *n_print);
void	ft_putcharf(char c, int	*res);

/* ft_printf_type1.c*/
void	ft_printf_init(t_printf *to_print);
char	ft_printf_isflag(const char **s);
void	ft_printf_getflag(t_printf *to_print, const char **s);
void	ft_printf_getfield(t_printf *to_print, const char **s);
void	ft_printf_getprecision(t_printf *to_print, const char **s);

/* ft_printf_type2.c*/
char	ft_printf_isconv(const char **s);
void	(*ft_printf_getconv(const char **s))(va_list *a, int *b, t_printf c);

/* ft_printf_conv1.c*/
void	ft_printf_writed(va_list *args, int *n_print, t_printf to_print);

#endif