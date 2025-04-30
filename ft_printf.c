/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:33:20 by ljudd             #+#    #+#             */
/*   Updated: 2025/04/30 15:17:28 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* function to handle the % */
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
				ft_printf_putchar('%', &res);
				s++;
			}
			else
				ft_printf_core(&s, &args, &res);
		}
		else
			ft_printf_putchar(*(s++), &res);
	}
	va_end(args);
	return (res);
}

/*int	main(void)
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
}*/

/*int	main(void)
{
	printf("%1.8d\n", 456);
	printf("%4.3d\n", 456);
	printf("%5.1d\n", 456);
	printf("%3.3d\n", 456);
	printf("%8.6d\n", 456);
	printf("%-8.6d\n", 456);
	printf("%08d\n", 456);
	printf("%0d\n", 456);
}*/

/*int	main(void)
{
	printf("%d\n", (int)ft_strlen("ok"));
	printf("%3c\n", 'c');
	ft_printf("%3c\n", 'c');
	printf("%-5c\n", 'c');
	ft_printf("%-5c\n", 'c');
	printf("%c\n", 'c');
	ft_printf("%c\n", 'c');
}*/

/*int	main(void)
{
	printf("%s\n", "salut");
	ft_printf("%s\n", "salut");
	printf("%.2s\n", "salut");
	ft_printf("%.2s\n", "salut");
	printf("%.8s\n", "salut");
	ft_printf("%.8s\n", "salut");
	printf("%10.8s\n", "salut");
	ft_printf("%10.8s\n", "salut");
	printf("%10.2s\n", "salut");
	ft_printf("%10.2s\n", "salut");
	printf("%-10.2s\n", "salut");
	ft_printf("%-10.2s\n", "salut");
	printf("%-10.15s\n", "salut");
	ft_printf("%-10.15s\n", "salut");
	printf("%2.4s\n", "salut");
	ft_printf("%2.4s\n", "salut");
}*/

int	main(void)
{
	char	*s = NULL;
	
	printf("%p\n", s);
	printf("%-p\n", s);
	printf("%30p\n", s);
	printf("%-30p\n", s);
}
