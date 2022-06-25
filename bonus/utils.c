/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:13:08 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 16:43:03 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*is_format_char(char c)
{
	char	*formats;

	formats = "cspiduxX";
	return (ft_strchr(formats, c));
}

char	*is_flag_char(char c)
{
	char	*flags;

	flags = "# +-.";
	return (ft_strchr(flags, c));
}

int	u_print_padding(char c, int length)
{
	int	counter;

	counter = 0;
	while (counter < length)
	{
		ft_putchar_fd(c, STDOUT);
		counter++;
	}
	return (counter);
}

int	u_print_str(char *str)
{
	int	str_len;

	if (!str)
		str = "(null)";
	str_len = ft_strlen(str);
	ft_putstr_fd(str, STDOUT);
	return (str_len);
}
