#include<stdio.h>
#include <dirent.h>
#include <fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    struct dirent *de;    
    char *buffer[1024];
    int fd, ret;

    DIR *dr = opendir("demo");
    
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
      printf("Could not open current directory" );
      return 0;
    }

    fd = open("demo.txt", O_RDWR | O_CREAT , 0777);

    if (fd == -1) {
        printf("Unable to create file name\n");
        return -1;
    }

    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }                
        write(fd, de->d_name, sizeof(de->d_name));
    }
    printf("Data written in file successfully");

    closedir(dr);
    return 0;
}
