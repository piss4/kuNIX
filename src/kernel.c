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

// #include "kernel.h"

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
    } else if (strcmp (command, "touchf") == 0) {
        printf("\n[touchf:file] >  ");
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
        printf ("\nException: COULD NOT DELETE FILE...");
        }
        goto getCommand;
    } else if (strcmp (command, "inspect") == 0) {
        printf ("\n[inspect:file] >  ");
        char fname[255];
        scanf ("%s", &fname);
        int size;
        FILE *f = NULL;
        f = fopen (fname, "r");
        fseek (f, 0, SEEK_END);
        size = ftell (f);
        fseek (f, 0, SEEK_SET);
        printf ("\nFile: %s\n", fname);
        printf ("Size: %d Bytes", size);
        goto getCommand;
    } else if (strcmp (command, "read") == 0) {
        FILE *fptr;
        char filename[100], c;
        printf ("\n[read:file] >  ");
        scanf ("%s", filename);
        fptr = fopen (filename, "r");
        if (fptr == NULL)
        {
        printf ("\nException: COULD NOT OPEN FILE...");
        }
        c = fgetc (fptr);
        while (c != EOF)
        {
        printf ("%c", c);
        c = fgetc (fptr);
        }
        fclose (fptr);
        goto getCommand;
    } else if (strcmp (command, "ls") == 0) {
        printf ("\n");
        DIR *d;
        struct dirent *dir;
        d = opendir (".");
        if (d)
        {
        while ((dir = readdir (d)) != NULL)
        {
        printf ("%s\n", dir->d_name);
        }
        closedir (d);
        }
        goto getCommand;
    } else if (strcmp (command, "time") == 0) {
        time_t currtime = time (NULL);
        char *s_time = ctime (&currtime);
        s_time[strlen (s_time) - 1] = '/0';
        printf ("\n%s", s_time);
        goto getCommand;
    } else if (strcmp (command, "write") == 0) {
        printf("\n[write:file] >  ");
        char wt[255] = "NULL";
        scanf("%s", wt);
        FILE *f = fopen(wt, "w");
        if (f == NULL)
        {
        printf("\nException: COULD NOT OPEN FILE...");
        goto getCommand;
        }
        printf("\n[write:content] >  ");
        const char *text;
        scanf("%s", text);
        fprintf(f, "%s", text);
        fclose(f);
        goto getCommand;
    } else if (strcmp (command, "dir") == 0) {
        printf ("\n[dir:path] >  ");
        char dirpath[200];
        scanf ("%s", &dirpath);
        chdir (dirpath);
        goto getCommand;
    } else if (strcmp (command, "touchd") == 0) {
        printf ("\n[touchd:directory] >  ");
        char dirmake[200];
        scanf ("%s", &dirmake);
        int result = mkdir (dirmake, 0777);
        goto getCommand;
    } else if (strcmp (command, "copy") == 0) {
        FILE *fptr1, *fptr2;
        char cpname[100], c;
        printf("\n[copy:file] >  ");
        scanf("%s", cpname);
        fptr1 = fopen(cpname, "r");
        if (fptr1 == NULL)
        {
        printf("\nException: COULD NOT OPEN FILE (1)...");
        }
        printf("\n[copy:destination] >  ");
        scanf("%s", cpname);
        fptr2 = fopen(cpname, "w");
        if (fptr2 == NULL)
        {
        printf("\nException: COULD NOT OPEN FILE (2)...");
        }
        c = fgetc(fptr1);
        while (c != EOF)
        {
        fputc(c, fptr2);
        c = fgetc(fptr1);
        }
        fclose(fptr1);
        fclose(fptr2);
        goto getCommand;
    } else {
        printf("\nException: INVALID COMMAND...");
        goto getCommand;
    }
}
