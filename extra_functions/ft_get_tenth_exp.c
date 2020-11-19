/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_tenth_exp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:02:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/19 13:40:27 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_double.h"

int	ft_get_tenth_exp(double value)
{
	t_double	nbr;
	int			exp;

	exp = 0;
	nbr.value = value;
	if (nbr.bitfield.exponent == 0 && nbr.bitfield.mantissa == 0)
		return (0);
	while (value > 9 || value < -9)
	{
		value = value / 10;
		exp++;
	}
	while (value < 1 && value > -1)
	{
		value = value * 10;
		exp--;
	}
	return (exp);
}
