/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 15:54:38 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <unistd.h>

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	if (argc != 5)
		return ft_printf("Please enter 4 args !\n");
	args = ft_struct_init(argv, envp);
	if (!args)
		return (0);

	ft_file_to_stdin(args);


  	//execve(args->cmd1, , NULL);
	return (0);
}
