#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    char buff[]="Welcome to Marvellous";

    if (argc != 2) {
        printf("Please specify filename\n");
        return 0;
    }
    
    fd = creat(argv[1], 0777);
    
    ret = write(fd, buff, sizeof(buff)-1);
    
    if (ret == -1) {
        printf("Unable to write data into file\n");
    } else {
        printf("Data has been written in file\n");
    }
    
    close(fd);
    
    return 0;
}
