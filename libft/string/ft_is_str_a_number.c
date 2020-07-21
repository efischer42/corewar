/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_a_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:29:22 by amartinod         #+#    #+#             */
/*   Updated: 2020/06/26 14:30:06 by amartinod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t		ft_is_str_a_number(char *nb_str)
{
	size_t		i;
	size_t		len;
	int8_t		ret;

	i = (nb_str[0] == '-') ? 1 : 0;
	len = ft_strlen(nb_str);
	if (len == 0)
		return (FALSE);
	while (i < len)
	{
		ret = ft_isdigit(nb_str[i]);
		if (ret == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
