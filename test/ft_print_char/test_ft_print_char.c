/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:50:24 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/13 22:31:08 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

// ft_print_char

int	main(void)
{
	// Ordinary tests
	printf("Teste #01\n");
	printf("Original printf - %d\n", printf("%c", 'm'));
	printf("My function - %d\n", ft_print_char('m'));
	printf("---\n");
	printf("Original printf - %d\n", printf("%c", ' '));
	printf("My function - %d\n", ft_print_char(' '));
	printf("---\n");
	// Unsafe tests
/* 	printf("Original printf - %d\n", printf("%c", 'as'));
	printf("My function - %d\n", ft_print_char('as')); */
}
