/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 09:58:14 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/01 18:09:57 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*nbr_string;
	unsigned int	number;

	len = ft_numlen(n);
	nbr_string = ft_calloc(len + 1, 1);
	if (nbr_string == 0)
		return (0);
	if (n < 0)
	{
		nbr_string[0] = '-';
		number = -n;
	}
	else
		number = n;
	while (len > 0)
	{
		if (nbr_string[len - 1] == '-')
			break ;
		nbr_string[len - 1] = number % 10 + '0';
		number = number / 10;
		len--;
	}
	return (nbr_string);
}
