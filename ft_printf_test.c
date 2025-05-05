/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljudd <ljudd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:36:27 by ljudd             #+#    #+#             */
/*   Updated: 2025/05/05 11:52:09 by ljudd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	a1;
	int	a2;

	a1 = ft_printf(NULL);
	a2 = printf(NULL);
	printf("%d=%d\n", a1, a2);
	a1 = ft_printf("%c, %s, %p, %d \n", 'a', "test", NULL, 0);
	a2 = printf("%c, %s, %p, %d \n", 'a', "test", NULL, 0);
	printf("%d=%d\n", a1, a2);
}

/* int	main(void)
{
	int	a1;
	int	a2;

	a1 = ft_printf("%i, %u, %x, %X \n", INT_MIN, 56, 16, 33);
	a2 = printf("%i, %u, %x, %X \n", INT_MIN, 56, 16, 33);
	printf("%d=%d\n", a1, a2);
} */


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
	printf("%2.4s\n", (char *) NULL);
	ft_printf("%2.4s\n", (char *) NULL);
}*/

/*int	main(void)
{
	char	*s = "test";
	
	printf("%p\n", s);
	ft_printf("%p\n", s);
	printf("%-p\n", s);
	ft_printf("%-p\n", s);
	printf("%30p\n", s);
	ft_printf("%30p\n", s);
	printf("%-30p\n", s);
	ft_printf("%-30p\n", s);
}*/

/*int	main(void)
{
	printf("%d\n", 5);
	ft_printf("%d\n", 5);
	printf("%-+12.6d\n", 534);
	ft_printf("%-+12.6d\n", 534);
	printf("%-+12.6d\n", 534186123);
	ft_printf("%-+12.6d\n", 534186123);
	printf("%-+12.6d\n", 0);
	ft_printf("%-+12.6d\n", 0);
	printf("%d\n", INT_MIN);
	ft_printf("%d\n", INT_MIN);
}*/

/*int	main(void)
{
	printf("%-10d\n", INT_MIN);
	ft_printf("%-10d\n", INT_MIN);
	printf("%-1u\n", 0);
	ft_printf("%-1u\n", 0);
	printf("%04d\n", -14);
	ft_printf("%04d\n", -14);
	printf("%05d\n", -15);
	ft_printf("%05d\n", -15);
	printf("%06d\n", -16);
	ft_printf("%06d\n", -16);
	printf("%010d\n", INT_MIN);
	ft_printf("%010d\n", INT_MIN);
}*/

/*int	main(void)
{
	ft_printf("%5.8%\n");
	printf("%5.8%\n");
	ft_printf("%5.8%  \n");
	printf("%5.8%  \n");
	ft_printf("%-5%\n");
	printf("%-5%\n");
	ft_printf("%-05%\n");
	printf("%-05%\n");
	ft_printf("%.s\n", (char *) NULL);
	printf("%.s\n", (char *) NULL);
	ft_printf("%.03s\n", (char *) NULL);
	printf("%.03s\n", (char *) NULL);
	ft_printf("%3.s\n", (char *) NULL);
	printf("%3.s\n", (char *) NULL);
	ft_printf("%10.s\n", (char *) NULL);
	printf("%10.s\n", (char *) NULL);
	ft_printf("%-3.s\n", (char *) NULL);
	printf("%-3.s\n", (char *) NULL);
	ft_printf("%-8.s\n", (char *) NULL);
	printf("%-8.s\n", (char *) NULL);
	ft_printf("%3.1s\n", (char *) NULL);
	printf("%3.1s\n", (char *) NULL);
	ft_printf("%9.1s\n", (char *) NULL);
	printf("%9.1s\n", (char *) NULL);
	ft_printf("%-3.1s\n", (char *) NULL);
	printf("%-3.1s\n", (char *) NULL);
	ft_printf("%-9.1s\n", (char *) NULL);
	printf("%-9.1s\n", (char *) NULL);
	ft_printf("%08.5i\n", 34);
	printf("%08.5i\n", 34);
	ft_printf("%010.5i\n", -216);
	printf("%010.5i\n", -216);
	ft_printf("%08.5i\n", 0);
	printf("%08.5i\n", 0);
	ft_printf("%08.3i\n", 8375);
	printf("%08.3i\n", 8375);
	ft_printf("%08.3i\n", -8473);
	printf("%08.3i\n", -8473);
	ft_printf("%.0i\n", 0);
	printf("%.0i\n", 0);
	ft_printf("%.i\n", 0);
	printf("%.i\n", 0);
	ft_printf("%.0u\n", 0);
	printf("%.0u\n", 0);
	ft_printf("%.u\n", 0);
	printf("%.u\n", 0);
	ft_printf("%10.u\n", 0);
	printf("%10.u\n", 0);
}*/

/*int	main(void)
{
	printf("%04d\n", 9);
	ft_printf("%04d\n", 9);
}*/

/* int	main(void)
{
	printf("%d\n", printf(0));
	printf("%d\n", ft_printf(0));
	printf("%d\n", printf("%-+12.6d\n", 534186123));
	printf("%d\n", ft_printf("%-+12.6d\n", 534186123));
} */
