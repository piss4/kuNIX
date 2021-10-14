#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <signal.h>
#include <ctype.h>
#include <math.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

void main() {
    // boot
    system("clear");
    printf("kuNIX 1.0");
    sleep(2);
    system("clear");
    sleep(1);

    // main
    getCommand:
        printf("\n>  ");
        char command[255] = "NULL";
        scanf("%s", command);

    //commands
    if (strcmp (command, "echo") == 0) {
        printf("\n[echo:echo] >  ");
        char echo[255] = "NULL";
        scanf("%s", echo);
        printf("%s", echo);
        goto getCommand;
    } else if (strcmp (command, "clear") == 0) {
        system("clear");
        goto getCommand;
    } else if (strcmp (command, "touch") == 0) {
        printf("\n[touch:file] >  ");
        char fileToTouch[255];
        scanf("%s", &fileToTouch);
        FILE *fp;
        fp = fopen(fileToTouch, "a");
        fclose(fp);
        goto getCommand;
    } else if (strcmp (command, "rename") == 0) {
        char r1[255], r2[255];
        printf("\n[rename:file] >  ");
        scanf("%s", r1);
        printf("\n[rename:name] >  ");
        scanf("%s", r2);
        if (rename (r1, r2) == 0) {
        } else {
            printf("\nException: COULD NOT RENAME FILE...");
        }
        goto getCommand;
    } else if (strcmp (command, "exit") == 0) {
        system("shutdown -P now");
    } else if (strcmp (command, "shutdown") == 0) {
        system("shutdown -P now");
    } else if (strcmp (command, "del") == 0) {
        printf ("\n[del:file] >  ");
        char fileToDelete[255];
        scanf ("%s", &fileToDelete);
        int del_task = remove(fileToDelete);
        if (del_task == 0) {
        } else {
            printf ("Exception: COULD NOT DELETE FILE...");
        }
        goto getCommand;
    }
}