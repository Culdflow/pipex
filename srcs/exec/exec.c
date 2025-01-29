/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 19:42:58 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/29 00:03:02 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	exec(char *command, char **env)
{
	char	*exec_path;
	char	**cmd;

	cmd = ft_split(command, ' ');
	exec_path = get_path(cmd[0], env);
	if (execve(exec_path, cmd, env) == -1)
	{
		free_tab(cmd);
		error("could not find command\n", 127);
	}
}