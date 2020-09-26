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

int main()
{
    struct Employee emp1 = {1, "AAA", "Pune", 20000};
    struct Employee emp2 = {2, "BBB", "Mumbai", 10000};
    struct Employee emp3 = {3, "CCC", "Delhi", 15000};
    struct Employee emp4 = {4, "DDD", "Chennai", 25000};

    FILE *of;
    of= fopen ("text.txt", "w");

    fwrite (&emp1, sizeof(struct Employee), 1, of);
    fwrite (&emp2, sizeof(struct Employee), 1, of);
    fwrite (&emp3, sizeof(struct Employee), 1, of);
    fwrite (&emp4, sizeof(struct Employee), 1, of);    

    if (of == 0) {
        printf("Unable to find the file");
        fclose (of);
        return -1;
    }
}