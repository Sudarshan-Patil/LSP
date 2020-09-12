#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
    int fd, ret, offset;
    char buff[sizeof(argv[2])];
    fd = open(argv[1], O_RDWR | O_CREAT, 0777);
    
    if (argc != 3) {
        printf("Please specify filename and string\n");
        return 0;
    }
    
    ret = write(fd, argv[2], sizeof(argv[2]));
    
    printf("%ld", sizeof(argv[2]));
    if(ret != sizeof(argv[2]))
    {
        printf("Unable to write contents\n");
    }

    lseek(fd,0,SEEK_SET);

    ret = read(fd,buff,sizeof(buff));
    printf("Written contents are : %s\n",buff);
    close(fd);
    close(ret);
    
    return 0;
}
