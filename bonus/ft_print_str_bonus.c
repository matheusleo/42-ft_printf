/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 20:35:57 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str(char *str, t_flags flags)
{
	int		str_len;

	str_len = u_print_str(str);
	if (flags.left_padded - str_len > 0)
		str_len += u_print_padding(' ', flags.left_padded - str_len);
	return (str_len);
}
