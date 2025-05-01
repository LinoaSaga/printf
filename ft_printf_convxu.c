/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convxu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:39:35 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 12:38:37 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_sized(unsigned int nb, t_printf to_print)
{
	int	res;

	if (nb == 0 && to_print.precision == 0)
		return (0);
	res = 1;
	if (to_print.flag_hash && nb != 0)
		res += 2;
	while (nb > 15)
	{
		res++;
		nb /= 16;
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
	while (nb > 15)
	{
		size++;
		nb /= 16;
	}
	n_zero = to_print.precision - size;
	if (n_zero > 0)
		ft_printf_putcharn('0', n_print, n_zero);
}

static void	ft_printf_putd(unsigned int nb, int *n_print, char *digits)
{
	if (nb > 15)
		ft_printf_putd(nb / 16, n_print, digits);
	ft_printf_putchar(digits[nb % 16], n_print);
}

void	ft_printf_writexu(va_list *args, int *n_print, t_printf to_print)
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
	if (to_print.flag_hash && nb != 0)
		ft_printf_putstrc("0X", n_print);
	ft_printf_put0d(nb, n_print, to_print);
	if (nb != 0 || to_print.precision != 0)
		ft_printf_putd(nb, n_print, "0123456789ABCDEF");
	if (to_print.flag_minus && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
}
