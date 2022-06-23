/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_new_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:28:21 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/22 22:11:34 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"
#include <stdio.h>

// bonus

// color functions
void	set_color(void)
{
	printf("\e[0;95m");
}

void	reset_color(void)
{
	printf("\033[0m");
}

// flag parser

static char	*is_format_char(char c)
{
	char	*formats;

	formats = "cspiduxX";
	return (ft_strchr(formats, c));
}

static char	*is_flag_char(char c)
{
	char	*flags;

	flags = "# +";
	return (ft_strchr(flags, c));
}

t_flags	ft_flag_parser(const char *str_flags)
{
	t_flags	flags;

	flags.alt_form = FALSE;
	flags.spaced_form = FALSE;
	flags.signed_form = FALSE;
	flags.left_padded = 0;
	flags.total_flags = 0;
	while (!is_format_char(*str_flags))
	{
		if (*str_flags == '#')
			flags.alt_form = TRUE;
		if (*str_flags == ' ')
			flags.spaced_form = TRUE;
		if (*str_flags == '+')
			flags.signed_form = TRUE;
		if (*str_flags == '-')
		{
			str_flags++;
			while (!is_format_char(*str_flags) && !is_flag_char(*str_flags))
			{
				flags.left_padded = flags.left_padded * 10 + (*str_flags - '0');
				flags.total_flags++;
				str_flags++;
			}
		}
		flags.total_flags++;
		str_flags++;
	}
	return (flags);
}

// utils

int	print_padding(int length, char c)
{
	int	counter;

	counter = 0;
	while (counter++ < length)
		ft_putchar_fd(c, STDOUT);
	return (counter);
}

// test functions

void	test_parser(void)
{

	const char	*format_str = "# +-10d";
	t_flags	used_flags;

	used_flags = ft_flag_parser(format_str);
	printf("used_flags.alt_form - %d\n", used_flags.alt_form);
	printf("used_flags.spaced_form - %d\n", used_flags.spaced_form);
	printf("used_flags.signed_form - %d\n", used_flags.signed_form);
	printf("used_flags.left_padded - %d\n", used_flags.left_padded);
	printf("used_flags.total_flags - %d\n", used_flags.total_flags);
}

void	test_new_flags(void)
{
	char	*word;
	int		nb;
	int		returned;

	word = "matheus";
	nb = 42;
	// Test #00 - Flag - (left_padded)
	set_color();
	printf("\nTest #00 - Flag - (left_padded)\n\n");
	reset_color();
	returned = printf("(%-20c)\n", *word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20s)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20p)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20i)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20u)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20d)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20x)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%-20X)\n", nb);
	printf("returned - %d\n\n", returned);
	printf("------\n");

	// Test #01 - Flag 0 (zero_padded)
	set_color();
	printf("\nTest #01 - Flag 0 (zero_padded)\n\n");
	reset_color();
	returned = printf("(%020c)\n", *word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020s)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020p)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020i)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020u)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020d)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020x)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%020X)\n", nb);
	printf("returned - %d\n\n", returned);
	printf("------\n");

	// Test #02 - Flag . (precision)
	set_color();
	printf("\nTest #02 - Flag . (precision)\n\n");
	reset_color();
	returned = printf("(%.20c)\n", *word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20s)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20p)\n", word);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20i)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20u)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20d)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20x)\n", nb);
	printf("returned - %d\n\n", returned);
	returned = printf("(%.20X)\n", nb);
	printf("returned - %d\n\n", returned);
	printf("------\n");
}


int	main(void)
{
	// test_parser();
	// test_new_flags();
}
