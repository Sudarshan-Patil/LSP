#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    struct dirent *de;
    char filename[1024];
    char src_folder[1024];
    char dest_folder[1024];
    int i=1;

    DIR *dr = opendir(argv[0]);
    
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
      printf("Could not open current directory" );
      return 0;
    }

    while ((de = readdir(dr)) != NULL)
    {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }                
        sprintf(filename,"%d%s", i, ".txt");
        sprintf(src_folder,"%s%s%s", argv[0], "/", de->d_name);
        sprintf(dest_folder,"%s%s%s", argv[0], "/", filename);
        printf("%s----------------%s\n",de->d_name,dest_folder);
        rename(src_folder, dest_folder);
        ++i;
    }
    
    closedir(dr);
    return 0;
}
