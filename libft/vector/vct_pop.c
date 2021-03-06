/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:04:17 by amartino          #+#    #+#             */
/*   Updated: 2020/05/19 11:02:00 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

/*
**	Remove a certain number of characters from the end of the string
*/

void			vct_pop(t_vector *vector, size_t len)
{
	size_t start;

	if (vector != NULL && vector->str != NULL)
	{
		start = vector->len - len;
		ft_bzero((vector->str + start), len);
		vector->len -= len;
	}
}
