/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:55 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/05 09:55:27 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_throw(char *strerr)
{
	perror(strerr);
	exit(EXIT_FAILURE);
}

void	faillure(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		(free(str[i]), str[i++] = NULL);
	free(str);
}

void	finish(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->map->height)
		free(data->map->cord[i++]);
	free(data->map->cord);
	free(data->map->img_addr);
	mlx_destroy_image(data->mlx, data->map->c_panel);
	mlx_clear_window(data->mlx, data->win_ptr);
	free(data->map);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}
