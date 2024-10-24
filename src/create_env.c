/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: herrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:19:54 by herrakot          #+#    #+#             */
/*   Updated: 2024/10/24 17:12:44 by herrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_env *create_node(const char *string) 
{
    t_env *node = NULL;

    node = malloc(sizeof(t_env));
    if (node) 
    {
        node->str = ft_strdup(string);
        node->next = NULL;
    }
    return node;
}

void add_node_end(t_env **head, const char *str)
{
    t_env *new_node = malloc(sizeof(t_env));
    new_node->str = strdup(str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    t_env *current = *head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

t_env *create_linked_list(char **str)
{
    t_env *head = NULL; 
    t_env *tail = NULL;
    t_env *new_node = NULL;

    while (*str) 
    {
        new_node = create_node(*str++);
        if (!new_node) 
            return (NULL); // Handle malloc failure
        if (!head) 
            head = new_node; // Set head if first node
        else 
            tail->next = new_node; // Link new node
        tail = new_node; // Move tail
    }
    return (head);
}

