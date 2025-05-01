/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 08:39:02 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 12:52:10 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_sized(int d, t_printf to_print)
{
	int				res;
	int				sign;
	unsigned int	nb;

	if (d == 0 && to_print.precision == 0)
		return (0);
	res = 1;
	sign = 0;
	if (d < 0 || to_print.flag_plus || to_print.flag_blank)
		sign++;
	nb = d;
	if (d < 0)
		nb = -((unsigned int) d);
	while (nb > 9)
	{
		res++;
		nb /= 10;
	}
	if (res < to_print.precision)
		return (to_print.precision + sign);
	return (res + sign);
}

static void	ft_printf_putsignd(int d, int *n_print, t_printf to_print)
{
	if (d < 0)
		ft_printf_putchar('-', n_print);
	else if (to_print.flag_plus)
		ft_printf_putchar('+', n_print);
	else if (to_print.flag_blank)
		ft_printf_putchar(' ', n_print);
}

static void	ft_printf_put0d(int d, int *n_print, t_printf to_print)
{
	int				n_zero;
	int				size;
	unsigned int	nb;

	size = 1;
	nb = d;
	if (d < 0)
		nb = -((unsigned int) d);
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

void	ft_printf_writed(va_list *args, int *n_print, t_printf to_print)
{
	int				d;
	unsigned int	nb;
	int				n_space;

	d = va_arg(*args, int);
	n_space = to_print.field_width - ft_printf_sized(d, to_print);
	if (!(to_print.flag_minus)
		&& (!to_print.flag_0 || to_print.precision != -1) && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
	ft_printf_putsignd(d, n_print, to_print);
	if (!(to_print.flag_minus) && to_print.flag_0
		&& to_print.precision == -1 && n_space > 0)
		ft_printf_putcharn('0', n_print, n_space);
	nb = d;
	if (d < 0)
		nb = -((unsigned int) d);
	ft_printf_put0d(nb, n_print, to_print);
	if (nb != 0 || to_print.precision != 0)
		ft_printf_putd(nb, n_print, "0123456789");
	if (to_print.flag_minus && n_space > 0)
		ft_printf_putcharn(' ', n_print, n_space);
}
