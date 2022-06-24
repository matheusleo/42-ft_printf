/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:57 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 21:02:02 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(int c, t_flags flags)
{
	int	len;

	len = 1;
	if (flags.zero_flag && !flags.dash_flag)
		len += u_print_padding(' ', flags.zero_flag - len);
	ft_putchar_fd((unsigned char)c, STDOUT);
	if (flags.dash_flag)
		len += u_print_padding(' ', flags.dash_flag - len);
	return (len);
}
