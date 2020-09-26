#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct Employee
{
    int empid;
    char name[255];
    char address[255];
    long salary;
};

int main(int argc, char *argv[])
{
    int fd = 0, ret = 0;
    struct Employee emp1 = {1,"AAA", "Pune", 20000};
    struct Employee emp2 = {2,"BBB", "Mumbai", 15000};
    struct Employee emp3 = {3,"CCC", "Delhi", 25000};

    if (argc != 2) {
        printf("Please enter the file name");
        return 0;
    }

    fd = creat(argv[1], 0777);
    if (fd == -1) {
        printf("Unable to open file\n");
        return -1;
    }

    ret = write(fd, &emp1, sizeof(emp1));
    ret = write(fd, &emp2, sizeof(emp2));
    ret = write(fd, &emp3, sizeof(emp3));

    if(ret == -1) {
        printf("Unable to write data into file.");
        return -1;
    } else {
        printf("Emplyee data has been written successfully");
    }
    return 0;

}