/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:49:23 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 11:58:33 by ezanotti         ###   ########lyon.fr   */
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

	ft_display(args);


  	//execve(args->cmd1, , NULL);
	return (0);
}
