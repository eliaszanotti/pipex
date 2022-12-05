/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:09:47 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 14:42:48 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_display(t_args *args)
{

	printf("%s, %s\n", args->tab_cmd1[0], args->tab_cmd2[0]);


	execve(args->tab_cmd1[0], args->tab_cmd1, args->envp);
	perror("execve");
	execve(args->tab_cmd2[0], args->tab_cmd2, NULL);
	perror("execve");
}
