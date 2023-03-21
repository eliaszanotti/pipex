/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:32 by elias             #+#    #+#             */
/*   Updated: 2023/03/21 15:52:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_heredoc(t_args *args)
{
	char	*line;
	int		fd[2];
	size_t	len;

	if (pipe(fd) == -1)
		return (ft_error(3));
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO, args->infile_name);
		len = ft_strlen(line) - 1;
		if (!ft_strncmp(args->infile_name, line, len) && \
			ft_strlen(args->infile_name) == len)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	args->infile = fd[0];
	close(fd[1]);
	return (0);
}

int	ft_open(t_args *args)
{
	if (!args->heredoc)
	{
		args->infile = open(args->infile_name, O_RDONLY);
		args->outfile = open(args->outfile_name, \
			O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
	else
	{
		if (ft_heredoc(args))
			return (ft_free_stack(args->stack), 1);
		args->outfile = open(args->outfile_name, \
			O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	if (args->infile == -1)
	{
		args->infile = 1;
		ft_error(10);
	}
	if (args->outfile == -1)
		return (ft_free_stack(args->stack), ft_error(11));
	return (0);
}
