/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 10:50:58 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/15 12:02:57 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	unsigned long int	addr;
	char				*base;
	char				buffer[12];
	ssize_t				iterator;

	iterator = 0;
	addr = (unsigned long int)ptr;
	base = "0123456789abcdef";
	while (iterator < 12)
	{
		buffer[iterator] = base[addr % ft_strlen(base)];
		addr = addr / ft_strlen(base);
		iterator++;
	}
	ft_putstr_fd("0x", STDOUT);
	while (iterator >= 0)
	{
		ft_putchar_fd(buffer[iterator], STDOUT);
		iterator--;
	}
	return (ft_strlen(buffer) + 2);
}
