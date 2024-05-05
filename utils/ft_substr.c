/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:07:00 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/03 23:04:45 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*t;
	unsigned int	l;
	size_t			buff;

	if (!s)
		return (ft_strdup(""));
	l = (unsigned int)ft_strlen((char *)s);
	i = 0;
	if (start >= l)
		return (ft_strdup(""));
	if (len > l - start)
		buff = l - start;
	else
		buff = len;
	t = (char *)malloc((buff + 1) * sizeof(char));
	if (!t)
		return (NULL);
	while (i < len && *(s + start + i))
	{
		*(t + i) = *(s + start + i);
		i++;
	}
	*(t + i) = '\0';
	return (t);
}
