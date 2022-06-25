/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:51 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 13:10:29 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int ft_print_int(int nb, t_flags flags)
{
	char *nb_str;
	int nb_len;

	nb_len = 0;
	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	if (flags.signed_form && nb >= 0)
		nb_len += u_print_str("+");
	else if (flags.spaced_form && nb >= 0)
		nb_len += u_print_str(" ");
	nb_len += ft_strlen(nb_str);
	if (nb < 0)
	{
		u_print_str("-");
		nb_str++;
	}
	if (flags.dot_flag && nb < 0)
		nb_len += u_print_padding('0', (flags.field_width + 1) - nb_len);
	else if (flags.dot_flag && nb >= 0)
		nb_len += u_print_padding('0', flags.field_width - nb_len);
	else if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.field_width - nb_len);
	u_print_str(nb_str);
	if (nb < 0)
		free(--nb_str);
	else
		free(nb_str);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.field_width - nb_len);
	return (nb_len);
}

// int main(void)
// {
// 	int 	nb;
// 	int		returned;
// 	t_flags	used_flags;

// 	used_flags.alt_form = 0;
// 	used_flags.signed_form = 0;
// 	used_flags.spaced_form = 0;
// 	used_flags.dash_flag = 0;
// 	used_flags.zero_flag = 0;
// 	used_flags.dot_flag = 0;
// 	used_flags.precision = 0;
// 	used_flags.total_flags = 0;

// 	nb = -1;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 2;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.2d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = -11;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 3;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.3d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = -14;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 4;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.4d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = -99;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 3;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.3d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = -101;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 4;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.4d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);

// 	nb = 1;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 2;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.2d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = 11;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 3;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.3d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = 14;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 4;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.4d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = 99;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 3;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.3d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	nb = 101;
// 	used_flags.dot_flag = 1;
// 	used_flags.precision = 4;
// 	used_flags.total_flags = 2;
// 	returned = printf("%.4d\n", nb);
// 	printf("original returned - %d\n", returned - 1);
// 	returned = ft_print_int(nb, used_flags);
// 	printf("\nmine returned - %d\n----\n", returned);


// 	// nb = LONG_MAX;
// 	// used_flags.dot_flag = 0;
// 	// used_flags.precision = 0;
// 	// used_flags.total_flags = 0;
// 	// returned = printf("%.10d\n", nb);
// 	// printf("original returned - %d\n", returned - 1);
// 	// returned = ft_print_int(nb, used_flags);
// 	// printf("\nmine returned - %d\n", returned);

// 	// nb = UINT_MAX;
// 	// used_flags.dot_flag = 0;
// 	// used_flags.precision = 0;
// 	// used_flags.total_flags = 0;
// 	// returned = printf("%.12d\n", nb);
// 	// printf("original returned - %d\n", returned - 1);
// 	// returned = ft_print_int(nb, used_flags);
// 	// printf("\nmine returned - %d\n", returned);

// 	// nb = ULONG_MAX;
// 	// used_flags.dot_flag = 0;
// 	// used_flags.precision = 0;
// 	// used_flags.total_flags = 0;
// 	// returned = printf("%.13d\n", nb);
// 	// printf("original returned - %d\n", returned - 1);
// 	// returned = ft_print_int(nb, used_flags);
// 	// printf("\nmine returned - %d\n", returned);

// 	// nb = 9223372036854775807LL;
// 	// used_flags.dot_flag = 0;
// 	// used_flags.precision = 0;
// 	// used_flags.total_flags = 0;
// 	// returned = printf("%.14d\n", 9223372036854775807LL);
// 	// printf("original returned - %d\n", returned - 1);
// 	// returned = ft_print_int(nb, used_flags);
// 	// printf("\nmine returned - %d\n", returned);
// }
