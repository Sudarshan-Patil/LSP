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

//myexe Filename
// myexe ARGV[1]
// ARGV[1] : Name of file that we want to create

struct FileInfo
{
    char Fname[256];    //FIle name
    int Fsize;          //File size
};

int main(int argc, char *argv[])
{    
    int ret = 0, fddest = 0, fdsrc = 0;    
    struct FileInfo fobj;
    char *buffer;

    if (argc != 2) {
        printf("Insufficient arguments \n");
        printf("Usage : File_name");        
        printf("File_Name : Name of file which contains the data of all files\n");
        return -1;
    }

    fdsrc = open(argv[1], O_RDONLY);

    if (fdsrc == -1) {
        printf("Unable to open the file\n");
        return -1;
    }

    mkdir("Destination", 0777);
    chdir("Destination");

    while ((ret = read(fdsrc, &fobj, sizeof(fobj))) != 0)
    {
        printf("File Name : %s Size : %d\n", fobj.Fname, fobj.Fsize);
        fddest = creat(fobj.Fname, 0777);
        if (fddest == -1) {
            printf("Unable to create file : %s\n", fobj.Fname);
            close(fdsrc);
            return -1;
        }

        //Dynamic memory for data to read
        buffer = (char*)malloc(fobj.Fsize);
        //read the data from merged file
        read(fdsrc, buffer, fobj.Fsize);
        //write the data into the newly created file
        write(fddest, buffer, fobj.Fsize);
        //free teh memory
        free(buffer);
        close(fddest);
    }

    close(fdsrc);

    return 0;
}
