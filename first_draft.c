/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_draft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:00:30 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 17:57:27 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int main(void)
{
    char    *input;
    char    **args = NULL;

    while (1)
    {
        input = readline("Minishell$ ");
        if (!input)
            break ;
        if (*input)
            add_history(input);
        args = strtok(input, " >|<");
        // if (built_in_command(args) == 0)
        //     execute_commad(args);
        built_in_command(args);
        free(input);
        free (args);
    }
}
