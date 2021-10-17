#include <stdio.h>
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

    system("clear");
    printf("kuNIX Operating System");                   // title screen
    char command[255] = "NULL";
    sleep(2);
    system("clear");


  cmd:                                                  // goto label
    printf("\n> ");
    scanf("%s", command);                               // get and store input

    if (strcmp (command, "exit") == 0) {
        printf("\nShutting down...");
        printf("\nThank you for using kuNIX.");
        sleep(1);
        system("shutdown -P now");
    } else if (strcmp (command, "shutdown") == 0) {
        printf("\nShutting down...");
        printf("\nThank you for using kuNIX.");
        sleep(1);
        system("shutdown -P now");
    } else if (strcmp (command, "time") == 0) {
        time_t currtime = time (NULL);
        char *s_time = ctime (&currtime);
        s_time[strlen (s_time) - 1] = '/0';
        printf("%s", s_time);
    } else if (strcmp (command, "delete") == 0) {
        printf("\n[delete:file] > ");
        char fileToDelete[255];
        scanf("%s", &fileToDelete);
        int del_task = remove(fileToDelete);
        if (del_task != 0) {
            printf("Exception: FILE NOT FOUND...");
        }
    } else if (strcmp (command, "touch") == 0) {
        printf("\n[touch:file] > ");
        char fileToTouch[255];
        scanf("%s", &fileToTouch);
        FILE *fp;
        fp = fopen(fileToTouch, "a");
        fclose(fp);
    } else if (strcmp (command, "info") == 0) {
        printf("\nkuNIX Beta Version 1.0");
        sleep(1);
        printf("\nCredits:");
        sleep(1);
        printf("\nScott");
        sleep(1);
        printf("\nYoPoster");
    } else if (strcmp (command, "rename") == 0) {
        char r1[255], r2[255];
        printf("\n[rename:file] > ");
        scanf("%s", r1);
        printf("\n[rename:new] > ");
        scanf("%s", r2);
        if (rename (r1, r2) != 0) {
            printf("\nException: COULDN'T RENAME FILE...");
        }
    } else if (strcmp (command, "clear") == 0) {
        system("clear");
    } else if (strcmp (command, "inspect") == 0) {
        printf("\n[inspect:file] > ");
        char fname[255];
        scanf("%s", &fname);
        int size;
        FILE *f = NULL;
        f = fopen(fname, "r");
        fseek (f, 0, SEEK_END);
        size = ftell (f);
        fseek(f, 0, SEEK_SET);
        printf("\nFile: %s", fname);
        printf ("\nSize: %d Bytes", size);
    } else if (strcmp (command, "ls") == 0) {
        printf ("\n");
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            while ((dir = readdir (d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir (d);
        }
    } else if (strcmp (command, "read") == 0) {
        FILE *fptr;
        char filename[100], c;
        printf ("\n[read:file] > ");
        scanf ("%s", filename);
        fptr = fopen (filename, "r");
        if (fptr == NULL) {
            printf ("\nException: COULDN'T OPEN FILE...");
        }
        c = fgetc (fptr);
        while (c != EOF) {
            printf ("%c", c);
            c = fgetc (fptr);
        }
        fclose (fptr);
    } else if (strcmp (command, "touchdir") == 0) {
        printf("\n[touchdir:directory] > ");
        char dirmake[200];
        scanf("%s", &dirmake);
        int result = mkdir(dirmake, 0777);
    } else if (strcmp (command, "chdir") == 0) {
        printf("\n[chdir:path] > ");
        char dirpath[200];
        scanf("%s", &dirpath);
        chdir(dirpath);
    } else if (strcmp (command, "write") == 0) {
        printf("\n[write:file] > ");
        char fileWrite[255];
        scanf("%s", fileWrite);
        FILE *f = fopen(fileWrite, "w");
        if (f == NULL) {
            printf("\nException: COULDN'T WRITE TO FILE...");
        }
        printf("\n[write:content] > ");
        char text[99999];
        scanf("%s", text);
        fprintf(f, "%s", text);
        fclose(f);
    } else {
        printf("\nException: COMMAND INVALID...");
    }


    goto cmd;

}