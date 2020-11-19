/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_put_double.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 10:18:18 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/19 12:02:23 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //remove
#include <unistd.h>
#include <stdlib.h>
#include "ft_double.h"
#include "libft.h"

static int		inf_nan(t_double nbr)
{
	if (nbr.bitfield.mantissa != 0)
	{
		if (write(1, "nan", 3) == -1)
			return (-1);
		return (3);
	}
	if (nbr.bitfield.sign == 1)
		if (write(1, "-", 1) == -1)
			return (-1);
	if (write(1, "inf", 3) == -1)
		return (-1);
	return (3 + nbr.bitfield.sign);
}

static double	extract_integers(double number, int pow, char *string)
{
	double		tens;
	int			c;

	if (pow < 0)
	{
		*string = '0';
		return (number);
	}
	tens = ft_exponent(10, pow);
	while (pow >= 0)
	{
		c = (int)(number / tens);
		number = number - c * tens;
		tens /= 10;
		if (c < 0)
			c = -c;
		c += '0';
		*string = c;
		string++;
		pow--;
	}
	return (number);
}

static double	extract_fraction(double number, int precision, char *string)
{

}


static char		*put_double_in_string(double number, int precision)
{
	char	*string;
	int		size;
	int		pow;

	pow = ft_get_tenth_exp(number);
	if (pow <= 0)
		size = 1 + (precision > 0 ? precision + 2 : 1);
	else
		size = pow + 1 + (precision > 0 ? precision + 2 : 1);
	string = (char*)ft_calloc(size, sizeof(char));
	if (string == 0)
		return (NULL);
	number = extract_integers(number, pow, string);
	if (precision != 0)
	{
		string[size - precision - 2] = '.';
		number = extract_fraction(number, precision, string + pow + 2);
	}
	return (string);
}

int				ft_put_double(double number, int precision)
{
	t_double	nbr;
	char		*string;

	nbr.value = number;
	if (precision < 0)
		precision = 6;
	if (nbr.bitfield.exponent == 2047)
		return (inf_nan(nbr));
	if (nbr.bitfield.sign == 1)
		if (write(1, "-", 1) == -1)
			return (-1);
	string = put_double_in_string(number, precision);
	if (string == 0)
		return (-1);
	ft_putstr_fd(string, 1);
	free(string);
	return (0);
}
