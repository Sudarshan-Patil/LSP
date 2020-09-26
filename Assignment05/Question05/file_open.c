#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{    
    int fd, ret;    
    char src_folder[1024];
    char buff[1];
    int i=1;

    if (argc != 3) {
        printf("Please specify directory name");
        return 0;
    }

    if(mkdir(argv[2], 0777) == -1) {
        printf("Unable to create directory");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        printf("Unable to open file");
        return -1;
    }
    
    while ((ret = read(fd, buff, sizeof(buff))) != 0) {
        printf("%s\n", buff);
        if (strcmp(buff, "") == 0) {
            printf("END\n");
        }
    }
    
    return 0;
}
