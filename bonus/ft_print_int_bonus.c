/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:51 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/23 09:37:06 by mleonard         ###   ########.fr       */
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
	nb_len += u_print_str(nb_str);
	free(nb_str);
	if (flags.left_padded - nb_len > 0)
		nb_len += u_print_padding(' ', flags.left_padded - nb_len);
	return (nb_len);
}
