/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 16:21:25 by hrasolof          #+#    #+#             */
/*   Updated: 2024/10/08 17:40:16 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *envp[] = { NULL };

    pid = fork();
    if (pid == 0)
    {
        if (execve(find_program_in_path(args[0]), args, envp) == -1)
        {
            perror("minishell");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("Fork failed");
        return -1;
    }
    else
        waitpid(pid, &status, 0);
    return 0;
}


// void execute_command(char **args)
// {
//     // char *argv[] = {args[1], NULL};
//     char *envp[] = { NULL };
//     if (ft_strcmp(args[0], "ls") == 0)
//         execve(find_program_in_path(args[0]), (char *const*)args[1], envp);
// }