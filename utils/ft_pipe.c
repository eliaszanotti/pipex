/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:51:36 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/08 16:07:10 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_get_stack_size(char ***stack)
{
	int	size;

	size = 0;
	while (stack[size])
		size++;
	return (size);
}

static int	ft_dup_and_exec(t_args *args, char **command, int fd[2], int last)
{
	char	*path;

	if (dup2(args->fdd, STDIN_FILENO) == -1)
		return (ft_error(5));
	if (!last && dup2(fd[1], STDOUT_FILENO) == -1)
		return (ft_error(5));
	close(fd[0]);
	path = ft_get_path(args, command[0]);
	if (execve(path, command, args->envp) == -1)
		return (free(path), ft_error(6));
	return (0);
}

static int	ft_execute_child(t_args *args, char **command, int last)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd))
		return (ft_error(3));
	pid = fork();
	if (pid == -1)
		return (ft_error(4));
	else if (pid == 0 && ft_dup_and_exec(args, command, fd, last))
		return (1);
	waitpid(pid, NULL, 0);
	close(fd[1]);
	args->infile = STDIN_FILENO;
	args->outfile = STDOUT_FILENO;
	args->fdd = fd[0];
	return (0);
}

int	ft_pipe(t_args *args)
{
	int	size;
	int	i;

	size = ft_get_stack_size(args->stack);
	i = -1;
	args->fdd = 0;
	if (args->infile && dup2(args->infile, STDIN_FILENO) == -1)
		return (ft_free_stack(args->stack), ft_error(5));
	if (args->outfile && dup2(args->outfile, STDOUT_FILENO) == -1)
		return (ft_free_stack(args->stack), ft_error(5));
	while (++i < size - 1)
		if (ft_execute_child(args, args->stack[i], 0))
			return (ft_free_stack(args->stack), 1);
	if (ft_execute_child(args, args->stack[i], 1))
		return (ft_free_stack(args->stack), 1);
	return (0);
}
