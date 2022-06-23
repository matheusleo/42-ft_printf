/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 20:56:24 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_str(char *str, t_flags flags)
{
	int		str_len;

	str_len = u_print_str(str);
	if (flags.dash_flag - str_len > 0)
		str_len += u_print_padding(' ', flags.dash_flag - str_len);
	return (str_len);
}
