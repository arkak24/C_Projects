#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/main_menu.h"
#include "../include/std_db.h"
#include "../include/update.h"
#include "../include/file_handler.h"

void update_student(void){
      unsigned long long int roll;
      printf("Enter the roll number of the student : ");
      scanf("%lld", &roll);

      int found = 0;

      student* temp = NULL;

      if(head == NULL){
            printf("No student present in the database!\n");
      }
      else{
            temp = head;
            printf("\n");
            while(temp != NULL){
                  if(roll == (temp -> roll_no)){
                        printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                        found = 1;
                        break;
                  }
                  temp = temp -> next_address;
            }
      }

      if(found == 0){
            printf("No such student present in the database!\n\n");
      }
      else{
            while(1){
                  int choice_update;
                  printf("\n\n<----------UPDATE_MENU---------->\n\n");
                  printf("1. Update Name\n");
                  printf("2. Update Roll No.\n");
                  printf("3. Update Phone No.\n");
                  printf("4. Update CGPA\n");
                  printf("5. Update Semester\n");
                  printf("6. Back to Main Menu\n");
                  printf("7. Exit Program\n");
                  printf("Enter your choice : ");
                  scanf("%d", &choice_update);
                  printf("\n");
            
                  switch(choice_update){
                        
                        case 1 : {
                              char new_name[50];
                              // getchar();
                              while (getchar() != '\n');
                              printf("Enter New_Name : ");
                              scanf("%[^\n]", new_name);
                              strcpy(temp -> name, new_name);
                              // save_database_to_file();
                              printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                              break;
                        }
      
                        case 2 : {
                              unsigned long long int new_roll;
                              printf("Enter New_Roll_No. : ");
                              scanf("%llu", &new_roll);
                              temp -> roll_no = new_roll;
                              // save_database_to_file();
                              printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                              break;
                        }
      
                        case 3 : {
                              unsigned long long int new_ph_no;
                              printf("Enter New_Phone_No. : ");
                              scanf("%llu", &new_ph_no);
                              temp -> ph_no = new_ph_no;
                              // save_database_to_file();
                              printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                              break;
                        }
      
                        case 4 : {
                              float new_cgpa;
                              printf("Enter New_CGPA : ");
                              scanf("%f", &new_cgpa);
                              temp -> CGPA = new_cgpa;
                              // save_database_to_file();
                              printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                              break;
                        }
      
                        case 5 : {
                              int new_sem;
                              printf("Enter New_Semester : ");
                              scanf("%d", &new_sem);
                              temp -> semester = new_sem;
                              // save_database_to_file();
                              printf("%s\t%llu\t%f\t%llu\t%d\n", temp -> name, temp -> roll_no, temp -> CGPA, temp -> ph_no, temp -> semester);
                              break;
                        }
      
                        case 6 : 
                        main_menu();
                        break;
      
                        case 7 : 
                        save_database_to_file();
                        exit(0);
      
                        default : printf("Invalid input! Enter a valid choice!\n\n");
                  }      
                  save_database_to_file();
            }
      }
}