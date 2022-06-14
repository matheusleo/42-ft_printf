/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:33:57 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/14 20:09:55 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_dec(int nb)
{
	char	*nb_str;
	int		nb_len;

	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	nb_len = ft_print_str(nb_str);
	return (nb_len);
}
