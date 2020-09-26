#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
    struct dirent *de;
    char filename[100];
    struct stat fileStat;


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
        if(strcmp(".", de->d_name) == 0 || strcmp("..", de->d_name) == 0) {
            continue;
        }
        
        sprintf(filename,"%s%s%s", argv[1], "/", de->d_name);
        if(stat(filename, &fileStat) < 0) {
            continue;
        }

        if (fileStat.st_size > 100) {            
            if(unlink(filename) == 0) {
                printf("File %s has been deleted successfully\n", filename);
            } else {
                printf("Could not delete %s", filename);
            }
        }
    }
        
    closedir(dr);
    return 0;
}
