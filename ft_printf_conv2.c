/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:37:00 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 12:50:16 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Functions to write the % for the given conversion specifier part 2*/

#include "ft_printf.h"

void	ft_printf_writeu(va_list *args, int *n_print, t_printf to_print)
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

void	ft_printf_writexl(va_list *args, int *n_print, t_printf to_print)
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

void	ft_printf_writexu(va_list *args, int *n_print, t_printf to_print)
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
