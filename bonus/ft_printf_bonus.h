/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:52:43 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/21 22:55:31 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# define STDOUT 1
# define FALSE 0
# define TRUE 1

// Struct to track the flags which are being used
typedef struct s_flags
{
	int	alt_form;
	int	signed_form;
	int	spaced_form;
	int	total_flags;
}				t_flags;

// Main function
int		ft_printf(const char *format, ...);

// Flag parser
t_flags	ft_flag_parser(const char *str_flags);

// Functions to print the values to the STDOUT
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_uint(unsigned int nb);
int		ft_print_int(int nb, t_flags flags);
int		ft_print_hex(unsigned int nb, int is_upper, t_flags flags);

#endif
