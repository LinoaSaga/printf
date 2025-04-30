/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:01:17 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 12:50:12 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions related to the type t_printf part 1*/

#include "ft_printf.h"

/* Function to initialize the t_printf*/
void	ft_printf_init(t_printf *to_print)
{
	to_print->flag_minus = 0;
	to_print->flag_0 = 0;
	to_print->flag_plus = 0;
	to_print->flag_blank = 0;
	to_print->flag_hash = 0;
	to_print->field_width = -1;
	to_print->precision = -1;
}

/* Function to determine if the character is an existing flag*/
char	ft_printf_isflag(const char **s)
{
	if (**s == '-')
		return (1);
	else if (**s == '0')
		return (1);
	else if (**s == '+')
		return (1);
	else if (**s == ' ')
		return (1);
	else if (**s == '#')
		return (1);
	return (0);
}

/* Function to change the flag and increment the read string*/
void	ft_printf_getflag(t_printf *to_print, const char **s)
{
	if (**s == '-')
		to_print->flag_minus = 1;
	else if (**s == '0')
		to_print->flag_0 = 1;
	else if (**s == '+')
		to_print->flag_plus = 1;
	else if (**s == ' ')
		to_print->flag_blank = 1;
	else if (**s == '#')
		to_print->flag_hash = 1;
	(*s)++;
}

/* Function to get the field width and increment the read string*/
void	ft_printf_getfield(t_printf *to_print, const char **s)
{
	to_print->field_width = *((*s)++) - 48;
	while (**s >= '0' && **s <= '9')
	{
		to_print->field_width = to_print->field_width * 10 + **s - 48;
		(*s)++;
	}
}

/* Function to get the precision and increment the read string*/
/* negative precision = precision omitted*/
void	ft_printf_getprecision(t_printf *to_print, const char **s)
{
	(*s)++;
	if (**s == '-')
	{
		(*s)++;
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	else
	{
		to_print->precision = 0;
		while (**s >= '0' && **s <= '9')
		{
			to_print->precision = to_print->precision * 10 + **s - 48;
			(*s)++;
		}
	}
}
