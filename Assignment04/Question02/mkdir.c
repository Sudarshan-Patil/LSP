#include<stdio.h>
#include <sys/stat.h> 

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Please specify directory name");
        return 0;
    }

    if(mkdir(argv[1], 0777) == -1) {
        printf("Unable to create directory");
    } else {
        printf("Directory created successfully");
    }
}