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
  //add Enterprise Domain
  //Write to Employee Emails File
  //Close File(s)

int main(void) {
  srand(time(NULL));
  FILE *fp;
  char buff[255];
  char employee_first_name[255];
  char employee_last_name[255];
  char employee_first_last_name[255];
  char enterprise_domain[50];
  char enterprise_first_last_file[50];
  char employee_random_char[10];
  int employee_random_num;

  //Get the Domain Name From User
  printf("What is your domain name? Ex. bing.com\n");
  scanf("%s", enterprise_domain);
  //Get the First Last Name File Name From User
  printf("What is the file path of your First-Last-Name-File?\n");
  scanf("%s", enterprise_first_last_file);
  
  fp = fopen("Student Directory Sample.txt", "r");
  if (fp == NULL)
    printf("ERROR! File not opened. (EXIT)");
  int i=0;
  while(fscanf(fp,"%s", employee_first_name) != EOF){
    fscanf(fp, "%s", employee_last_name);
    strcat(employee_first_name, employee_last_name);
    strcat(employee_first_last_name, employee_first_name);

    int j = 0;
    while(j<3){
      employee_random_num = rand()%10;
        if(employee_random_num == 0)
          strcat(employee_random_char, "0");
        if(employee_random_num == 1)
          strcat(employee_random_char, "1");
        if(employee_random_num == 2)
          strcat(employee_random_char, "2");
        if(employee_random_num == 3)
          strcat(employee_random_char, "3");
        if(employee_random_num == 4)
          strcat(employee_random_char, "4");
        if(employee_random_num == 5)
          strcat(employee_random_char, "5");
        if(employee_random_num == 6)
          strcat(employee_random_char, "6");
        if(employee_random_num == 7)
          strcat(employee_random_char, "7");
        if(employee_random_num == 8)
          strcat(employee_random_char, "8");
        if(employee_random_num == 9)
          strcat(employee_random_char, "9");
        strcat(employee_first_last_name, employee_random_char);
        employee_random_char[0] = '\0';
    j++;
    }
    strcat(employee_first_last_name, "@");
    strcat(employee_first_last_name, enterprise_domain);
    printf("%s\n", employee_first_last_name);
    employee_first_last_name[0] = '\0';
  i++;
  }
  fclose(fp);
  
  return 0;
}