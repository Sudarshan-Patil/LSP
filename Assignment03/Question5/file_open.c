#include<stdio.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
    struct dirent *de;

    if (argc != 3) {
        printf("Please specify directory name and filename");
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
        if (strcmp(de->d_name, argv[2]) == 0) {
            printf("File %s is present in directory %s\n", argv[2], argv[1]);
            return 0;
        }
    }
    
    printf("File %s is not present in directory %s\n", argv[2], argv[1]);
    closedir(dr);
    return 0;
}
