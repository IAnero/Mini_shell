/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:14:53 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 17:56:26 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

#define TOKEN_BUFFER_SIZE 64

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

// Function to check if a character is a special operator
int is_special_char(char c)
{
    return (c == '|' || c == '>' || c == '<');
}

char **tokenize_input(char *input)
{
    int bufsize = TOKEN_BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = malloc(TOKEN_BUFFER_SIZE * sizeof(char));
    int token_pos = 0;

    if (!tokens || !token)
    {
        fprintf(stderr, "minishell: allocation error\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (ft_isspace(input[i]))
        {
            if (token_pos > 0)
            {
                token[token_pos] = '\0';
                tokens[position++] = ft_strdup(token);
                token_pos = 0;
            }
        }
        else if (is_special_char(input[i]))
        {
            if (token_pos > 0)
            {
                token[token_pos] = '\0';
                tokens[position++] = ft_strdup(token);
                token_pos = 0;
            }
            tokens[position++] = strndup(&input[i], 1);
        }
        else
            token[token_pos++] = input[i];
        if (position >= bufsize)
        {
            bufsize += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "minishell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (token_pos > 0)
    {
        token[token_pos] = '\0';
        tokens[position++] = ft_strdup(token);
    }
    tokens[position] = NULL;
    free(token);
    return (tokens);
}

