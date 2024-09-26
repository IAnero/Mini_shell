/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:14:53 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/26 11:14:56 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOKEN_BUFFER_SIZE 64
#define DELIMETERS " \t\r\n\a"

// Function to tokenize the input string
char **tokenize_input(char *input) {
    int bufsize = TOKEN_BUFFER_SIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens) {
        fprintf(stderr, "minishell: allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Use strtok to split the input by spaces (or other delimiters)
    token = strtok(input, DELIMETERS);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        // If we exceed the buffer size, reallocate more space
        if (position >= bufsize) {
            bufsize += TOKEN_BUFFER_SIZE;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                fprintf(stderr, "minishell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIMETERS);
    }
    tokens[position] = NULL; // Null-terminate the array of tokens
    return tokens;
}

int main() {
    char *input = strdup("ls -la /home");
    char **tokens = tokenize_input(input);
    
    for (int i = 0; tokens[i] != NULL; i++) {
        printf("Token[%d]: %s\n", i, tokens[i]);
    }

    free(tokens);  // Remember to free the tokens after use
    free(input);   // Free the input as well
    return 0;
}
