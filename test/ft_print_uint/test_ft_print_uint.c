/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:32:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/14 22:35:51 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: remove unused or test libraries from source code
#include <stdio.h>
#include "../includes/ft_printf.h"

// ft_print_uint

int	main(void)
{
	printf("Original printf - %d\n", printf("%u", -0));
	printf("My function - %d\n---\n", ft_print_uint(-0));

	printf("Original printf - %d\n", printf("%u", 1));
	printf("My function - %d\n---\n", ft_print_uint(1));

	printf("Original printf - %d\n", printf("%u", -1));
	printf("My function - %d\n---\n", ft_print_uint(-1));

	printf("Original printf - %d\n", printf("%u", -5));
	printf("My function - %d\n---\n", ft_print_uint(-5));

	printf("Original printf - %d\n", printf("%u", 5));
	printf("My function - %d\n---\n", ft_print_uint(5));

	printf("Original printf - %d\n", printf("%u", 65535));
	printf("My function - %d\n---\n", ft_print_uint(65535));

	printf("Original printf - %d\n", printf("%u", 429496729));
	printf("My function - %d\n---\n", ft_print_uint(429496729));
}
