/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:24:57 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 15:27:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Creates a copy of the process and place the PC of the new process is :
**	PC = (ARG1 (DIR_CODE) % IDX_MOD) + POS_OF_OLD_PROCESS.
*/

t_cursor	*fork_cursor(t_cursor *cursor, int32_t address)
{
	t_cursor	*new_cursor;

	new_cursor = ft_memalloc(sizeof(t_cursor));
	if (new_cursor != NULL)
	{
		new_cursor = ft_memcpy(new_cursor, cursor, sizeof(t_cursor));
		new_cursor->pc = modulo(address, MEM_SIZE);
	}
	return (new_cursor);
}

void		op_fork(t_vm *vm, t_cursor *cursor)
{
	t_cursor	*new_cursor;
	int16_t		arg_1;
	int32_t		address;

	arg_1 = cursor->param[0];
	address = cursor->pc + (arg_1 % IDX_MOD);
	new_cursor = fork_cursor(cursor, address);
	if (new_cursor != NULL)
	{
		new_cursor->next = vm->cursor;
		vm->cursor = new_cursor;
	}
	else
	{
		clean_vm(&vm);
		exit(EXIT_FAILURE);
	}
}
