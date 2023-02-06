/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:20 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/02 17:09:44 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_get_argv_size(char **argv)
{
	int	size;

	size = 0;
	while (argv[size])
		size++;
	return (size);
}

static int	ft_get_here_doc(t_args *args, char **argv)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		args->heredoc = 1;
	else
		args->heredoc = 0;
	return (0);
}

static int	ft_fill_stack(t_args *args, char **argv)
{
	int	size;
	int	i;
	int	i_stack;

	size = ft_get_argv_size(argv);
	args->stack = malloc(sizeof(char *) * (size + 1));
	if (!args->stack)
		return (ft_error(99));
	i = -1;
	args->infile_name = argv[++i];
	i_stack = 0;
	while (++i < size - 1)
		args->stack[i_stack++] = ft_split(argv[i], ' ');
	args->stack[i_stack] = NULL;
	return (0);
}

int	ft_struct_init(t_args *args, char **argv, char **envp)
{
	args->envp = envp;
	args->outfile_name = argv[ft_get_argv_size(argv) - 1];
	ft_get_here_doc(args, argv);
	if (args->heredoc == 1 && ft_fill_stack(args, argv + 2))
		return (1);
	if (args->heredoc == 0 && ft_fill_stack(args, argv + 1))
		return (1);
	if (ft_open(args))
		return (1);
	return (0);
}
