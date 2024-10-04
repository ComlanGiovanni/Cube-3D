/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_levels_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gicomlan <gicomlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:46:23 by gicomlan          #+#    #+#             */
/*   Updated: 2024/09/06 18:25:30 by gicomlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_so_long_bonus.h"

//t_point
void	ft_reset_grid(t_game *game)
{
	int	x;
	int	y;

	x = 0x0;
	y = 0x0;
	while (y < game->map.size.y)
	{
		x = 0x0;
		while (x < game->map.size.x)
		{
			game->map.grid[y][x] = game->map.original[y][x];
			x++;
		}
		y++;
	}
}
