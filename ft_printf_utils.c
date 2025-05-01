/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:14:21 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/01 08:36:04 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* function to write a char and increment the total written counter*/
void	ft_printf_putchar(char c, int	*res)
{
	write(1, &c, 1);
	(*res)++;
}

/* function to write n times a char and increment the total written counter*/
void	ft_printf_putcharn(char c, int *res, int n)
{
	while (n-- > 0)
		ft_printf_putchar(c, res);
}

/* putstr with the counter*/
void	ft_printf_putstrc(char *s, int *res)
{
	while (*s)
	{
		ft_printf_putchar(*s, res);
		s++;
	}
}
