/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_func_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:03:26 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 21:54:48 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"
#include <stdio.h>

int	ft_print_str(char *str)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT);
	return (str_len);
}


// Refactored ft_print_hex

int	ft_print_hex(unsigned int nb, int is_upper, int is_alt)
{
	char			*base;
	int				nb_len;
	unsigned int	quoc;
	unsigned int	remain;

	nb_len = 1;
	if (is_upper)
	{
		base = "0123456789ABCDEF";
		if (is_alt)
			nb_len += ft_print_str("0x");
	}
	else
	{
		base = "0123456789abcdef";
		if (is_alt)
			nb_len += ft_print_str("0x");
	}
	quoc = nb / ft_strlen(base);
	remain = nb % ft_strlen(base);
	if (quoc != 0)
		nb_len += ft_print_hex(quoc, is_upper, FALSE);
	ft_putchar_fd(base[remain], STDOUT);
	return (nb_len);
}
