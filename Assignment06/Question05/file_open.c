#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    char *buffer;
    
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
    
    buffer = (char*)malloc(atoi(argv[2]));                
    read(fd, buffer, sizeof(buffer));    
    close(fd);
    remove(argv[1]);                
    fd = creat(argv[1], 0777);
    write(fd, buffer, sizeof(buffer));

    printf("File content is : %s\n", buffer);
    
    close(fd);
    
    return 0;
}
