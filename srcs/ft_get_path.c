/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 14:36:42 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_get_path(t_args *args, char *cmd)
{
	char	**paths;
	char	*good_path;
	int		i;

	i = 0;
	while (!ft_strnstr(args->envp[i], "PATH", 4))
		i++;
	paths = ft_split(args->envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	while (*paths)
	{
		good_path = ft_strjoin(*paths++, ft_strjoin("/", cmd));
		if (access(good_path, F_OK) == 0)
			return (good_path);
	}
	return (NULL);
}
