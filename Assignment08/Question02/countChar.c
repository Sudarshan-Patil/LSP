#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    char buffer;
    int count=0;    
    char buff[1024] = {'\0'};
    
    fd = open(argv[0], O_RDONLY);

    if (fd == -1) {
        printf("Unable to open file %s", argv[0]);
        return -1;
    }

    while ((ret=read(fd, &buffer, sizeof(buffer))) != 0) {
        if (buffer>='A' && buffer <= 'Z') {
            count++;
        }        
    }
    sprintf(buff, "Total number of capital letters are %d.\n", count);
    
    fd = open("count.txt", O_RDWR | O_CREAT | O_APPEND, 0777);

    if (fd == -1) {
        printf("Unable to create file %s", argv[0]);
        return -1;
    }

    ret = write(fd, buff, sizeof(buff));    

    if (ret == -1) {
        printf("Unable to write into file %s", argv[0]);
        return -1;
    } else {
        printf("Count of capital of file %s are written successfully", argv[0]);        
    }

    return 0;
}