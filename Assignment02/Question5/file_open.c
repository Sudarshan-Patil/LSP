#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    char buff[atoi(argv[2])];
    
    fd = open(argv[1], O_RDONLY);

    if (argc != 3) {
        printf("Please specify filename and bytes\n");
        return 0;
    }
    
    if (fd == -1) {
        printf("Unable to open file\n");
        return -1;
    } else {
        printf("File opened successfully\n");
    }
    
    ret = read(fd, buff, atoi(argv[2]));
    printf("File content is : %s\n", buff);
    
    close(fd);
    
    return 0;
}
