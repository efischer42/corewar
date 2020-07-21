/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vct_get_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amartinod <amartino@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 09:54:29 by amartinod         #+#    #+#             */
/*   Updated: 2020/07/18 19:02:08 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static t_vector		*get_the_file(int32_t fd, t_vector *file)
{
	t_vector		*line;
	int8_t			ret;

	ret = TRUE;
	line = NULL;
	while (ret == TRUE)
	{
		ret = vct_read_line(fd, &line);
		if (ret == TRUE)
			vct_addchar(line, '\n');
		file = vct_joinfree(&file, &line, BOTH);
		if (file == NULL)
			ret = ft_perror_failure("malloc failed", __FILE__, __LINE__);
	}
	vct_del(&line);
	if (ret == FAILURE)
		vct_del(&file);
	return (file);
}

t_vector			*vct_get_file(char *file_name)
{
	t_vector		*file;
	int32_t			fd;

	file = NULL;
	fd = open(file_name, O_RDWR);
	if (fd != FAILURE)
		file = get_the_file(fd, file);
	else
		ft_perror("can't open the file", __FILE__, __LINE__);
	return (file);
}
