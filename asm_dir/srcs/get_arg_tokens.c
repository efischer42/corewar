/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <efischer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 10:55:49 by efischer          #+#    #+#             */
/*   Updated: 2020/07/18 19:54:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static bool		check_args_string(const char *str)
{
	char	separator_char;
	size_t	i;

	i = 0;
	separator_char = 0;
	if (str[i] == SEPARATOR_CHAR)
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] == SEPARATOR_CHAR)
		{
			if (separator_char != 0)
				return (false);
			separator_char = SEPARATOR_CHAR;
		}
		else
			separator_char = 0;
		i++;
	}
	if (separator_char != 0)
		return (false);
	return (true);
}

bool			is_number(char *s)
{
	if (*s == '-')
		s++;
	if (*s == '\0')
		return (false);
	while (*s != '\0')
	{
		if (ft_isdigit(*s) == false)
			return (false);
		s++;
	}
	return (true);
}

static uint64_t	get_next_arg(t_data *data, char *arg, const enum e_token type)
{
	arg = trim_side(arg);
	if (arg[0] == DIRECT_CHAR)
		return (get_dir_arg(data, arg + 1, type));
	else if (arg[0] == 'r')
		return (get_reg_arg(data, arg + 1));
	return (get_ind_arg(data, arg));
}

size_t			get_arg_tokens(t_data *data, char *merge, t_token *op_token,
						size_t *nb_args)
{
	char		**split_arg;
	uint64_t	new_ocp;
	uint64_t	ocp;

	ocp = 0;
	if (check_args_string(merge) == false)
	{
		ft_strdel(&merge);
		exit_error(data, INVALID_ARG);
	}
	split_arg = ft_strsplit(merge, SEPARATOR_CHAR);
	while (split_arg[*nb_args] != NULL && *nb_args < MAX_ARGS_NUMBER)
	{
		new_ocp = get_next_arg(data, split_arg[*nb_args], op_token->type);
		ocp |= new_ocp << (6 - *nb_args * 2);
		(*nb_args)++;
	}
	del_array(split_arg);
	if (*nb_args == MAX_ARGS_NUMBER)
		exit_error(data, TOO_MUCH_ARG);
	return (ocp);
}
