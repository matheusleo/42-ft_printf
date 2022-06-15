/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:33:57 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/15 20:21:51 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_int(int nb)
{
	char	*nb_str;
	int		nb_len;

	nb_str = ft_itoa(nb);
	if (!*nb_str)
		return (-1);
	nb_len = ft_print_str(nb_str);
	free(nb_str);
	return (nb_len);
}
