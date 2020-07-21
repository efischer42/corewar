/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:20:21 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 15:25:04 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Loads the value passed in the first parameter (DIR_CODE/IND_CODE) inside
**	of the second argument (REG_CODE). If the value passed in the register was
**	equal to zero then the carry = 1, if it wasn't null then carry = 0.
*/

void		op_ld(t_vm *vm, t_cursor *cursor)
{
	int32_t		arg_1;
	int32_t		arg_2;
	uint8_t		type_of_param;

	type_of_param = param_type(vm, cursor, FIRST_PARAM);
	if (type_of_param == DIR_CODE)
		arg_1 = cursor->param[0];
	else if (type_of_param == IND_CODE)
		arg_1 = get_indirect(vm, cursor, 0);
	else
		return ;
	arg_2 = cursor->param[1];
	cursor->registries[arg_2] = arg_1;
	cursor->carry = (arg_1 == 0) ? 1 : 0;
}
