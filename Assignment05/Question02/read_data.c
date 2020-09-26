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
    int fd=0, ret = 0;
    struct Employee emp;
    if (argc != 2) {
        printf("Please enter teh file name");
        return 0;
    }

    fd = open(argv[1], O_RDONLY);
    printf("File content is : \n");
    while((ret = read(fd, &emp, sizeof(emp))) != 0)
    {
        printf("Emp id : %d, Name : %s, Address : %s, Salary : %ld\n", emp.empid, emp.name, emp.address, emp.salary);
    }
}