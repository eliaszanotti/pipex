/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:47 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 17:56:30 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_file_to_stdin(t_args *args)
{
	int fd;
	
	fd = open(args->file1, O_RDONLY);
	if (fork() == 0)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			return (-1);
		close(fd);
		execve(args->tab_cmd1[0], args->tab_cmd1, args->envp);
	}	
	else
		close(fd);
	return (0);
}
