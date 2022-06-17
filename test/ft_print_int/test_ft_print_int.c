/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:30:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/14 20:27:57 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_printf.h"

// ft_print_int

int	main(void)
{
	printf("Original printf - %d\n", printf("%d", 0));
	printf("My function - %d\n---\n", ft_print_int(0));
	printf("Original printf - %d\n", printf("%d", -0));
	printf("My function - %d\n---\n", ft_print_int(-0));
	printf("Original printf - %d\n", printf("%d", 1));
	printf("My function - %d\n---\n", ft_print_int(1));
	printf("Original printf - %d\n", printf("%d", -1));
	printf("My function - %d\n---\n", ft_print_int(-1));
	printf("Original printf - %d\n", printf("%d", -5));
	printf("My function - %d\n---\n", ft_print_int(-5));
	printf("Original printf - %d\n", printf("%d", 5));
	printf("My function - %d\n---\n", ft_print_int(5));
}
