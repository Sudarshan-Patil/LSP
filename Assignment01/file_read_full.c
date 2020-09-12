#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int fd, rd, offset;
    char buf[20];
    fd = open(argv[1], O_RDONLY);
    
    if (argc != 2) {
        printf("Please specify filename\n");
        return 0;
    }
    
    if (fd == -1) {
        printf("Unable to open file\n");
        return 0;
    }
    
    rd = read(fd, buf, 30);
    if (rd == -1) {
        printf("Unable to read file\n");
        return 0;
    }
    
    printf("Read contents are \n %s\n",buf);
    
    offset = lseek(fd,0,SEEK_CUR);
    printf("After reading 20 bytes current byte offset is %d\n",offset);
    
    return 0;
}
