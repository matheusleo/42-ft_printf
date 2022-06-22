/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:45:32 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/21 23:10:33 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_parse_format_char(char indicator, va_list list, t_flags flags)
{
	if (indicator == 'c')
		return (ft_print_char(va_arg(list, int)));
	if (indicator == 's')
		return (ft_print_str(va_arg(list, char *)));
	if (indicator == 'd')
		return (ft_print_int(va_arg(list, int), flags));
	if (indicator == 'i')
		return (ft_print_int(va_arg(list, int), flags));
	if (indicator == 'u')
		return (ft_print_uint(va_arg(list, unsigned int)));
	if (indicator == 'x')
		return (ft_print_hex(va_arg(list, unsigned int), FALSE, flags));
	if (indicator == 'X')
		return (ft_print_hex(va_arg(list, unsigned int), TRUE, flags));
	if (indicator == 'p')
		return (ft_print_ptr(va_arg(list, void *)));
	return (ft_print_char('%'));
}

int	ft_printf(const char *format, ...)
{
	int		format_len;
	va_list	arg_list;
	t_flags	flags;

	va_start(arg_list, format);
	format_len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			flags = ft_flag_parser(++format);
			format += flags.total_flags;
			format_len += ft_parse_format_char(*(format), arg_list, flags);
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
