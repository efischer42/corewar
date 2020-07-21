/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:56:01 by amartino          #+#    #+#             */
/*   Updated: 2020/05/19 11:05:25 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

/*
**	Return a duplicate of the given vector
*/

t_vector	*vct_dup(t_vector *vector)
{
	t_vector	*dup;

	dup = NULL;
	if (vector != NULL && vector->str != NULL)
	{
		dup = vct_new(vector->size);
		if (dup != NULL)
		{
			if ((vct_cat(dup, vector)) == FAILURE)
				vct_del(&dup);
		}
	}
	return (dup);
}
