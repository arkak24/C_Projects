#include <stdio.h>
#include <stdlib.h>

#include "std_db.h"

int main(void){

      int choice;

      while(choice != 4){

            printf("1. Add a student to the database\n");
            printf("2. Delete a student from the database\n");
            printf("3. Print the database\n");
            printf("4. Exit program\n");
            printf("Enter your choice : ");
            
            scanf("%d", &choice);

            if(choice == 1){
                  add_student();
            }
            else if(choice == 2){
                  delete_student();
            }
            else if(choice == 3){
                  print_db();
            }
            else if(choice == 4){
                  exit(0);
            }
            else{
                  printf("Invalid input !!!\n");
            }
      }     
}