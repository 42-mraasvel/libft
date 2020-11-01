/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 10:38:05 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/29 16:29:35 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	size_t	len;

	if (s == 0 || f == 0)
		return (0);
	len = ft_strlen(s);
	dest = (char*)malloc((len + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	dest[len] = 0;
	len = 0;
	while (s[len] != 0)
	{
		dest[len] = (*f)(len, s[len]);
		len++;
	}
	return (dest);
}
