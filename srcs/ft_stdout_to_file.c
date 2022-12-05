/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:59:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 17:55:02 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_stdout_to_file(t_args *args)
{
	int	fd;

	fd = open(args->file2, O_RDONLY | O_WRONLY | O_TRUNC, 0600);

	if (fork() == 0)
	{
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (-1);
		close(fd);
		execve(args->tab_cmd2[0], args->tab_cmd2, args->envp);
	}
	else
		close(fd);
	return (0);
}
