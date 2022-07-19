#include <stdio.h>

  //Gather Enterprises Domain Name
  //Read Employee Directory File
  //Tanner Ellingson -> telli
  //add @
  //add enterprisename
  //add .com
  //Write to Employee Emails File
  //Close File(s)

int main(void) {
  FILE *fp;
  char buff[255];
  char employee_first_name[255];
  char employee_last_name[255];
  
  fp = fopen("Student Directory Sample.txt", "r");
  if (fp == NULL)
    printf("ERROR! File not opened. (EXIT)");
  
  fscanf(fp, "%s", employee_first_name);
    printf(" First : %s\n", employee_first_name);
   
  fscanf(fp, "%s", employee_last_name);
    printf("  Last : %s\n", employee_last_name);

  printf("Concate: %s\n", strcat(employee_first_name,employee_last_name));

  
  
  
  
  
  
  
  
  
  fclose(fp);
  
  return 0;
}