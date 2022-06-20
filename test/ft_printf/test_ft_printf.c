/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:02:24 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 09:29:15 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"
#include <stdio.h>

// ft_printf

int	main(void)
{
	char	*word;
	int		test_value;
	int		returned;

	word = "matheus";
	test_value = 42;

	// c
	printf("Original printf - ");
	returned = printf("%c\n", *word);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%c\n", *word);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// s
	printf("Original printf - ");
	returned = printf("%s\n", word);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%s\n", word);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// d
	printf("Original printf - ");
	returned = printf("%d\n", test_value);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%d\n", test_value);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// i
	printf("Original printf - ");
	returned = printf("%i\n", test_value);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%i\n", test_value);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// u
	printf("Original printf - ");
	returned = printf("%u\n", test_value);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%u\n", test_value);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// x
	printf("Original printf - ");
	returned = printf("%x\n", test_value);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%x\n", test_value);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// X
	printf("Original printf - ");
	returned = printf("%X\n", test_value);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%X\n", test_value);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// p
	printf("Original printf - ");
	returned = printf("%p\n", word);
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%p\n", word);
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// %
	printf("Original printf - ");
	returned = printf("%%\n");
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("%%\n");
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);

	// oridnary
	printf("Original printf - ");
	returned = printf("matheus\n");
	printf("Returned original printf - %d\n", returned);
	ft_putstr_fd("ft_printf - ", STDOUT);
	returned = ft_printf("matheus\n");
	printf("ft_printf return - %d\n", returned);
	ft_putstr_fd("---\n", STDOUT);
}
