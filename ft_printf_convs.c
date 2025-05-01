/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:03:16 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 12:09:41 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_writes_sub(char *s, int *n_print, t_printf to_print)
{
	int	n_space;
	int	k;

	if (to_print.precision != -1 && (int) ft_strlen(s) > to_print.precision)
		n_space = to_print.field_width - to_print.precision;
	else
		n_space = to_print.field_width - ft_strlen(s);
	if (!(to_print.flag_minus))
		ft_printf_putcharn(' ', n_print, n_space);
	k = 0;
	while (s[k] && (to_print.precision == -1 || k < to_print.precision))
	{
		ft_printf_putchar(s[k], n_print);
		k++;
	}
	if (to_print.flag_minus)
		ft_printf_putcharn(' ', n_print, n_space);
}

void	ft_printf_writes(va_list *args, int *n_print, t_printf to_print)
{
	char	*s;

	s = va_arg(*args, char *);
	if (!s)
	{
		to_print.precision = -1;
		ft_printf_putstrc("(null)", n_print);
	}
	else
		ft_printf_writes_sub(s, n_print, to_print);
}
