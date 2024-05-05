/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:46:46 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/05 10:30:28 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	my_mlx_pixel_put(t_fdf *data, t_point *a)
{
	int	color;
	int	i;

	if (a->x > MAX_WIDTH / 5 && a->x < MAX_WIDTH && a->y > 0
		&& a->y < MAX_HEIGH)
	{
		color = a->color;
		i = (a->y * data->map->win_x) + (a->x * data->map->bbp / 8);
		data->map->img_addr[i] = color;
		data->map->img_addr[++i] = color >> 8;
		data->map->img_addr[++i] = color >> 16;
	}
}
