/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:52 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/26 13:47:52 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	in_hexa(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')
			|| str[i] == 'x' || str[i] == ',' || str[i] == '-' || str[i] == '+'
			|| (str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int	valid_extention(char *av)
{
	char	*s;

	s = NULL;
	if (av)
		s = ft_strrchr(av, '.');
	if (s && !ft_strncmp(s + 1, "fdf", 3))
		return (1);
	return (0);
}
