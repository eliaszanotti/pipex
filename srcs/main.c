/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 19:00:56 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc != 5)
		return (ft_printf("Please enter 4 args !\n"));
	args = ft_struct_init(argv, envp);
	if (!args)
		return (0);
	
	ft_pipe(args);



	/*if (ft_file_to_stdin(args) != 0)
		return (-1);
	if (ft_stdout_to_file(args) != 0)
		return (-1);*/
	return (0);
}
