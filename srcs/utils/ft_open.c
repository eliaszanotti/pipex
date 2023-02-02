/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:32 by elias             #+#    #+#             */
/*   Updated: 2023/02/02 14:35:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_heredoc(t_args *args)
{
	char	*line;
	int		tmp_file;

	tmp_file = open(".tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_file == -1)
		return (ft_error(11));
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(args->infile_name, line, \
			ft_strlen(args->infile_name) - 1))
			break ;
		write(tmp_file, line, ft_strlen(line));
		write(tmp_file, "\n", 1);
	}

	close(tmp_file);
	args->infile = open(".tmp", O_RDONLY);
	return (0);
}

int	ft_open(t_args *args)
{
	//printf("in = %s, out = %s\n", args->infile_name, args->outfile_name);
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
