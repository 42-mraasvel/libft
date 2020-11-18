/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_get_tenth_exp.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 17:02:41 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/18 17:03:52 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_get_tenth_exp(double value)
{
	int	exp;

	exp = 0;
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
