#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct dirent *de;
    char src_folder[1024];
    char dest_folder[1024];
    
    if (argc != 3) {
        printf("Please specify source directory name and destination directory name");
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
        sprintf(src_folder,"%s%s%s", argv[1], "/", de->d_name);
        sprintf(dest_folder,"%s%s%s", argv[2], "/", de->d_name);
        printf("%s----------------%s\n",de->d_name,dest_folder);
        rename(src_folder, dest_folder);
    }
    
    closedir(dr);
    return 0;
}
