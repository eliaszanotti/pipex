/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:01:12 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/08 14:03:03 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("\033[31mError\033[0m");
	exit(EXIT_FAILURE);
}

int	ft_file_to_stdin(t_args *args, int *fd)
{
	int	filein;

	filein = open(args->file1, O_RDONLY);
	if (filein == -1)
		return (1);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (1);
	if (dup2(filein, STDIN_FILENO) == -1)
		return (1);
	close(fd[0]);
	if (execve(args->tab_cmd1[0], args->tab_cmd1, args->envp) == -1)
		return (1);
	return (0);
}

int	ft_stdout_to_file(t_args *args, int *fd)
{
	int	fileout;

	fileout = open(args->file2, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fileout == -1)
		return (1);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (1);
	if (dup2(fileout, STDOUT_FILENO) == -1)
		return (1);
	close(fd[1]);
	if (execve(args->tab_cmd2[0], args->tab_cmd2, args->envp) == -1)
		return (1);
	return (0);
}
