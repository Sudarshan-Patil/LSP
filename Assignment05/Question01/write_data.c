#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

struct Employee
{
    int empid;
    char name[255];
    char address[255];
    long salary;
};

int main(int argc, char *argv[])
{
    FILE *fd;
    struct Employee emp;
    fd = fopen (argv[1], "r");
    if (fd == NULL) {
        printf("\nError to open the file\n");
        return -1;
    }
    while(fread(&emp, sizeof(struct Employee), 1, fd)) {
        printf("Emp id = %d name = %s Address = %s Salary = %d\n", emp.empid, emp.name, emp.address, emp.salary);
    }
    
    fclose (fd);
}