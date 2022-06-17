/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:37:02 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/16 21:01:56 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

// ft_print_str

int	main(void)
{
	// Ordinary tests
	printf("Teste #01\n\n");
	printf("Original printf - %d\n", printf("%s", "Matheus\n"));
	printf("My function - %d\n", ft_print_str("Matheus\n"));
	printf("---\n");

	printf("Teste #02\n\n");
	printf("Original printf - %d\n", printf("%s", " "));
	printf("My function - %d\n", ft_print_str(" "));
	printf("---\n");

	printf("Teste #03\n\n");
	printf("Original printf - %d\n", printf("%s", "42"));
	printf("My function - %d\n", ft_print_str("42"));
	printf("---\n");

	printf("Teste #04\n\n");
	printf("Original printf - %d\n", printf("%s", NULL));
	printf("My function - %d\n", ft_print_str(NULL));
	printf("---\n");
	// Unsafe tests - cannot be compilled with flags	// printf("Original printf - %d\n", printf(""));
	// printf("My function - %d\n", ft_print_str(""));
	// printf("---\n");
	// // Seg fault will be expected for the following
	// printf("Original printf - %d\n", printf('42'));
	// printf("My function - %d\n", ft_print_str('42'));
	// printf("---\n");
}
