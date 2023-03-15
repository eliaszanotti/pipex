/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:51:08 by ezanotti          #+#    #+#             */
/*   Updated: 2023/03/15 15:47:11 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_args
{
	char	***stack;
	char	**envp;
	char	*infile_name;
	char	*outfile_name;
	pid_t	*pid_tab;
	int		*close_tab;
	int		infile;
	int		outfile;
	int		fdd;
	int		heredoc;
}	t_args;

void	ft_putstr(char *str);
int		ft_error(int error_code);
int		ft_open(t_args *args);

int		ft_struct_init(t_args *args, char **argv, char **envp);
int		ft_pipe(t_args *args);
char	*ft_get_path(t_args *args, char *cmd);

void	ft_free_str(char **str);
void	ft_free_stack(char ***stack);

int		ft_add_pid(t_args *args, pid_t pid);
int		ft_wait_and_close(t_args *args);

int		ft_get_stack_size(char ***stack);

#endif
