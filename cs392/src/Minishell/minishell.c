#define _POSIX_SOURCE
#include "my.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(pid_t pid) {
    kill(pid, SIGKILL);
}

void execute(char *buf) {
    pid_t pid;
    char **vect = my_str2vect(buf);
    if((pid = fork()) < 0) {
        perror("fork");
    }
    if(pid == 0) {
        if(execvp(vect[0], vect) < 0) {
            perror("exec");
        }
        exit(0);
    }
    else {
        wait(NULL);
    }
}

int main(int argc, char *argv[]) {
    int BUFSIZE  = 1024;
    int running = 1;
    int n;
    int c;
    int start;
    char *cur_dir;
    char *buf;
    buf = (char *)malloc(BUFSIZE);
    char path[1024];

    while(running) {
        c = 0;

        signal(SIGINT, sig_handler);

        cur_dir = getcwd(NULL, 0);
        my_str("MINISHELL: ");
        my_str(cur_dir);
        my_str(" $:");
        
        start = BUFSIZE;
        while((n = read(0, &buf[c*start], start-1)) == start-1) {
            if(buf[n] == '\n') 
                break;
            BUFSIZE += start;
            buf = realloc(buf, BUFSIZE);
            c++;
        }
        buf[n] = '\0';

        if(my_strcmp(buf, "exit\n") == 0) {
            exit(0);
        }
        else if(my_strcmp(buf, "help\n") == 0) {
            my_str("\ncd [directory]\nChanges the current working directory to [directory].\n\nexit\nExits the minishell.\n\nhelp\nPrints a help message listing the built in commands.\n\n");
        }
        else if(my_strncmp(buf, "cd ", 3) == 0) {
            int i;
            for(i = 3; buf[i] != ' ' && buf[i] != '\0' && buf[i] != '\n'; i++) {
                path[i-3] = buf[i];
            }
            path[i-3] = '\0';

            char* abs_path = (char*)malloc(strlen(cur_dir)+strlen(path)+2);
            my_strcpy(abs_path, cur_dir);
            my_strcat(abs_path, "/");
            my_strcat(abs_path, path);

//            for(int i = 0; i < my_strlen(abs_path); i++) {
//                if(abs_path[i] == '\n') {
//                    abs_path[i] = 0;
//                }
//            }

            if(chdir(abs_path) < 0) {
                perror("Invalid path");
                my_str(abs_path);
                my_char('\n');
            }
            free(abs_path);
        }
        else {
            execute(buf);
        }

    }
}
