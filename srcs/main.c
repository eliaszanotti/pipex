/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/27 16:39:33 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc != 5)
		return (1);
	args = ft_struct_init(argv, envp);
	if (!args)
		return (ft_error(1));
	if (ft_pipe(args) == 1)
		return (ft_error(1));
	ft_free_args(args);
	free(args);
	return (0);
}
