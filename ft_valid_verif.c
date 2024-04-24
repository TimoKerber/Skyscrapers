/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 21:06:16 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/27 22:29:10 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_valid_verif.h"

int	ft_valid_from_left(int **matrix, struct s_dim s_pos, int clue, int val)
{
	int	visible;
	int	max_height;
	int	count;

	visible = 0;
	max_height = 0;
	count = 0;
	matrix[s_pos.row][s_pos.col] = val;
	while (count < 4)
	{
		if (matrix[s_pos.row][count] > max_height)
		{
			visible++;
			max_height = matrix[s_pos.row][count];
		}
		count++;
	}
	matrix[s_pos.row][s_pos.col] = 0;
	if (visible > clue)
		return (0);
	if (visible < clue && s_pos.col == 3)
		return (0);
	return (1);
}

int	ft_valid_from_right(int **matrix, struct s_dim s_pos, int clue, int val)
{
	int	visible;
	int	max_height;
	int	count;

	visible = 0;
	max_height = 0;
	count = 3;
	matrix[s_pos.row][s_pos.col] = val;
	while (count >= 0)
	{
		if (matrix[s_pos.row][count] > max_height)
		{
			visible++;
			max_height = matrix[s_pos.row][count];
		}
		count--;
	}
	matrix[s_pos.row][s_pos.col] = 0;
	if (visible > clue && s_pos.col == 3)
		return (0);
	if (visible < clue && s_pos.col == 3)
		return (0);
	return (1);
}

int	ft_valid_from_top(int **matrix, struct s_dim s_pos, int clue, int val)
{
	int	visible;
	int	max_height;
	int	count;

	visible = 0;
	max_height = 0;
	count = 0;
	matrix[s_pos.row][s_pos.col] = val;
	while (count <= 3)
	{
		if (matrix[count][s_pos.col] > max_height)
		{
			visible++;
			max_height = matrix[count][s_pos.col];
		}
		count++;
	}
	matrix[s_pos.row][s_pos.col] = 0;
	if (visible > clue)
		return (0);
	if (visible < clue && s_pos.row == 3)
		return (0);
	return (1);
}

int	ft_valid_from_bottom(int **matrix, struct s_dim s_pos, int clue, int val)
{
	int	visible;
	int	max_height;
	int	count;

	visible = 0;
	max_height = 0;
	count = 3;
	matrix[s_pos.row][s_pos.col] = val;
	while (count >= 0)
	{
		if (matrix[count][s_pos.col] > max_height)
		{
			visible++;
			max_height = matrix[count][s_pos.col];
		}
		count--;
	}
	matrix[s_pos.row][s_pos.col] = 0;
	if (visible > clue && s_pos.row == 3)
		return (0);
	if (visible < clue && s_pos.row == 3)
		return (0);
	return (1);
}
