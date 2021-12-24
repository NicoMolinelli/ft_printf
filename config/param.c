/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   param_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 13:06:45 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 13:18:49 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/** reset_params() **/
// should bzero conversion??
static t_data	*reset_params(t_data *params)
{
	params->hex = 0;
	params->plus_sign = 0;
	params->left_pad = 0;
	params->pad = ' ';
	params->width = 0;
	params->precision = -1;
	return (params);
}

static int	is_flag(int c)
{
	return (c == '0' || c == '#' || c == ' ' || c == '-' || c == '+');
}

static void	set_num_param(const char **str, int *data_param)
{
	*data_param = 0;
	while (ft_isdigit(**str))
	{
		*data_param = 10 * *data_param + (**str - '0');
		(*str)++;
	}
}

static void	set_flags(const char **str, t_data *params)
{
	while (is_flag(**str))
	{
		if (**str == '#')
			params->hex = 1;
		else if (**str == '+')
			params->plus_sign = '+';
		else if (**str == '-')
		{
			params->left_pad = 1;
			params->pad = ' ';
		}
		else if (**str == '0' && !params->left_pad)
			params->pad = '0';
		else if (**str == ' ' && !params->plus_sign)
			params->plus_sign = ' ';
		(*str)++;
	}
}

void	set_params(const char **str, t_data *params)
{
	++(*str);
	reset_params(params);
	set_flags(str, params);
	set_num_param(str, &params->width);
	if (**str == '.')
	{
		params->pad = ' ';
		++(*str);
		set_num_param(str, &params->precision);
	}
	if (params->pad == '0' && params->precision == -1)
		params->precision = params->width;
	params->format = **str;
}
