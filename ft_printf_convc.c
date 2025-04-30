/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:37:04 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 15:18:03 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions to write the % for the given conversion specifier part 1*/

#include "ft_printf.h"

void	ft_printf_writec(va_list *args, int *n_print, t_printf to_print)
{
	unsigned char	s;
	int				n_space;

	s = (unsigned char) va_arg(*args, int);
	n_space = to_print.field_width - 1;
	if (!(to_print.flag_minus) && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
	ft_printf_putchar(s, n_print);
	if (to_print.flag_minus) && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
}


void	ft_printf_writed(va_list *args, int *n_print, t_printf to_print)
{
	char	s;

	s = va_arg(*args, int);
	write(1, &s, 1);
	s = *n_print + 48;
	write(1, &s, 1);
	s = to_print.flag_minus + 48;
	write(1, &s, 1);
	s = to_print.flag_0 + 48;
	write(1, &s, 1);
	s = to_print.flag_plus + 48;
	write(1, &s, 1);
	s = to_print.flag_blank + 48;
	write(1, &s, 1);
	s = to_print.flag_hash + 48;
	write(1, &s, 1);
	s = to_print.field_width + 48;
	write(1, &s, 1);
	s = to_print.precision + 48;
	write(1, &s, 1);
}

void	ft_printf_writei(va_list *args, int *n_print, t_printf to_print)
{
	char	s;

	s = va_arg(*args, int);
	write(1, &s, 1);
	s = *n_print + 48;
	write(1, &s, 1);
	s = to_print.flag_minus + 48;
	write(1, &s, 1);
	s = to_print.flag_0 + 48;
	write(1, &s, 1);
	s = to_print.flag_plus + 48;
	write(1, &s, 1);
	s = to_print.flag_blank + 48;
	write(1, &s, 1);
	s = to_print.flag_hash + 48;
	write(1, &s, 1);
	s = to_print.field_width + 48;
	write(1, &s, 1);
	s = to_print.precision + 48;
	write(1, &s, 1);
}
