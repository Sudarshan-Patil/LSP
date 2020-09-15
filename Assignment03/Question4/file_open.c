#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd1, fd2, ret1 = 1, ret2;
    char buff[11];
    
    if (argc != 3) {
        printf("Please specify 2 files\n");
    }
    
    fd1 = open(argv[1], O_RDONLY);
    
    fd2 = creat(argv[2], 0777);
    
    ret1 = read(fd1, buff, 10);
    if (ret1 == -1) {
        printf("Unable to read content\n");
        return -1;
    }
    
    while (ret1 != 0) {
        ret2 = write(fd2, buff, sizeof(buff));
        if (ret2 != sizeof(buff)) {
            printf("Unable to write data\n");
            return -1;
        }
        ret1 = read(fd1, buff, 10);
    }
}
