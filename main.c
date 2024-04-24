/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:08:03 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/28 00:02:06 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	**ft_solve_puzzle(int **matrix, int **clues);

int	**ft_get_clues(int argc, char **argv);

int	**ft_gen_matrix(void)
{
	int	**matrix;
	int	i;
	int	j;

	matrix = (int **)malloc(4 * 4 * sizeof(int));
	i = 0;
	while (i < 4)
	{
		matrix[i] = malloc(4 * sizeof(int));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
	return (matrix);
}

void	ft_output_solution(int **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			write(1, (char []){matrix[i][j] + '0'}, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	**clues;
	int	**matrix;
	int	**solution;

	clues = ft_get_clues(argc, argv);
	if (!(clues))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	matrix = ft_gen_matrix();
	solution = ft_solve_puzzle(matrix, clues);
	if (!(solution))
		write(2, "Error\n", 6);
	else
		ft_output_solution(solution);
	return (0);
}
