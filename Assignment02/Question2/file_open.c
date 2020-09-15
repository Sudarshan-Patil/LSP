#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], atoi(argv[2]));

    if (argc != 3) {
        printf("Please specify filename and mode");
        return 0;
    }

    if (fd == -1) {
        printf("Unable to open file");
    } else {
        printf("File opened successfully");
    }
    return 0;
}
