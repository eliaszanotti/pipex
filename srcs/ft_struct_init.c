/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:10:20 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_args	*ft_struct_init(char **argv, char **envp)
{
	t_args	*args;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	args->envp = envp;
	args->file1 = argv[1];
	args->cmd1 = argv[2];
	args->cmd2 = argv[3];
	args->file2 = argv[4];
	args->tab_cmd1 = ft_split(args->cmd1, ' ');
	args->tab_cmd2 = ft_split(args->cmd2, ' ');
	if (!*args->tab_cmd1 || !*args->tab_cmd2)
		return (NULL);
	args->tab_cmd1[0] = ft_get_path(args, args->tab_cmd1[0]);
	args->tab_cmd2[0] = ft_get_path(args, args->tab_cmd2[0]);
	if (!args->tab_cmd1[0] || !args->tab_cmd2[0])
		return (NULL);
	return (args);
}
