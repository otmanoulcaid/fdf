/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:48:34 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/03 22:20:33 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_zoom(t_fdf *data)
{
	if (data->map->width < 8)
		return (35);
	else if (data->map->width < 10)
		return (30);
	else if (data->map->width < 20)
		return (25);
	else if (data->map->width < 30)
		return (15);
	else if (data->map->width < 40)
		return (10);
	return (1);
}
