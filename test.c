/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:43:17 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/28 14:28:32 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int execute_command(char **args)
{
    pid_t pid;
    int status;
    char *envp[] = { NULL };

    pid = fork();  // Create a new child process
    if (pid == 0)  // Child process
    {
        // The child process will run the executable
        if (execve(find_program_in_path(args[0]), args, envp) == -1)
        {
            perror("minishell");
            exit(EXIT_FAILURE);  // Exit child process on failure
        }
    }
    else if (pid < 0)  // Fork failed
    {
        perror("Fork failed");
        return -1;
    }
    else  // Parent process
        waitpid(pid, &status, 0); // Wait for the child process to finish
    return 0;
}

