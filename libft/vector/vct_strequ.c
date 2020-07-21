/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_strequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartino <amartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:50:29 by amartino          #+#    #+#             */
/*   Updated: 2020/05/19 11:09:29 by francis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

uint8_t		vct_strequ(t_vector const *vector, char const *str)
{
	size_t	i;

	i = 0;
	if (vector == NULL || vector->str == NULL || str == NULL)
		return (FALSE);
	while (vector->str[i] || str[i])
	{
		if (vector->str[i] != str[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}
