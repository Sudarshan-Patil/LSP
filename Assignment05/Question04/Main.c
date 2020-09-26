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
    struct stat sobj, dobj;
    int ret = 0, fddest = 0, fdsrc = 0;
    char name[256] = {'\0'};
    struct FileInfo fobj;
    char buffer[1024];

    if (argc != 3) {
        printf("Insufficient arguments \n");
        printf("Usage : Directory_name File_name");
        printf("Directory_Name : Name of directory which contains the file that we want to combine \n");
        printf("File_Name : Name of file which will contains the data of all files\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if (dp == NULL) {
        printf("Unable to open the directory i.e. : %s\n", argv[1]);
        return -1;
    }

    fddest = creat(argv[2], 0777);

    if (fddest == -1) {
        printf("Unable to create  newfile : %s\n", argv[2]);
        closedir(dp);
        return -1;
    }

    ret = stat(argv[2], &dobj);    
    printf("%s : %lld\n", argv[2], dobj.st_size);

    
    while ((dip = readdir(dp)) != NULL) {                     
        sprintf(name, "%s/%s", argv[1], dip->d_name);
        ret = stat(name, &sobj);
        if(S_ISREG(sobj.st_mode)) {    
            printf("%s : %lld\n", dip->d_name, sobj.st_size);              
            strcpy(fobj.Fname, dip->d_name);
            fobj.Fsize = sobj.st_size;            

            write(fddest, &fobj, sizeof(fobj));

            memset(&fobj, 0, sizeof(fobj)); //zeroout the memory
            fdsrc = open(name, O_RDONLY);

            while ((ret = read(fdsrc, &buffer, sizeof(buffer))) != 0) {
                write(fddest, buffer, ret);
            }

            memset(buffer, 0, sizeof(buffer));
            close(fdsrc);
        }        
    }

    closedir(dp);

    return 0;
}
