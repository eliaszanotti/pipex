/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/21 15:24:32 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	args;

	if (argc < 5)
		return (ft_error(2));
	if (ft_struct_init(&args, argv, envp))
		return (1);
	if (ft_pipe(&args))
		return (1);
	ft_free_stack(args.stack);
	return (0);
}
