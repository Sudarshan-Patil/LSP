#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{    
    if (argc != 3) {
        printf("Please specify filename\n");
        return 0;
    }
    
    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0)
    {
        return -1;
    }
    
    switch (mode) {
        case "O_RDONLY":
            if (fileStat.st_mode & S_IRUSR) {
                printf("File is eligible for read only permission");
            }
            break;

        case "O_WRONLY":
            if (fileStat.st_mode & S_IWUSR) {
                printf("File is eligible for write only permission");
            }
            break;

        case "O_RDWR":
            if (fileStat.st_mode & S_IRUSR & S_IRUSR) {
                printf("File is eligible for read and write permission");
            }
            break;

        default:
            printf("File dont have permission");
            break;
    }
    
    return 0;
}
