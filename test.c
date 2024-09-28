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

// int main(int argc, char *argv[], char *env[])
// {
//   pid_t           pid;
//   int           status;

//   if (argc > 1)
//     {
//       if ((pid = fork()) == -1)
//         {
//           perror("fork");
//           return 1;
//         }
//       /* Si pid == 0, alors on est dans le process fils. */
//       else if (pid == 0)
//         {
//           if (execve(argv[1], argv + 1, env) == -1)
//             perror("execve");
//           return 1; /* On termine le fils même si execve fail parce qu'on veut voir que le pid du pere*/
//         }
//       /* Sinon, dans le pere. */
//       else
//         wait(&status); /* Oui, il faudrait vérifier la valeur de retour... */
//     }

//   printf("My pid is: %d\n", getpid());

//   return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <elf.h>  // To parse ELF headers

void simple_execve(const char *path, char *const argv[], char *const envp[]) {
    // Step 1: Open the executable file
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        perror("Failed to open the file");
        return;
    }

    // Step 2: Get file size
    struct stat st;
    if (fstat(fd, &st) == -1) {
        perror("Failed to get file stats");
        close(fd);
        return;
    }

    // Step 3: Map the file into memory
    void *file_in_memory = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (file_in_memory == MAP_FAILED) {
        perror("Failed to map file into memory");
        close(fd);
        return;
    }
    
    // Step 4: Interpret the ELF header (assuming ELF format)
    Elf64_Ehdr *elf_header = (Elf64_Ehdr *)file_in_memory;

    // Basic ELF header validation (check magic number)
    if (elf_header->e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header->e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header->e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header->e_ident[EI_MAG3] != ELFMAG3) {
        printf("Not a valid ELF file\n");
        munmap(file_in_memory, st.st_size);
        close(fd);
        return;
    }

    // Step 5: Find the entry point
    void (*entry_point)() = (void (*)())elf_header->e_entry;

    // Step 6: Clean up the current process (Simulated)
    printf("Simulating cleanup...\n");

    // Step 7: Transfer control to the new program
    printf("Transferring control to the entry point...\n");
    entry_point();  // Jump to the entry point (hypothetical)

    // Step 8: Cleanup resources
    munmap(file_in_memory, st.st_size);
    close(fd);
}

int main() {
    // Arguments and environment variables
    char *argv[] = { "/usr/bin/ls", NULL };
    char *envp[] = { NULL };

    // Call your custom execve function
    simple_execve("/usr/bin/ls", argv, envp);

    return 0;
}
