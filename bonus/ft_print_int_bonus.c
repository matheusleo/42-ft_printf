/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:51 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/21 21:51:45 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_int(int nb, int is_signed, int is_spaced)
{
	char	*nb_str;
	int		nb_len;

	nb_len = 0;
	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	if (is_signed && nb > 0)
		nb_len += ft_print_str("+");
	else if (is_spaced && nb > 0)
		nb_len += ft_print_str(" ");
	nb_len += ft_print_str(nb_str);
	free(nb_str);
	return (nb_len);
}
