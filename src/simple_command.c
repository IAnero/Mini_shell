/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:15:50 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 10:24:40 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int ft_cd(char **av)
{
    const char *home;

    if (av[1] == NULL)
    {
        home = getenv("HOME");
        if (home == NULL)
        {
            printf("minishell : cd : HOME not found");
            return (0);
        }
        if (chdir(home) != 0)
        {
            perror("minishell");
            return (0);
        }
    }
    else
    {
        if (chdir(av[1]) != 0)
            perror("minishell");
    }
    return (1);
}

int ft_exit()
{
    printf("exit\n");
    exit(0);
    return (0);
}

int print_env(t_env *head)
{
    printf("THE ENV FUNCTION WORKED\n");
    while (head)
    {
        printf("%s\n", head->str);
        head = head->next;
    }
    return (1);
}

int ft_export(char **av, t_env **head)
{
    if (av[1])
    {
        add_node_end(head, av[1]);
        print_env(*head);
    }
    else
        print_env(*head);
    return (1);
}

int unset_env(t_env *head, const char *str_to_remove)
{
    t_env *current = NULL;
    t_env *previous = NULL;

    current = head;

    // Traverse the list to find the node to remove
    while (current != NULL)
    {
        if (strcmp(current->str, str_to_remove) == 0)
        {
            // Node found, remove it
            if (previous == NULL)
            {
                // Node to remove is the head
                head = current->next;
            } 
            else
            {
                // Node to remove is not the head
                previous->next = current->next;
            }
            print_env(head);
            free(current->str); // Free the memory for the string
            free(current);      // Free the node itself
            return (1);            // Exit the function after removing the node
        }
        previous = current;
        current = current->next;
    }
    return (1);
}

