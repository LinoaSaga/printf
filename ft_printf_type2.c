/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:01:21 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 12:50:09 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions related to the type t_printf part 2*/

#include "ft_printf.h"

/* Boolean function to indicate if the character is a conversion*/
/* specifier*/
char	ft_printf_isconv(const char **s)
{
	if (**s == 'c')
		return (1);
	else if (**s == 's')
		return (1);
	else if (**s == 'p')
		return (1);
	else if (**s == 'd')
		return (1);
	if (**s == 'i')
		return (1);
	else if (**s == 'u')
		return (1);
	else if (**s == 'x')
		return (1);
	else if (**s == 'X')
		return (1);
	return (0);
}

/* Function return the related function of the conversion spec*/
void	(*ft_printf_getconv(const char **s))(va_list *a, int *b, t_printf c)
{
	void	(*f)(va_list *, int *, t_printf);

	f = NULL;
	if (**s == 'c')
		f = &ft_printf_writec;
	else if (**s == 's')
		f = &ft_printf_writes;
	else if (**s == 'p')
		f = &ft_printf_writep;
	else if (**s == 'd')
		f = &ft_printf_writed;
	if (**s == 'i')
		f = &ft_printf_writei;
	else if (**s == 'u')
		f = &ft_printf_writeu;
	else if (**s == 'x')
		f = &ft_printf_writexl;
	else if (**s == 'X')
		f = &ft_printf_writexu;
	(*s)++;
	return (f);
}
