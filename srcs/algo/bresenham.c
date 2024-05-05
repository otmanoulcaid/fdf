/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:47:32 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/05 10:31:49 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	slope_bigger_than_one(t_fdf *data, t_point d, t_point *a)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(d.x) - abs(d.y);
	while (++i < abs(d.y))
	{
		my_mlx_pixel_put(data, a);
		if (d.y > 0)
			a->y++;
		else
			a->y--;
		if (p < 0)
			p += abs(d.x);
		else
		{
			if (d.x > 0)
				a->x++;
			else
				a->x--;
			p += (abs(d.x) - abs(d.y));
		}
	}
}

void	slope_less_than_one(t_fdf *data, t_point d, t_point *a)
{
	int	p;
	int	i;

	i = -1;
	p = 2 * abs(d.y) - abs(d.x);
	while (++i < abs(d.x))
	{
		my_mlx_pixel_put(data, a);
		if (d.x > 0)
			a->x++;
		else
			a->x--;
		if (p < 0)
			p += abs(d.y);
		else
		{
			if (d.y > 0)
				a->y++;
			else
				a->y--;
			p += (abs(d.y) - abs(d.x));
		}
	}
}

void	bresenham(t_point p1, t_point p2, t_fdf *data)
{
	t_point	delta;

	set_coordinate(&p1, &p2, data);
	delta.x = p2.x - p1.x;
	delta.y = p2.y - p1.y;
	if (abs(delta.x) > abs(delta.y))
		slope_less_than_one(data, delta, &p1);
	else
		slope_bigger_than_one(data, delta, &p1);
}
