/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:55:59 by liemi             #+#    #+#             */
/*   Updated: 2025/08/12 18:19:06 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*word_dup(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
		free(arr[--i]);
	free(arr);
}

static int	get_next(const char **ps, char c, char **out)
{
	const char	*s;
	size_t		len;

	s = *ps;
	while ((*s == c))
		s++;
	if (!*s)
	{
		*ps = s;
		*out = NULL;
		return (0);
	}
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	*out = word_dup(s, len);
	if (!*out)
		return (-1);
	*ps = s + len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*w;
	size_t	i;
	int		status;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		status = get_next(&s, c, &w);
		if (status == 0)
			break ;
		if (status == -1)
			return (free_all(result, i), NULL);
		result[i++] = w;
	}
	result[i] = NULL;
	return (result);
}
