/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:52:43 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/15 10:01:18 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <unistd.h>
# define STDOUT 1

// Functions to print the values to the STDOUT
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_int(int nb);
int	ft_print_uint(unsigned int nb);
int	ft_print_hex(unsigned int nb, int is_upper);

#endif
