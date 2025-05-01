/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:12:10 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 14:42:59 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

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
void	ft_printf_core(const char **s, va_list *args, int *n_print);
int		ft_printf(const char *s, ...);

/* ft_printf_utils.c*/
void	ft_printf_putchar(char c, int	*res);
void	ft_printf_putcharn(char c, int *res, int n);
void	ft_printf_putstrc(char *s, int *res);

/* ft_printf_type1.c*/
void	ft_printf_init(t_printf *to_print);
char	ft_printf_isflag(const char **s);
void	ft_printf_getflag(t_printf *to_print, const char **s);
void	ft_printf_getfield(t_printf *to_print, const char **s);
void	ft_printf_getprecision(t_printf *to_print, const char **s);

/* ft_printf_type2.c*/
char	ft_printf_isconv(const char **s);
void	(*ft_printf_getconv(const char **s))(va_list *a, int *b, t_printf c);

/* ft_printf_conv.c*/
void	ft_printf_writec(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writes(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writep(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writed(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writei(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writeu(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writexl(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writexu(va_list *args, int *n_print, t_printf to_print);
void	ft_printf_writepct(va_list *args, int *n_print, t_printf to_print);

#endif