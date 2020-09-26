#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int fd, ret;
    char buff[20];

    if (argc != 3) {
        printf("Please specify file name and offset from which you wana read data");
        return 0;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        printf("Unable to open file");
        return -1;
    }

    lseek(fd, atoi(argv[2]), SEEK_SET);
    ret = read(fd, buff, 20);

    if (ret == -1) {
        printf("Unable to read file content");
    } else {
        printf("%s\n", buff);
    }
    return 0;
}