#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "input_valid.h"
#include "free_shapes.h"



bool user_menu(list_shapes_t* list){
    int user_choice_menu = -1;
    bool exit_programm = false;
    
    while (!exit_programm) {
        user_choice_menu = ask_for_int("Greetings, welcome in your menu, press: 1(Create) 2(Edit) 3(Delete) 0(Cancel the editor)");
        if (user_choice_menu == 0 || user_choice_menu == 1 || user_choice_menu == 2 || user_choice_menu == 3) {
            switch (user_choice_menu){
            case 0:
                printf("Cancelling the editor.");
                exit_programm =true;
                break;
            case 1:
                printf("[Create] selected.\n");
                choice_shapes_and_insert(list);
                break;
            case 2:
                printf("[Edit] selected.\n");
                edit_shapes(list);
                break;
            case 3:
                printf("[Delete] selected.\n");
                display_list_shapes(list);
                int index_to_delete = ask_for_int("Enter the index of the shape to delete (1-based index):");
                if (index_to_delete > 0) {
                    if (delete_shape_at_index(list, index_to_delete)) {
                    } else {
                        printf("Error: Could not delete shape. The index %d is invalid or the list is empty.\n", index_to_delete);
                    }
                } else {
                    printf("Deletion cancelled or invalid index provided.\n");
                }
                break;
            default:
                break;
            }
        } else{
            printf("Incorrect input, please try again.\n");
        }
        
    }
    return exit_programm;
}