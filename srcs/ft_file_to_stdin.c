/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:47 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 19:54:32 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_to_stdin(t_args *args, int *fd)
{
	int	filein;

	filein = open(args->file1, O_RDONLY, 0777);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		return (-1);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	if (execve(args->tab_cmd1[0], args->tab_cmd1, args->envp) == -1)
		return (-1);
	return (0);
}
