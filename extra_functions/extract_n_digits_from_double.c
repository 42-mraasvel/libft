/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   extract_n_digits_from_double.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 22:15:12 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/19 22:40:37 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_double.h"
#include "libft.h"

static double	extract_n_digits(double unit, char *digits,
				int power, unsigned int n)
{
	double	tens;
	int		result;

	tens = ft_exponent(10, power);
	while (n > 0)
	{
		result = (int)(unit / tens);
		unit = unit - tens * result;
		tens /= 10;
		if (result < 0)
			result = -result;
		*digits = result + '0';
		digits++;
		n--;
	}
	return (unit);
}

char			*extract_n_digits_from_double(double unit, unsigned int n)
{
	char	*digits;
	int		power;

	power = ft_get_tenth_exp(unit);
	digits = (char*)malloc((n + 1) * sizeof(char));
	if (digits == NULL)
		return (NULL);
	digits[n] = '\0';
	unit = extract_n_digits(unit, digits, power, n);
	digits = ft_round_double(digits, unit, n - 1, 0);
	return (digits);
}
