/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2023/02/02 17:22:54 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parse_args(t_args *args)
{
	char	*path;
	int		i;

	i = 0;
	while (args->stack[i])
	{
		path = ft_get_path(args->stack[i++][0]);
		if (!path)
			return (free(path), ft_free_stack(args->stack), ft_error(7));
		free(path);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc < 5)
		return (ft_error(2));
	if (ft_struct_init(&args, argv, envp))
		return (1);
	if (ft_parse_args(&args))
		return (1);
	if (ft_pipe(&args))
		return (1);
	if (args.heredoc)
		unlink(".tmp");
	ft_free_stack(args.stack);
	return (0);
}
