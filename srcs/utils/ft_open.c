/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <zanotti.elias@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:27:32 by elias             #+#    #+#             */
/*   Updated: 2023/02/02 14:08:04 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open(t_args *args)
{
	printf("in = %s, out = %s\n", args->infile_name, args->outfile_name);
	if (!args->heredoc)
	{
		args->infile = open(args->infile_name, O_RDONLY);
		args->outfile = open(args->outfile_name, \
			O_RDWR | O_TRUNC | O_CREAT, 0644);
	}
	else
	{
		args->outfile = open(args->outfile_name, \
			O_RDWR | O_APPEND | O_CREAT, 0644);
	}
	if (args->infile == -1)
		return (ft_error(10));
	if (args->outfile == -1)
		return (ft_error(11));
	return (0);
}
