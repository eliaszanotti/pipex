/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:36:27 by ezanotti          #+#    #+#             */
/*   Updated: 2022/12/06 14:59:08 by ezanotti         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_pathjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s1 || !s2 || !str)
		return (NULL);
	str[0] = '\0';
	while (*s1)
		str[i++] = *s1++;
	str[i++] = '/';
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
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
	i = 0;
	good_path = NULL;
	while (paths[i])
	{
		good_path = ft_pathjoin(paths[i++], cmd);
		if (access(good_path, F_OK) == 0)
			break ;
		free(good_path);
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	free(cmd);
	return (good_path);
}
