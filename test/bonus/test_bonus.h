/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:07:08 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/22 22:11:37 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BONUS_H
# define TEST_BONUS_H
# define STDOUT 1
# define FALSE 0
# define TRUE 1
# include <stdarg.h>
# include <unistd.h>
# include "../../includes/libft.h"

typedef struct s_flags
{
	int	alt_form;
	int	signed_form;
	int	spaced_form;
	int	left_padded;
	int	total_flags;
}				t_flags;

// Unchanged functions
int	ft_print_str(char *str);

// Refactored functions
int	ft_printf(const char *format, ...);
int	ft_print_hex(unsigned int nb, int is_upper, int is_alt);
int	ft_print_int(int nb, int is_signed, int is_spaced);

// Flag parser
t_flags	ft_flag_parser(const char *str_flags);

#endif
