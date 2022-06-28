/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:51 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/28 15:53:08 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	print_sign_flags(int nb, t_flags flags)
{
	if (flags.signed_form && nb >= 0)
		return (u_print_str("+"));
	else if (flags.spaced_form && nb >= 0)
		return (u_print_str(" "));
	else
		return (0);
}

static int	print_flags_before(int nb, int nb_len, t_flags flags)
{
	if (flags.dot_flag && nb < 0)
		return (u_print_padding('0', (flags.field_width + 1) - nb_len));
	else if (flags.dot_flag && nb >= 0)
		return (u_print_padding('0', flags.field_width - nb_len));
	else if (flags.zero_flag && !flags.dash_flag)
		return (u_print_padding('0', flags.field_width - nb_len));
	else
		return (0);
}

int	ft_print_int(int nb, t_flags flags)
{
	char	*nb_str;
	int		nb_len;

	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	print_sign_flags(nb, flags);
	nb_len = ft_strlen(nb_str);
	if (nb < 0)
	{
		u_print_str("-");
		nb_str++;
	}
	nb_len += print_flags_before(nb, nb_len, flags);
	u_print_str(nb_str);
	if (nb < 0)
		free(--nb_str);
	else
		free(nb_str);
	if (flags.dash_flag)
		nb_len += u_print_padding(' ', flags.field_width - nb_len);
	if ((flags.signed_form || flags.spaced_form) && nb >= 0)
		nb_len++;
	return (nb_len);
}
