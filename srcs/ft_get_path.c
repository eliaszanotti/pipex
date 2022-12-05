/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/05 18:22:16 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (!str)
		return (free(s1), NULL);
	free(s1);
	return (str);
}

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
		good_path = ft_strjoin_free(*paths++, ft_strjoin_free("/", cmd));
		if (access(good_path, F_OK) == 0)
			return (good_path);
	}
	return (NULL);
}
