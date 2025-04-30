/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:00:50 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 15:18:16 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_writep(va_list *args, int *n_print, t_printf to_print)
{
	unsigned int	*p;
	int			n_space;

	p = va_arg(*args, unsigned int);
	n_space = to_print.field_width - ft_printf_sizep(p);
	if (!(to_print.flag_minus) && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
	if (p == 0)
	if (to_print.flag_minus && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
}
