/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:50:43 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/27 22:40:37 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_valid_verif.h"

int	ft_is_valid(int **matrix, struct s_dim s_pos, int val, int **clues);

int	is_complete(int **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (matrix[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_find_empty_row(int **matrix, int row, int col)
{
	while (row <= 3)
	{
		col = 0;
		while (col < 3)
		{
			if (matrix[row][col] == 0)
				break ;
			col++;
		}
		if (matrix[row][col] == 0)
			break ;
		row++;
	}
	return (row);
}

int	ft_find_empty_col(int **matrix, int row, int col)
{
	while (row <= 3)
	{
		col = 0;
		while (col < 3)
		{
			if (matrix[row][col] == 0)
				break ;
			col++;
		}
		if (matrix[row][col] == 0)
			break ;
		row++;
	}
	return (col);
}

int	**ft_solve_puzzle(int **matrix, int **clues)
{
	int				height;
	struct s_dim	s_pos;

	if (is_complete(matrix) == 1)
		return (matrix);
	s_pos.row = ft_find_empty_row(matrix, 0, 0);
	s_pos.col = ft_find_empty_col(matrix, 0, 0);
	height = 1;
	while (height <= 4)
	{
		if (ft_is_valid(matrix, s_pos, height, clues) == 1)
		{
			matrix[s_pos.row][s_pos.col] = height;
			if (ft_solve_puzzle(matrix, clues) != NULL)
				return (matrix);
			matrix[s_pos.row][s_pos.col] = 0;
		}
		height++;
	}
	return (NULL);
}
