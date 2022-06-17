/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:54:06 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/17 11:24:21 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

//ft_print_ptr

int	main(void)
{
	char	*word;

	word = "matheus";
	int value_word = printf("%s", word);
	printf("\n");
	int value_word_addr = printf("%p", word);
	printf("\n");
	int value_word_addr_addr = printf("%p", &word);
	printf("\n");
	int func_word = ft_print_str(word);
	ft_putstr_fd("\n",STDOUT);
	int func_word_addr = ft_print_ptr(word);
	ft_putstr_fd("\n",STDOUT);
	int func_word_addr_addr = ft_print_ptr(&word);
	ft_putstr_fd("\n",STDOUT);
	printf("\n---\n");
	printf("value_word - %d\n", value_word);
	printf("value_word_addr - %d\n", value_word_addr);
	printf("value_word_addr_addr - %d\n", value_word_addr_addr);
	printf("func_word - %d\n", func_word);
	printf("func_word_addr - %d\n", func_word_addr);
	printf("func_word_addr_addr - %d\n", func_word_addr_addr);
	// NULL test
	printf("\n-----\nprintf NULL - ");
	int value_NULL = printf("%p", NULL);
	printf("\nvalue_NULL - %d\n", value_NULL);
	ft_putstr_fd("My func NULL - ",STDOUT);
	int func_value_NULL = ft_print_ptr(NULL);
	ft_putstr_fd("\n",STDOUT);
	printf("func_value_NULL - %d\n", func_value_NULL);
}
