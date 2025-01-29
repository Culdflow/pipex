/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfeve <dfeve@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:05:15 by dfeve             #+#    #+#             */
/*   Updated: 2025/01/29 00:03:03 by dfeve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	**get_paths_str(char **env)
{
	int	i;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			return (ft_split(env[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

char	*get_path(char *name, char **env)
{
	char	**paths_tab;
	char	*path;
	int		i;

	i = 0;
	path = NULL;
	name = ft_strjoin("/", name);
	paths_tab = get_paths_str(env);
	if (!paths_tab)
		error("ENV NOT FOUND\n", 1);
	while (paths_tab && paths_tab[i])
	{
		path = ft_strjoin(paths_tab[i], name);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_tab(paths_tab);
			free(name);
			return (path);
		}
		free(path);
		i++;
	}
	free(name);
	free_tab(paths_tab);
	return (NULL);
}
