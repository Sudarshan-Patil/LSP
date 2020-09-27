/*
Application which is used to combine all regular files from the directory into one regular file.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

//myexe Directoryname
// myexe ARGV[1]
// ARGV[1] : Name of directory that we want to open

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *dip = NULL;
    struct stat sobj;
    int ret = 0, fd = 0;
    char name[256] = {'\0'};    
    char *buffer;

    if (argc != 2) {
        printf("Insufficient arguments \n");
        printf("Usage : Directory_name");
        printf("Directory_Name : Name of directory which contains the file \n");
        return -1;
    }

    dp = opendir(argv[1]);

    if (dp == NULL) {
        printf("Unable to open the directory i.e. : %s\n", argv[1]);
        return -1;
    }

    while ((dip = readdir(dp)) != NULL) {                     
        sprintf(name, "%s/%s", argv[1], dip->d_name);
        ret = stat(name, &sobj);
        if(S_ISREG(sobj.st_mode)) {  
            printf("%s : %lld\n", dip->d_name, sobj.st_size);   
            fd = open(name, O_RDWR);
            if (sobj.st_size < 1024){                
                lseek(fd, 1024-sobj.st_size, SEEK_CUR);
                write(fd, dip->d_name, sizeof(dip->d_name));                
            } else {
                ret = truncate(name, 1024);                
            }   
            close(fd);
        }        
    }

    closedir(dp);

    return 0;
}
