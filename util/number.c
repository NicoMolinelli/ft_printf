/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nmolinel <nmolinel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/16 13:37:24 by nmolinel      #+#    #+#                 */
/*   Updated: 2021/12/16 14:26:08 by nmolinel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}

/*	Converts an unsigned number(nb) of base(base)
	in string and store it in data.

	- return length of the string converted.
*/
int	put_unb(unsigned long nb, char *base, int base_len, char *data)
{
	static int	i;

	if (nb / base_len > 0)
		put_unb(nb / base_len, base, base_len, data);
	else
		i = 0;
	data[i++] = base[nb % base_len];
	data[i] = 0;
	return (i);
}

/*	Converts a long number(nb) of base(base)
	in string and store it in data.
	Handles of course negative numbers.

	- return length of the string converted.
*/
int	put_nb(long nb, char *base, int base_len, char *data)
{
	static int	i;

	if (nb < 0)
		nb *= -1;
	if (nb / base_len > 0)
		put_nb(nb / base_len, base, base_len, data);
	else
		i = 0;
	data[i++] = base[nb % base_len];
	data[i] = 0;
	return (i);
}
