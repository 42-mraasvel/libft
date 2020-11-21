/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_double_exp.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/21 16:52:45 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/21 16:52:46 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	dbl_exponent(double nbr)
{
	int	e;

	e = 0;
	if (nbr == 0)
		return (0);
	while (nbr < 1 && nbr > -1)
	{
		nbr *= 10;
		e--;
	}
	while (nbr >= 10 || nbr <= -10)
	{
		nbr /= 10;
		e++;
	}
	return (e);
}
