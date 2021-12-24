/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ref.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 14:11:43 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:11:44 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

void	set_refs(int (*refs[254])(t_data*))
{
	refs['%'] = pf_percent;
	refs['c'] = pf_char;
	refs['s'] = pf_string;
	refs['p'] = pf_pointer;
	refs['d'] = pf_integer;
	refs['i'] = pf_integer;
	refs['u'] = pf_unsigned_x;
	refs['x'] = pf_unsigned_x;
	refs['X'] = pf_unsigned_x;
}

int	jump_to_ref(int (*refs[254])(t_data*), int c, t_data *data)
{
	if (refs[c])
		return (refs[c](data));
	return (ft_putchar(c));
}
