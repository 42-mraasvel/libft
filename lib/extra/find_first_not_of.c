/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_first_not_of.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/31 16:14:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/10/31 16:23:04 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_first_not_of(char *s, int (*is_function)(int))
{
	while (*s != '\0' && is_function(*s))
	{
		++s;
	}
	return (s);
}
