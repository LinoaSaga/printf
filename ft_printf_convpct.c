/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convpct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:16:52 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 14:27:28 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_writepct(va_list *args, int *n_print, t_printf to_print)
{
	ft_printf_putchar('%', n_print);
	(void) to_print;
	(void) args;
}
