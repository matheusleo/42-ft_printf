/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:52:43 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/15 19:29:04 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# define STDOUT 1

// Main function
int	ft_printf(const char *format, ...);

// Functions to print the values to the STDOUT
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_int(int nb);
int	ft_print_uint(unsigned int nb);
int	ft_print_hex(unsigned int nb, int is_upper);
int	ft_print_ptr(void *ptr);

#endif
