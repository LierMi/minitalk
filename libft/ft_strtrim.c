/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:17:10 by liemi             #+#    #+#             */
/*   Updated: 2025/08/11 22:38:26 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	return (ft_substr(s1, start, len));
}

// int	main(void)
// {
// 	char	*s = "\n\t  Hello 42! \t\t\n";
// 	char	*set = " \n\t";
// 	char	*trimmed = ft_strtrim(s, set);

// 	if (trimmed)
// 	{
// 		printf("Trimmed: \"%s\"\n", trimmed); // 应该输出：Hello 42!
// 		free(trimmed);
// 	}
// 	else
// 		printf("Memory allocation failed.\n");
// 	return (0);
// }
