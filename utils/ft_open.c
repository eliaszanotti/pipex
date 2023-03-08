/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:32 by elias             #+#    #+#             */
/*   Updated: 2023/03/08 15:03:30 by ezanotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_heredoc_loop(t_args *args, int file)
{
	char	*line;
	size_t	len;

	write(1, "heredoc> ", 9);
	line = get_next_line(STDIN_FILENO, args->infile_name);
	len = ft_strlen(line) - 1;
	if (!ft_strncmp(args->infile_name, line, len) && \
		ft_strlen(args->infile_name) == len)
		return (free(line), 1);
	write(file, line, ft_strlen(line));
	return (free(line), 0);
}

static int	ft_heredoc(t_args *args)
{
	int		tmp_file;

	tmp_file = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file == -1)
		return (ft_error(11));
	while (1)
	{
		if (ft_heredoc_loop(args, tmp_file))
			break ;
	}
	close(tmp_file);
	args->infile = open(".tmp", O_RDONLY);
	if (args->infile == -1)
		return (ft_error(10));
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
			return (1);
		args->outfile = open(args->outfile_name, \
			O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	if (args->infile == -1)
		return (ft_error(10));
	if (args->outfile == -1)
		return (ft_error(11));
	return (0);
}
