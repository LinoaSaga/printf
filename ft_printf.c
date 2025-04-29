/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:33:20 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/29 13:30:46 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/* function to write a char and increment the total written counter*/
void	ft_putcharf(char c, int	*res)
{
	write(1, &c, 1);
	(*res)++;
}

/* function to handle the conversion specifiers */
void	ft_printf_core(const char **s, va_list *args, int *n_print)
{
	t_printf	to_print;

	ft_printf_init(&to_print);
	while (ft_printf_isflag(s))
		ft_printf_getflag(&to_print, s);
	if (**s >= '1' && **s <= '9')
		ft_printf_getfield(&to_print, s);
	if (**s == '.')
		ft_printf_getprecision(&to_print, s);
	if (ft_printf_isconv(s))
		(*ft_printf_getconv(s))(args, n_print, to_print);
}

int	ft_printf(const char *s, ...)
{
	int		res;
	va_list	args;

	res = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (*(++s) == '%')
			{
				ft_putcharf('%', &res);
				s++;
			}
			else
				ft_printf_core(&s, &args, &res);
		}
		else
			ft_putcharf(*(s++), &res);
	}
	va_end(args);
	return (res);
}

int	main(void)
{
	ft_printf("test %% ok\n", "aa", 45);
	ft_printf("test %d ok\n", 'b');
	ft_printf("test %-d ok\n", 'b');
	ft_printf("test %0d ok\n", 'b');
	ft_printf("test %+d ok\n", 'b');
	ft_printf("test % d ok\n", 'b');
	ft_printf("test %#d ok\n", 'b');
	ft_printf("test %-0+--d ok\n", 'b');
	ft_printf("test %3d ok\n", 'b');
	ft_printf("test %.7d ok\n", 'b');
	ft_printf("test %.-7d ok\n", 'b');
	ft_printf("test %--#6.6d ok\n", 'b');
	ft_printf("test %z ok\n", 'b');
	ft_printf("test %--#6.6d ok %--#8.6d\n", 'b', 'c');
}
