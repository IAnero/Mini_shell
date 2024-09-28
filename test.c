/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 11:43:17 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/28 11:53:54 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

// int main(int argc, char *argv[], char *env[])
// {
//   if (argc > 1)
//     if (execve(argv[1], argv + 1, env) == -1)
//       perror("execve");

//   printf("My pid is: %d\n", getpid());

//   return 0;
// }

// int main(void)
// {
//   pid_t          pid;

//   if ((pid = fork()) == -1)
//     {
//       perror("fork");
//       return 1;
//     }
//   else if (pid == 0)
//     printf("Je suis le fils, et mon pid = %d\n", getpid());
//   else
//     printf("Je suis le pere, et mon pid = %d. Le pid de mon fils = %d\n", getpid(), pid);

//   return 0;
// }

int main(int argc, char *argv[], char *env[])
{
  pid_t           pid;
  int           status;

  if (argc > 1)
    {
      if ((pid = fork()) == -1)
        {
          perror("fork");
          return 1;
        }
      /* Si pid == 0, alors on est dans le process fils. */
      else if (pid == 0)
        {
          if (execve(argv[1], argv + 1, env) == -1)
            perror("execve");
          return 1; /* On termine le fils même si execve fail parce qu'on veut voir que le pid du pere*/
        }
      /* Sinon, dans le pere. */
      else
        wait(&status); /* Oui, il faudrait vérifier la valeur de retour... */
    }

  printf("My pid is: %d\n", getpid());

  return 0;
}