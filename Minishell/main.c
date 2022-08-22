/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:58:10 by irifarac          #+#    #+#             */
/*   Updated: 2022/08/22 13:28:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <string.h>

int	spawn(char *program, char **arg_list)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid != 0)
	{
		return (child_pid);
	}
	else
	{
		arg_list[1] = "-la";
		execvp(program, arg_list);
		write(2, "Error\n", 6);
		return (-1);
	}
	return (0);
}

int	main(void)
{
	/*char* line;

    line = readline("$");  // readline allocates space for returned string
    if(line != NULL) {
       printf("You entered: %s\n", line);
	   free(line);   // but you are responsible for freeing the space
	}*/
	int		child_status;
	char	*arg_list[] = {
		"ls",
		"-l",
		NULL
	};
	spawn("ls", arg_list);
	wait(&child_status);
	printf("%s\n", arg_list[1]);
	if (WIFEXITED(child_status))
		printf("the child process exited normally, with exit code %d\n", WEXITSTATUS(child_status));
	else
		printf("the child process exited abnormally\n");
	write(1,"done with main\n", 15);
	/*char *inpt;

    int i = 0;

    while (strcmp(inpt, "exit") != 0)
    {
                inpt = readline("$ ");
                add_history(inpt);
                printf("%s", inpt);
                printf("\n");
				free(inpt);
                ++i;
    }*/

	return (0);
}
