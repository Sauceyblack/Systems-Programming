#include "my.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

pid_t pid;
int mypipefd[2];
int mypipefd2[2];
char * retstring;
char readbuffer[100];

int main(int argc, char *argv[]) {

	if (argc == 1) {
		perror("Error: function usage requires 2 arg values: 1.Filename 2. String");
		exit(EXIT_FAILURE);
	}


	if (pipe(mypipefd) == -1) {
		perror("Error: Pipe could not execute");
		exit(EXIT_FAILURE);
	}

	pid = fork(); 
	char *retstring = my_vect2str(&argv[1]);
	if (pid < 0) {
		perror("Error: Cannot fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		if(pipe(mypipefd2) == -1) {
			perror("Error: Pipe could not execute");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid < 0) {
			perror("Error: Cannot fork");
			exit(EXIT_FAILURE);
		}
		if (pid == 0) {
			/*You're in Grandchild Process*/
            read(mypipefd2[0], readbuffer, (my_strlen(retstring)+ 1));
			my_str("Grandchild: ");
            my_str(readbuffer);
            my_str("\n");
			_exit(EXIT_SUCCESS);
		}
        else {
            close(mypipefd[1]);
        }
		/*You're in the child process*/
        close(mypipefd[1]);
        read(mypipefd[0], readbuffer, (my_strlen(retstring) + 1));
		my_str("Child: ");
        my_str(readbuffer);
        my_str("\n");
		write(mypipefd2[1], retstring, (my_strlen(retstring) + 1));
		wait(NULL);
		exit(EXIT_SUCCESS);
	} else {
		/* You're in parent process*/
        close(mypipefd[0]);
 		my_str("Parent: ");    
        my_str(retstring);
        my_str("\n");
		write(mypipefd[1], retstring, (my_strlen(retstring) + 1));
		wait(NULL);
        exit(EXIT_SUCCESS);
	}

	return 1;
}