/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnofc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 10:18:24 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/11/15 12:00:44 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_tenth_putnofc(size_t n, unsigned char c)
{
	char	buffer[10000];

	if (write(1, buffer, n % 10000) == -1)
		return (-1);
	ft_memset(buffer, (int)c, 10000);
	while (n > 10000)
	{
		if (write(1, buffer, 10000) == -1)
			return (-1);
		n -= 10000;
	}
	return (0);
}

/*
** Write unsigned char 'c' n times to stdout
** Return: bytes written or -1 on error.
*/

ssize_t		ft_putnofc(size_t n, unsigned char c)
{
	char	*buffer;

	if (n > 10000)
	{
		if (ft_tenth_putnofc(n, c) == -1)
			return (-1);
		return (n);
	}
	buffer = (char*)malloc(n * sizeof(char));
	if (buffer == 0)
		return (-1);
	ft_memset(buffer, c, n);
	if (write(1, buffer, n) == -1)
		return (-1);
	free(buffer);
	return (n);
}
