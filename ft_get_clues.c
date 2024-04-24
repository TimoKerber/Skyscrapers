/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_clues.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzipp <lzipp@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:57:27 by lzipp             #+#    #+#             */
/*   Updated: 2023/08/27 22:58:51 by lzipp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_input_is_valid(int argc, char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (len != 31 || argc != 2)
		return (0);
	return (1);
}

int	**ft_alloc_memo(void)
{
	int	**clues;
	int	i;

	clues = (int **)malloc(4 * sizeof(int *));
	i = 0;
	while (i < 4)
	{
		clues[i] = (int *)malloc(4 * sizeof(int));
		i++;
	}
	return (clues);
}

int	**ft_read_from_str(char *str)
{
	int	**clues;
	int	i;
	int	ii;

	clues = ft_alloc_memo();
	i = 0;
	ii = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4' && i % 2 == 0)
		{
			clues[i / 8][ii] = str[i] - '0';
			ii++;
		}
		else if (str[i] != ' ' && i % 2 != 0)
		{
			free (clues);
			return (NULL);
		}
		i++;
		if (ii > 3)
			ii = 0;
	}
	return (clues);
}

int	**ft_get_clues(int argc, char **argv)
{
	if (argc != 2)
		return (NULL);
	if (ft_input_is_valid(argc, argv[1]))
		return (ft_read_from_str(argv[1]));
	return (NULL);
}
