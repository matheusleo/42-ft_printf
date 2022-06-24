/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:48:44 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/24 09:27:52 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*generate_limited_str(char *str, int max_length)
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
		str = generate_limited_str(str, flags.precision);
	if (!str)
		return (ft_print_str("(null)", flags));
	str_len = ft_strlen(str);
	if (flags.zero_flag && !flags.dash_flag)
		str_len += u_print_padding(' ', flags.zero_flag - str_len);
	str_len += u_print_str(str);
	if (flags.dash_flag)
		str_len += u_print_padding(' ', flags.dash_flag - str_len);
	if (flags.dot_flag)
		free(str);
	return (str_len);
}
