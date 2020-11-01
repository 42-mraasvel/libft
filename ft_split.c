/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 21:02:00 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/10/30 20:39:05 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_count_strings(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (*s == 0)
		return (0);
	count = 1;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != 0)
	{
		if (s[i] == c && i != 0)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] == c)
		return (count - 1);
	return (count);
}

static char		*ft_strndup(char const *s, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	if (i < n)
		dest = (char*)malloc((i + 1) * sizeof(char));
	else
		dest = (char*)malloc((n + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	if (i < n)
		dest[i] = 0;
	else
		dest[n] = 0;
	i = 0;
	while (i < n && s[i] != 0)
	{
		dest[i] = s[i];
		i++;
	}
	return (dest);
}

static size_t	find_delimiter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static size_t	ft_free_strings(char **strings, size_t index)
{
	while (index > 0)
	{
		free(strings[index - 1]);
		index--;
	}
	free(strings);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	ri;

	if (s == 0)
		return (0);
	i = ft_count_strings(s, c);
	result = (char**)malloc((i + 1) * sizeof(char*));
	if (result == 0)
		return (0);
	result[i] = 0;
	i = 0;
	ri = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			result[ri++] = ft_strndup(&(s[i]), find_delimiter(&(s[i]), c));
			if (result[ri - 1] == 0)
				return ((char**)ft_free_strings(result, ri - 1));
			i += find_delimiter(&(s[i]), c) - 1;
		}
		i++;
	}
	return (result);
}
