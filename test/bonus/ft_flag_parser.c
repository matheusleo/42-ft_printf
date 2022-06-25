/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:52:28 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 13:25:52 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static char	*is_format_char(char c)
{
	char	*formats;

	formats = "cspiduxX";
	return (ft_strchr(formats, c));
}

t_flags	ft_flag_parser(const char *str_flags)
{
	t_flags	flags;

	flags.alt_form = FALSE;
	flags.spaced_form = FALSE;
	flags.signed_form = FALSE;
	flags.total_flags = 0;
	while (!is_format_char(*str_flags))
	{
		if (*str_flags == '#')
			flags.alt_form = TRUE;
		if (*str_flags == ' ')
			flags.spaced_form = TRUE;
		if (*str_flags == '+')
			flags.signed_form = TRUE;
		if (*str_flags == '#' || *str_flags == ' ' || *str_flags == '+')
			flags.total_flags += 1;
		str_flags++;
	}
	return (flags);
}
