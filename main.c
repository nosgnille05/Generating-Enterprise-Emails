#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  FILE *in;
  FILE *out;
  char employee_first_initial[10];
  char employee_first_name[100];
  char employee_last_name[100];
  char employee_last_name_first_four[10];
  char enterprise_domain[100];
  char enterprise_directory_file[100];
  char employee_random_char[10];
  int employee_random_num;
  int one_email_generated = 0;
  int random_nums_generated;

  //Get the Domain Name From User
  printf("What is your domain name? Ex. bing.com\n");
  scanf("%s", enterprise_domain);
  
  //Get the First Last Name File Name From User
  printf("\nWhat is the file path of your Directory-File?\n");
  scanf("%s", enterprise_directory_file);

  //Open Input File
  in = fopen(&enterprise_directory_file, "r");
  if (in == NULL){
    printf("We're unable to find the file/path you entered.\nPlease try again later.\n");
    return 1;
    }
  
  //Open Output File
  out = fopen("Result.txt","w");
  if (out == NULL){
    printf("Result file did not open correctly.\nPlease try again later.\n");
    return 1;
    }

  //Print Header
  printf("\nEnterprise Emails:\n\n");
  //Begin Email Generation - Scan First Name from File
  while(fscanf(in,"%s", employee_first_name) != EOF){
    //Get the First Initial and Convert to Lowercase
    employee_first_initial[0] = tolower(employee_first_name[0]);
    //Scan Last Name - Convert to Lowercase - Only take first four characters
    fscanf(in, "%s", employee_last_name);
    employee_last_name[0] = tolower(employee_last_name[0]);
    memcpy(employee_last_name_first_four,&employee_last_name[0], 4);
    //Clear employee_first_name
    employee_first_name[0] = '\0';
    //Concate first initial and last name last four
    strcat(employee_first_name, employee_first_initial);
    strcat(employee_first_name, employee_last_name_first_four);

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
        strcat(employee_first_name, employee_random_char);
        employee_random_char[0] = '\0';
    //Generate Next Random Char (3 Total)
    random_nums_generated++;
    }

    //Concate "User Name" with Enterprise Domain Name
    strcat(employee_first_name, "@");
    strcat(employee_first_name, enterprise_domain);
    
    //Write Output to File
    fprintf(out,"%s\n", employee_first_name);
    printf("%s\n", employee_first_name);
  //Move to next Directory Entry
  one_email_generated++;
  }
  //Close Input/Output Files
  fclose(in);
  fclose(out);
  
  return 0;
}