/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:51:36 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 19:51:43 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipe(t_args *args)
{
	(void)args;

	int	fd[2];
	int	pid_child;
	int	pid_parent;

	if (pipe(fd) == 1)
		return (1);
	pid_child = fork();
	if (pid_child < 0)
		return (-1);
	if (pid_child == 0)
		ft_file_to_stdin(args, fd);
	pid_parent = fork();
	if (pid_parent < 0)
		return (-1);
	if (pid_parent == 0)
		ft_stdout_to_file(args, fd);
	waitpid(pid_child, NULL, 1);
	waitpid(pid_parent, NULL, 1);
	return (0);
}
