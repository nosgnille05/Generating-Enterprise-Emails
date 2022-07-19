#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define frand() (rand()/(double)RAND_MAX)
#define nrand() (sqrt(-2*log(frand()))*cos(2*M_PI*frand()))

  //Gather Enterprises Domain Name
  //Read Employee Directory File
  //Tanner Ellingson -> telli
  //add @
  //add enterprisename
  //add .com
  //Write to Employee Emails File
  //Close File(s)

int main(void) {
  srand(time(NULL));
  FILE *fp;
  char buff[255];
  char employee_first_name[255];
  char employee_last_name[255];
  char employee_first_last_name[255];
  int employee_random_num;
  //char **employee_random_char[255];
  
  fp = fopen("Student Directory Sample.txt", "r");
  if (fp == NULL)
    printf("ERROR! File not opened. (EXIT)");
  int i=0;
  while(fscanf(fp,"%s", employee_first_name) != EOF){
    //printf(" First : %s\n", employee_first_name);
    fscanf(fp, "%s", employee_last_name);
    //printf("  Last : %s\n", employee_last_name);
    strcat(employee_first_name,employee_last_name);
    strcat(employee_first_last_name,employee_first_name);
    printf("%s", employee_first_last_name);
    employee_first_last_name[0] = '\0';
    
    employee_random_num = rand()%1000 + '0';
    //strcat(**employee_random_char, employee_random_num);
    printf("%d", employee_random_num);

    printf("\n");
      i++;
  }

  
  
  
  
  
  
  
  
  
  fclose(fp);
  
  return 0;
}