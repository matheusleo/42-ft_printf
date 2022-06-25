/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:51 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 11:22:51 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_int(int nb, t_flags flags)
{
	char	*nb_str;
	int		nb_len;

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
	if (flags.dot_flag)
		nb_len += u_print_padding('0', flags.precision - nb_len);
	else if (flags.zero_flag && !flags.dash_flag)
		nb_len += u_print_padding('0', flags.zero_flag - nb_len);
	u_print_str(nb_str);
	if (nb < 0)
		free(--nb_str);
	else
		free(nb_str);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.dash_flag - nb_len);
	return (nb_len);
}
