#include <stdio.h>
#include <stdlib.h>

#include "std_db.h"

int main(void){
      int choice;

      while(choice != 4){
            printf("\n\n1. Add student\n");
            printf("2. Delete student\n");
            printf("3. Display database\n");
            printf("4. Exit program\n\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);

            switch(choice){
                  case 1 : add_student();
                  break;

                  case 2 : delete_student();
                  break;

                  case 3 : print_db();
                  break;

                  case 4 : printf("\nThank You for using the program !!!\n\n");
                  free_list();
                  exit(0);

                  default : printf("\nInvalid input !!!\n\n");
            }
      }
}