/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:04:55 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/17 11:14:03 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_unsigned_lint(unsigned long int nb)
{
	char	*base;
	int		base_len;
	int		nb_len;

	nb_len = 0;
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (nb != 0)
	{
		nb_len += 1;
		nb_len += print_unsigned_lint(nb / base_len);
		ft_putchar_fd(base[nb % base_len], STDOUT);
		return (nb_len);
	}
	return (nb_len);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long int	addr;
	int					nb_len;

	addr = (unsigned long int)ptr;
	if (!ptr)
		return (ft_print_str("(nil)"));
	nb_len = ft_print_str("0x");
	nb_len += print_unsigned_lint(addr);
	return (nb_len);
}
