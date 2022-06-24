/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:52:28 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/24 10:08:22 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*is_format_char(char c)
{
	char	*formats;

	formats = "cspiduxX";
	return (ft_strchr(formats, c));
}

static char	*is_flag_char(char c)
{
	char	*flags;

	flags = "# +";
	return (ft_strchr(flags, c));
}

t_flags	ft_flag_parser(const char *str_flags)
{
	t_flags	flags;

	flags.alt_form = FALSE;
	flags.spaced_form = FALSE;
	flags.signed_form = FALSE;
	flags.dash_flag = 0;
	flags.zero_flag = 0;
	flags.dot_flag = 0;
	flags.precision = 0;
	flags.total_flags = 0;
	while (!is_format_char(*str_flags))
	{
		if (*str_flags == '#')
			flags.alt_form = TRUE;
		if (*str_flags == ' ')
			flags.spaced_form = TRUE;
		if (*str_flags == '+')
			flags.signed_form = TRUE;
		if (*str_flags == '-')
		{
			str_flags++;
			flags.total_flags++;
			while (!is_format_char(*str_flags) && !is_flag_char(*str_flags))
			{
				flags.dash_flag = flags.dash_flag * 10 + (*str_flags - '0');
				flags.total_flags++;
				str_flags++;
			}
			continue ;
		}
		if (*str_flags == '0')
		{
			str_flags++;
			flags.total_flags++;
			while (!is_format_char(*str_flags) && !is_flag_char(*str_flags))
			{
				flags.zero_flag = flags.zero_flag * 10 + (*str_flags - '0');
				flags.total_flags++;
				str_flags++;
			}
			continue ;
		}
		if (*str_flags == '.')
		{
			flags.dot_flag = TRUE;
			str_flags++;
			flags.total_flags++;
			while (!is_format_char(*str_flags) && !is_flag_char(*str_flags))
			{
				flags.precision = flags.precision * 10 + (*str_flags - '0');
				flags.total_flags++;
				str_flags++;
			}
			continue ;
		}
		flags.total_flags++;
		str_flags++;
	}
	return (flags);
}
