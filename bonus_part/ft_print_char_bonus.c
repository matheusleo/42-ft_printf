/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:57 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 13:10:14 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(int c, t_flags flags)
{
	int	len;

	len = 1;
	if (flags.zero_flag && !flags.dash_flag)
		len += u_print_padding(' ', flags.field_width - len);
	ft_putchar_fd((unsigned char)c, STDOUT);
	if (flags.dash_flag)
		len += u_print_padding(' ', flags.field_width - len);
	return (len);
}
