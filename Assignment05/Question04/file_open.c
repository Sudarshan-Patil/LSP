#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    struct dirent *de;
    char buff[10];
    int fd, ret;
    int newfd;
    char src_folder[1024];

    if (argc != 2) {
        printf("Please specify directory name");
        return 0;
    }

    DIR *dr = opendir(argv[1]);
    
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
      printf("Could not open current directory" );
      return 0;
    }

    newfd = creat("demo.txt", 0777);
    while ((de = readdir(dr)) != NULL)
    {   
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }        
        sprintf(src_folder,"%s%s%s", argv[1], "/", de->d_name);

        fd = open(src_folder, O_RDONLY);        

        if (fd != -1) {
            while ((ret = read(fd, buff, sizeof(buff))) != 0) {
                if (write(newfd, buff, sizeof(buff)) == -1) {
                    printf("Error in writing into file");
                    return -1;
                }
                memset(buff, 0, sizeof(buff));
            }            
        }
    }
    printf("Data written in file successfully");
    
    closedir(dr);
    return 0;
}
