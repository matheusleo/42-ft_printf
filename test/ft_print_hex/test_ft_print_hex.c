/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_print_hex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:38:09 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 09:28:53 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

// ft_print_hex

int	main(void)
{
	printf("Original printf - %d\n", printf("%x", 42));
	printf("My function - %d\n---\n", ft_print_hex(42, 0)); // 2a

	printf("Original printf - %d\n", printf("%x", 420));
	printf("My function - %d\n---\n", ft_print_hex(420, 0)); // 1a4

	printf("Original printf - %d\n", printf("%X", 42));
	printf("My function - %d\n---\n", ft_print_hex(42, 1)); // 2A

	printf("Original printf - %d\n", printf("%X", 420));
	printf("My function - %d\n---\n", ft_print_hex(420, 1)); // 1A4

	printf("Original printf - %d\n", printf("%x", -42));
	printf("My function - %d\n---\n", ft_print_hex(-42, 0)); // ffffffd6

	printf("Original printf - %d\n", printf("%x", -420));
	printf("My function - %d\n---\n", ft_print_hex(-420, 0)); // fffffe5c

	printf("Original printf - %d\n", printf("%X", -42));
	printf("My function - %d\n---\n", ft_print_hex(-42, 1)); // FFFFFFD6

	printf("Original printf - %d\n", printf("%X", -420));
	printf("My function - %d\n---\n", ft_print_hex(-420, 1)); // FFFFFE5C

}
