#include<stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    struct dirent *de;
    struct stat buf;

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
        
        if (S_ISREG(buf.st_mode))
        {
            printf(" - Regular file");
        }
        else if (S_ISDIR(buf.st_mode))
        {
            printf(" - Directory");
        }
        else if (S_ISCHR(buf.st_mode))
        {
            printf(" - Character special fiel");
        }
        else if (S_ISBLK(buf.st_mode))
        {
            printf(" - Block special file");
        }
        else if (S_ISFIFO(buf.st_mode))
        {
            printf(" - FIFO");
        }
        else if (S_ISLNK(buf.st_mode))
        {
            printf(" - Symbolic link");
        }
        else if (S_ISSOCK(buf.st_mode))
        {
            printf(" - Socket");
        }
        else
        {
            printf(" - File type is unknown");
        }
        printf("\n");
        
    }
        

    closedir(dr);
    return 0;
}
