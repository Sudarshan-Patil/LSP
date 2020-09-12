#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int fd;
    fd = open(argv[1], O_RDONLY);
    
    if (argc != 2) {
        printf("Please specify filename");
        return 0;
    }
    
    if (fd == -1) {
        printf("Unable to open file");
    } else {
        printf("File opened successfully");
    }
    return 0;
}
