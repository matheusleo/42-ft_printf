/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:26:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/20 22:17:26 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_parse_format_char(char indicator, va_list list)
{
	if (indicator == 'c')
		return (ft_print_char(va_arg(list, int)));
	if (indicator == 's')
		return (ft_print_str(va_arg(list, char *)));
	if (indicator == 'd')
		return (ft_print_int(va_arg(list, int)));
	if (indicator == 'i')
		return (ft_print_int(va_arg(list, int)));
	if (indicator == 'u')
		return (ft_print_uint(va_arg(list, unsigned int)));
	if (indicator == 'x')
		return (ft_print_hex(va_arg(list, unsigned int), FALSE));
	if (indicator == 'X')
		return (ft_print_hex(va_arg(list, unsigned int), TRUE));
	if (indicator == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	return (ft_print_char('%'));
}

int	ft_printf(const char *format, ...)
{
	int		format_len;
	va_list	arg_list;

	va_start(arg_list, format);
	format_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format_len += ft_parse_format_char(*(++format), arg_list);
			format++;
			continue ;
		}
		ft_putchar_fd(*format, STDOUT);
		format++;
		format_len++;
	}
	va_end(arg_list);
	return (format_len);
}
