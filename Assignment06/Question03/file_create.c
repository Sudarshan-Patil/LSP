#include<stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h> 

int main(int argc, char *argv[])
{
    char file_path[255];

    if (argc != 3) {
        printf("Please enter the file name and directory name");
        return 0;
    }

    if (mkdir(argv[1], 0777) != -1) {
        printf("Directory not available so creating a new directory\n");
    }

    sprintf(file_path, "%s%s%s", argv[1], "/", argv[2]);
    if (creat(file_path, 0777) == -1) {
        printf("Unable to create file %s in directory %s", argv[2], argv[1]);
    } else {
        printf("File %s successfully created in directory %s", argv[2], argv[1]);
    }
    return 0;
}