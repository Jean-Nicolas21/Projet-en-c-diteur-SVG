#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "input_valid.h"

bool user_choice_start(viewbox_t *viewbox){
    int user_choice;
    bool is_user_input_valid = false;
    
    while (!is_user_input_valid) {
        user_choice = ask_for_int("Would you like to start your viewbox?Please press 1(yes) or 0(no): ");
        if (user_choice == 0 || user_choice == 1) {
            is_user_input_valid = true;
        }
    }
    
    if (user_choice == 1){
        create_viewbox();
        viewbox->start_x = ask_for_int("Please enter your start_x for your viewbox: ");
        viewbox->start_y = ask_for_int("Please enter your start_y for your viewbox: ");
        viewbox->end_x = ask_for_int("Please enter your end_x for your viewbox: ");
        viewbox->end_y = ask_for_int("Please enter your end_y for your viewbox: ");
        
    } else if (user_choice == 0){
        printf("Cancelling the editor.");
        return true;
    } 
    return false;
}
