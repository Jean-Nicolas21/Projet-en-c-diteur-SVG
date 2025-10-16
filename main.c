#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "shapes.h"
#include "start.h"
#include "input_valid.h"
#include "free_shapes.h"
#include "menu.h"

int main(){
    viewbox_t* user_viewbox = create_viewbox();
    list_shapes_t* list = create_list_shapes();
    
    if (user_choice_start(user_viewbox)) {
        return EXIT_FAILURE; 
    }

    FILE* write_file = fopen("test.svg", "w");
    fprintf(write_file, "<svg viewBox='%d %d %d %d' xmlns='http://www.w3.org/2000/svg'>\n", user_viewbox->start_x, user_viewbox->start_y, user_viewbox->end_x, user_viewbox->end_y);
    user_menu(list);
    fprintf(write_file, "</svg>");
    fclose(write_file);
    return 0;
}

