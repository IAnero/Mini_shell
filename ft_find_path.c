/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:41:44 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/28 14:55:03 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int is_executable(const char *path)
{
    struct stat buf;

    if (stat(path, &buf) == 0 && (buf.st_mode & S_IXUSR))
        return (1);
    return (0);
}

char *find_program_in_path(const char *program)
{
    char *path_env = getenv("PATH");
    char full_path[1024];
    if (!path_env)
    {
        printf("PATH environment variable not found\n");
        return (NULL);
    }
    char *path_dup = ft_strdup(path_env);
    char *dir = strtok(path_dup, ":");
    while (dir != NULL)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, program);
        if (is_executable(full_path))
        {
            free(path_dup);
            return ft_strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }
    free(path_dup);
    return (NULL);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <program_name>\n", argv[0]);
        return (1);
    }

    char *program_path = find_program_in_path(argv[1]);
    if (program_path)
    {
        printf("Program '%s' found at: %s\n", argv[1], program_path);
        free(program_path);
    }
    else
        printf("Program '%s' not found in PATH\n", argv[1]);
    return 0;
}
