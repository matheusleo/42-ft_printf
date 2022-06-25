/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 16:28:23 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*generate_limited_str(char *str, int max_length)
{
	char	*limited_str;

	limited_str = (char *)malloc(sizeof(char) * max_length + 1);
	ft_strlcpy(limited_str, str, max_length + 1);
	return (limited_str);
}

int	ft_print_str(char *str, t_flags flags)
{
	int		str_len;

	str_len = 0;
	if (flags.dot_flag)
		str = generate_limited_str(str, flags.field_width);
	if (!str)
		return (ft_print_str("(null)", flags));
	str_len = ft_strlen(str);
	if (!str_len && !flags.dash_flag && !flags.dot_flag && flags.field_width)
		return (u_print_padding(' ', flags.field_width));
	if (flags.zero_flag && !flags.dash_flag)
		str_len += u_print_padding(' ', flags.field_width - str_len);
	u_print_str(str);
	if (flags.dash_flag)
		str_len += u_print_padding(' ', flags.field_width - str_len);
	if (flags.dot_flag)
		free(str);
	return (str_len);
}
