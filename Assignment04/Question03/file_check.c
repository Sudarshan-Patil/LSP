#include<stdio.h>
 
int main(int argc, char *argv[]) {
   FILE *fp1, *fp2;
   int ch1, ch2;
   char fname1[40], fname2[40];
 
    if (argc != 3) {
        printf("Please enter 2 files to compare");
        return 0;
    }
 
   fp1 = fopen(argv[1], "r");
   fp2 = fopen(argv[2], "r");
 
   if (fp1 == NULL) {
      printf("Cannot open %s for reading ", fname1);
      return -1;
   } else if (fp2 == NULL) {
      printf("Cannot open %s for reading ", fname2);
      return -1;
   } else {
      ch1 = getc(fp1);
      ch2 = getc(fp2);
 
      while ((ch1 != EOF) && (ch2 != EOF) && (ch1 == ch2)) {
         ch1 = getc(fp1);
         ch2 = getc(fp2);
      }
 
      if (ch1 == ch2)
         printf("Files are identical n");
      else if (ch1 != ch2)
         printf("Files are Not identical n");
 
      fclose(fp1);
      fclose(fp2);
   }
   return 0;
}