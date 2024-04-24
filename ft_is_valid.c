/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:42:30 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/27 23:04:14 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid_verif.h"

int	ft_is_unique(int **matrix, struct s_dim s_pos, int val)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (matrix[s_pos.row][i] == val)
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (matrix[i][s_pos.col] == val)
			return (0);
	i++;
	}
	return (1);
}

int	ft_is_valid(int **matrix, struct s_dim s_pos, int val, int **clues)
{
	if (!(ft_is_unique(matrix, s_pos, val)))
	{
		return (0);
	}
	if (!(ft_valid_from_left(matrix, s_pos, clues[2][s_pos.row], val))
		|| !(ft_valid_from_right(matrix, s_pos, clues[3][s_pos.row], val)))
	{
		return (0);
	}
	if (!(ft_valid_from_top(matrix, s_pos, clues[0][s_pos.col], val))
		|| !(ft_valid_from_bottom(matrix, s_pos, clues[1][s_pos.col], val)))
	{
		return (0);
	}
	return (1);
}
