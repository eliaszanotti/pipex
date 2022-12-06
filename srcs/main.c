/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/06 14:57:14 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc != 5)
		return (ft_printf("Error : please enter 4 args !\n"));
	args = ft_struct_init(argv, envp);
	if (!args)
		return (ft_printf("Error : command invalid\n"));
	if (ft_pipe(args) == -1)
		return (-1);
	ft_free_args(args);
	free(args);
	return (0);
}
