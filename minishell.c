/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:39:06 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/27 11:37:44 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int main(void)
{
    char    *input;
    char    **args = NULL;
    int     i = 0;
    while (1)
    {
        input = readline("\033[1mMinishell \U0001F60A $\033[0m ");
        if (!input)
            break ;
        if (*input)
            add_history(input); 
        args = ft_toksplit(input);
        
        // if (built_in_command(args) == 0)
        //     execute_commad(args);
        built_in_command(args);
        free(input);
        while (args[i])
            free (args[i++]);
        free (args);            
    }
}


