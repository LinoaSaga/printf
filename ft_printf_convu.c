/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:39:15 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 11:32:40 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_sized(unsigned int nb, t_printf to_print)
{
	int	res;

	res = 1;
	while (nb > 9)
	{
		res++;
		nb /= 10;
	}
	if (res < to_print.precision)
		return (to_print.precision);
	return (res);
}

static void	ft_printf_put0d(unsigned int nb, int *n_print, t_printf to_print)
{
	int	n_zero;
	int	size;

	size = 1;
	while (nb > 9)
	{
		size++;
		nb /= 10;
	}
	n_zero = to_print.precision - size;
	if (n_zero > 0)
		ft_printf_putcharn('0', n_print, n_zero);
}

static void	ft_printf_putd(unsigned int nb, int *n_print, char *digits)
{
	if (nb > 9)
		ft_printf_putd(nb / 10, n_print, digits);
	ft_printf_putchar(digits[nb % 10], n_print);
}

void	ft_printf_writeu(va_list *args, int *n_print, t_printf to_print)
{
	unsigned int	nb;
	int				n_space;

	nb = va_arg(*args, unsigned int);
	n_space = to_print.field_width - ft_printf_sized(nb, to_print);
	if (!(to_print.flag_minus) && to_print.flag_0
		&& to_print.precision == -1 && n_space > 0)
		ft_printf_putcharn('0', n_print, n_space);
	else if (!(to_print.flag_minus) && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
	ft_printf_put0d(nb, n_print, to_print);
	ft_printf_putd(nb, n_print, "0123456789");
	if (to_print.flag_minus && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
}
