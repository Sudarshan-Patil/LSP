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

//myexe Directoryname Filename
// myexe ARGV[1] ARGV[2]
// ARGV[1] : Name of directory that we want to open
// ARGV[2] : Name of file that we want to create

struct FileInfo
{
    char Fname[256];    //FIle name
    int Fsize;          //File size
};

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *dip = NULL;
    struct stat sobj;
    int ret = 0, fd = 0, ret1 = 0;
    char name[256] = {'\0'};
    char buffer[1024];

    if (argc != 2) {
        printf("Insufficient arguments \n");
        printf("Usage : Directory_name");
        printf("Directory_Name : Name of directory which contains the files we want to scan \n");        
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
            printf("Details of File : %s\n", dip->d_name);
            printf("File Size : \t\t%d bytes\n",(int)sobj.st_size);
            printf("Number of Links : \t%d\n",(int)sobj.st_nlink);
            printf("File inode : \t\t%d\n",(int)sobj.st_ino);
            printf("File system number: \t\t%d\n",(int)sobj.st_dev);
            printf("Number of blocks allocated fior file\t\t%d\n",(int)sobj.st_blocks);
            printf("File Permissions: \t");

            printf( (S_ISDIR(sobj.st_mode)) ? "d" : "-");
            printf( (sobj.st_mode & S_IRUSR) ? "r" : "-");
            printf( (sobj.st_mode & S_IWUSR) ? "w" : "-");
            printf( (sobj.st_mode & S_IXUSR) ? "x" : "-");
            printf( (sobj.st_mode & S_IRGRP) ? "r" : "-");
            printf( (sobj.st_mode & S_IWGRP) ? "w" : "-");
            printf( (sobj.st_mode & S_IXGRP) ? "x" : "-");
            printf( (sobj.st_mode & S_IROTH) ? "r" : "-");
            printf( (sobj.st_mode & S_IWOTH) ? "w" : "-");
            printf( (sobj.st_mode & S_IXOTH) ? "x" : "-");
            printf("\n\n");
            
            fd = open(name, O_RDONLY);
            if (fd == -1) {
                printf("Unable to open file i.e. : %s\n", dip->d_name);
                return -1;
            }
            printf("File content of file %s : \n", dip->d_name);
            while((ret1=read(fd, buffer, sizeof(buffer))) != 0) {
                printf("%s", buffer);
            }
            printf("\n\n");
            close(fd);
        }  
    }

    closedir(dp);

    return 0;
}
