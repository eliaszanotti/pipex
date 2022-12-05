/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdout_to_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:59:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 19:54:23 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_stdout_to_file(t_args *args, int *fd)
{
	int	fileout;

	fileout = open(args->file2, O_RDONLY | O_WRONLY | O_TRUNC, 0600);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		return (-1);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	if (execve(args->tab_cmd2[0], args->tab_cmd2, args->envp) == -1)
		return (-1);
	return (0);
}
