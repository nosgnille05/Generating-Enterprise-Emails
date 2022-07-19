#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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
  char employee_first_name[100];
  char employee_first_initial[100];
  char employee_last_name[100];
  char employee_first_last_name[200];
  char enterprise_domain[100];
  char enterprise_directory_file[100];
  char employee_random_char[10];
  char employee_first_name_lowercase[50];
  int employee_random_num;
  int one_email_generated = 0;
  int random_nums_generated;

  //Get the Domain Name From User
  printf("What is your domain name? Ex. bing.com\n");
  scanf("%s", enterprise_domain);
  printf("\n");
  //Get the First Last Name File Name From User
  printf("What is the file path of your Directory-File?\n");
  //scanf("%s", enterprise_directory_file);
  printf("\n");

  //Open File
  fp = fopen("Student Directory Sample.txt", "r");
  if (fp == NULL)
    printf("ERROR! File not found. (EXIT)");

  //Begin Email Generation
  while(fscanf(fp,"%s", employee_first_name) != EOF){
    employee_first_initial[0] = tolower(employee_first_name[0]);
    fscanf(fp, "%s", employee_last_name);
    employee_last_name[0] = tolower(employee_last_name[0]);
    employee_first_name[0] = '\0';
    strcat(employee_first_name, employee_first_initial);
    strcat(employee_first_name, employee_last_name);
    employee_last_name[0] = '\0';
    employee_first_initial[0] = '\0';

    //Generate 3 Random Numbers for Uniqueness
    random_nums_generated = 0;
    while(random_nums_generated<3){
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
    random_nums_generated++;
    }

    //Concate "User Name" with Enterprise Domain Name
    strcat(employee_first_name, "@");
    strcat(employee_first_name, enterprise_domain);
    printf("%s\n", employee_first_name);
  one_email_generated++;
  }
  //Close File
  fclose(fp);
  
  return 0;
}