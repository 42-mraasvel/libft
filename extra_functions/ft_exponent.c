/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exponent.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 12:35:28 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/18 16:59:54 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

double	ft_exponent(double x, double pow)
{
	double	result;

	if (pow == 0 || x == 1.0)
		return (1.0);
	result = 1.0;
	if (pow < 0)
		return (result / ft_exponent(x, -pow));
	while (pow > 0)
	{
		result = result * x;
		pow--;
	}
	return (result);
}
