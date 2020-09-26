
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    int fd = -1;
    char buffer[]="Welcome to marvellous";
    if (argc < 2) {
        printf("Please enter the file name\n");
        return -1;
    }
    fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("Unable to ope file name\n");
        return -1;
    }
    write(fd, buffer, sizeof(buffer));
    lseek(fd, 1024, SEEK_CUR);
    write(fd, buffer, sizeof(buffer));
    close(fd);
    return 0;
}