/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:28:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 09:43:07 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <stdio.h>

// bonus

int	main(void)
{
	char	*word;

	word = "matheus";
	// c
	printf("%+c\n", *word);
	// s
	printf("%+s\n", word);
	// p
	printf("%+p\n", word);
	// i - positive
	printf("%+i\n", 42);
	// u - positive
	printf("%+u\n", 42);
	// d - positive
	printf("%+d\n", 42);
	// i - negative
	printf("%+i\n", -42);
	// u - negative
	printf("%+u\n", -42);
	// d - negative
	printf("%+d\n", -42);
	// x
	printf("%+x\n", 42);
	// X
	printf("%+X\n", 42);
	// // %
	// printf("%+%\n");
}
