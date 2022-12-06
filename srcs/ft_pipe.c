/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:51:36 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/06 12:16:04 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(t_args *args)
{
	int	fd[2];
	int	pid_child;
	int	pid_parent;

	if (pipe(fd) == 1)
		return (1);
	pid_child = fork();
	if (pid_child < 0)
		return (-1);
	if (pid_child == 0)
		if (ft_file_to_stdin(args, fd) == -1)
			return (-1);
	pid_parent = fork();
	if (pid_parent < 0)
		return (-1);
	if (pid_parent == 0)
		if (ft_stdout_to_file(args, fd) == -1)
			return (-1);
	waitpid(pid_child, NULL, 1);
	waitpid(pid_parent, NULL, 1);
	return (0);
}
