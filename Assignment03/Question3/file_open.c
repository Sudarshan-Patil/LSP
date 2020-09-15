#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>


int main(int argc, char *argv[])
{
    struct dirent *de;
    struct stat buf;
    int size;
    char filename[100];

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

    while ((de = readdir(dr)) != NULL)
    {
        printf("%s", de->d_name);
        
        if (stat(de->d_name, &buf) < 0)
        {
            printf(" - Error while retriving statistics of file\n");            
        }
        
        if (size < buf.st_size) {
            size = (int)buf.st_size;
            strcpy(filename, de->d_name);
            printf("%s", de->d_name);
        }
    }
    
    printf("The filename is %s\n", filename);
    printf("The file size is %d\n", size);
        
    closedir(dr);
    return 0;
}
