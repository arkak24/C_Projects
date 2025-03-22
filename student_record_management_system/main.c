#include <stdio.h>
#include <stdlib.h>

#include "../include/std_db.h"
#include "../include/file_handler.h"

int main(void){

      load_database_from_file();

      int choice = 0;

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

                  case 4 : save_database_to_file();
                  printf("\nThank You for using the program !!!\n\n");
                  free_list();
                  exit(0);

                  default : printf("\nInvalid input !!!\n\n");
            }
      }
}