/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_verif.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 22:09:59 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/27 22:42:09 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALID_VERIF_H
# define FT_VALID_VERIF_H

struct s_dim
{
	int	row;
	int	col;
};

int	ft_valid_from_left(int **matrix, struct s_dim s_pos, int clue, int val);

int	ft_valid_from_right(int **matrix, struct s_dim s_pos, int clue, int val);

int	ft_valid_from_top(int **matrix, struct s_dim s_pos, int clue, int val);

int	ft_valid_from_bottom(int **matrix, struct s_dim s_pos, int clue, int val);

#endif
