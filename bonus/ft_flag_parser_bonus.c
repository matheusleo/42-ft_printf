/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_parser_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleonard <mleonard@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 08:52:28 by mleonard          #+#    #+#             */
/*   Updated: 2022/06/25 13:42:07 by mleonard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flags	init_flags_struct(void)
{
	t_flags	initial_flags;

	initial_flags.alt_form = FALSE;
	initial_flags.spaced_form = FALSE;
	initial_flags.signed_form = FALSE;
	initial_flags.dash_flag = FALSE;
	initial_flags.zero_flag = FALSE;
	initial_flags.dot_flag = FALSE;
	initial_flags.field_width = 0;
	initial_flags.total_flags = 0;
	return (initial_flags);
}

static t_flags	parse_form_flags(const char **str_flags, t_flags flags)
{
	if (**str_flags == '#')
		flags.alt_form = TRUE;
	if (**str_flags == ' ')
		flags.spaced_form = TRUE;
	if (**str_flags == '+')
		flags.signed_form = TRUE;
	flags.total_flags++;
	(*str_flags)++;
	return (flags);
}

static t_flags	parse_field_width_flags(const char **str_flags, t_flags flags)
{
	if (**str_flags == '-')
		flags.dash_flag = TRUE;
	if (**str_flags == '0')
		flags.zero_flag = TRUE;
	if (**str_flags == '.')
		flags.dot_flag = TRUE;
	(*str_flags)++;
	flags.total_flags++;
	while (!is_format_char(**str_flags) && !is_flag_char(**str_flags))
	{
		flags.field_width = flags.field_width * 10 + (**str_flags - '0');
		flags.total_flags++;
		(*str_flags)++;
	}
	return (flags);
}

t_flags	ft_flag_parser(const char *str_flags)
{
	t_flags	flags;

	flags = init_flags_struct();
	while (!is_format_char(*str_flags))
	{
		if (ft_strchr("# +", *str_flags))
		{
			flags = parse_form_flags(&str_flags, flags);
			continue ;
		}
		if (ft_strchr("-0.", *str_flags))
		{
			flags = parse_field_width_flags(&str_flags, flags);
			continue ;
		}
		flags.total_flags++;
		str_flags++;
	}
	return (flags);
}
