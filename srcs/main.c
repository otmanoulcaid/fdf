/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:28:06 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/02/25 19:28:06 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	exit_func(void)
{
	exit(EXIT_SUCCESS);
	return (1);
}

int	main(int ac, char **av)
{
	t_fdf	data;

	if (ac != 2 || !valid_extention(av[1]))
		ft_throw("invalid data");
	init_mlx_content(&data);
	parse_map(&data, av[1]);
	fdf(&data);
	mlx_hook(data.win_ptr, 2, 0, event_handling, &data);
	mlx_hook(data.win_ptr, 17, 0, exit_func, &data);
	mlx_loop(data.mlx);
	return (0);
}
