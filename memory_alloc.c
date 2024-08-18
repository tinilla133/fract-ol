/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvizcaya <fvizcaya@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:47:38 by fvizcaya          #+#    #+#             */
/*   Updated: 2024/08/09 15:19:54 by fvizcaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 *		Allocates memory for a matrix of integers of dimension 
 *		size_t dim_1 x size_t dim2. Returns a pointer to the beginning of 
 *		allocated memory. 
 */

int	**ft_mem_alloc(size_t dim1, size_t dim2)
{
	int		**ptr_array;
	size_t	i;

	ptr_array = (int **) malloc (dim1 * sizeof (int *));
	if (!ptr_array)
		return (NULL);
	i = 0;
	while (i < dim1)
	{
		ptr_array[i] = (int *) malloc (dim2 * sizeof (int));
		if (!ptr_array[i])
			return (ft_mem_free((void **) ptr_array, dim1), NULL);
		i++;
	}
	return (ptr_array);
}

/*
 *		Procedure. Frees memory of a matrix that receives as void **mem of 
 *		size_t dim1 rows. 
 */

void	ft_mem_free(void **mem, size_t dim1)
{
	size_t	i;

	i = 0;
	while (i < dim1)
		free(mem[i++]);
	free(mem);
}
