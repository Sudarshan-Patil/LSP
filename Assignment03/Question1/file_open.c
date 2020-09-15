#include<stdio.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    struct dirent *de;

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
          printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
}
