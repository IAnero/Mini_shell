/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:21:25 by hrasolof          #+#    #+#             */
/*   Updated: 2024/10/07 17:46:29 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int   execute_command(char **args)
{
    char *argv[] = {args[1], NULL};
    char *envp[] = { NULL };
    if (ft_strcmp(args[0], "ls") == 0)
        return (execve(find_program_in_path(args[0]), argv, envp));
    return (0);
}


// void execute_command(char **args)
// {
//     // char *argv[] = {args[1], NULL};
//     char *envp[] = { NULL };
//     if (ft_strcmp(args[0], "ls") == 0)
//         execve(find_program_in_path(args[0]), (char *const*)args[1], envp);
// }