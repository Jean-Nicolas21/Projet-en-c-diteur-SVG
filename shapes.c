#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "input_valid.h"



viewbox_t* create_viewbox(void){
    viewbox_t* viewbox = malloc(sizeof(viewbox_t));
    viewbox->start_x = 0;
    viewbox->start_y = 0;
    viewbox->end_x = 0;
    viewbox->end_y = 0;
    return viewbox;
}

void free_viewbox(viewbox_t* viewbox){
    free(viewbox);
}

rectangle_t* create_rectangle(void){
    rectangle_t* rectangle = malloc(sizeof(rectangle_t));

    if (rectangle == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the rectangle.\n");
        return NULL; 
    }

    rectangle->x = 0;
    rectangle->y = 0;
    rectangle->width = 0;
    rectangle->height = 0;
    return rectangle;
}

void free_rectangle(rectangle_t* rectangle){
    free(rectangle);
}

square_t* create_square(void){
    square_t* square = malloc(sizeof(square_t*));

    if (square == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the square.\n");
        return NULL; 
    }

    square->x = 0;
    square->y = 0;
    square->width = 0;
    square->height = square->width;
    return square;
}

void free_square(square_t* square){
    free(square);
}

ellipse_t* create_ellipse(void){
    ellipse_t* ellipse = malloc(sizeof(ellipse_t));

    if (ellipse == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the ellipse.\n");
        return NULL; 
    }

    ellipse->cx = 0;
    ellipse->cy = 0;
    ellipse->rx = 0;
    ellipse->ry = 0;
    return ellipse;
}

void free_ellipse(ellipse_t* ellipse){
    free(ellipse);
}

circle_t* create_circle(void){
    circle_t* circle = malloc(sizeof(circle_t));

    if (circle == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the circle.\n");
        return NULL; 
    }

    circle->cx = 0;
    circle->cy = 0;
    circle->rx = 0;
    circle->ry = circle->rx;
    return circle;
}

void free_circle(circle_t* circle){
    free(circle);
}

line_t* create_line(void){
    line_t* line = malloc(sizeof(line_t));

    if (line == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the line.\n");
        return NULL; 
    }

    line->x_1 = 0;
    line->y_1 = 0;
    line->x_2 = 0;
    line->y_2 = 0;
    return line;
}

void free_line(line_t* line){
    free(line);
}

void free_point_list(points_t* head) {
    points_t* current = head;
    points_t* next;
    
    while (current != NULL) {
        next = current->next; 
        free(current);        
        current = next;       
    }
}

polyline_t* create_polyline(void) {
    polyline_t* polyline = malloc(sizeof(polyline_t));
    if (polyline == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the polyline.\n");
        return NULL;
    }
    polyline->head = NULL;
    return polyline;
}

void free_polyline(polyline_t* polyline) {
    if (polyline == NULL) return;
    free_point_list(polyline->head);
    free(polyline);
}

int add_point_to_polyline(polyline_t* polyline, int x, int y) {
    points_t* new_point = malloc(sizeof(points_t));
    if (new_point == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for new point.\n");
        return 0;
    }
    new_point->x = x;
    new_point->y = y;
    new_point->next = NULL; 
    if (polyline->head == NULL) {
        polyline->head = new_point;
    } else {
        points_t* current = polyline->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_point;
    }
    return 1;
}

size_t count_polyline_points(const polyline_t* polyline) {
    if (polyline == NULL) {
        return 0;
    }
    size_t count = 0;
    points_t* current = polyline->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void choice_shapes_and_insert(list_shapes_t* list) {
    int user_choice = 0;
    form_t* newform = NULL;
    while (user_choice < 1 || user_choice > 6) {
        user_choice = ask_for_int("Please select a form you want to for your viewbox, press: 1(rectangle), 2(ellipse), 3(line), 4(square), 5(circle), 6(polyline).\nYour choice: ");
        if (user_choice < 1 || user_choice > 6) {
            printf("Incorrect input, please select 1, 2, 3, 4, 5 or 6.\n");
        }
    }
    newform = malloc(sizeof(form_t));
    if (newform == NULL) {
        fprintf(stderr, "Error: failing to allocate memory.\n");
        return;
    }
    switch (user_choice) {
    case RECTANGLE:
        printf("[Rectangle] selected.\n");
        newform->type = RECTANGLE;
        newform->data.rectangle = create_rectangle();
        newform->data.rectangle->x = ask_for_int("Please enter your starting x for your rectangle: ");
        newform->data.rectangle->y = ask_for_int("Please enter your starting y for your rectangle: ");
        newform->data.rectangle->width = ask_for_int("Please enter the width of your rectangle: ");
        newform->data.rectangle->height = ask_for_int("Please enter the height of your rectangle: ");
        printf("You create a rectangle with the following parameters: x:%d y:%d width:%d height:%d.\n", newform->data.rectangle->x, newform->data.rectangle->y, newform->data.rectangle->width, newform->data.rectangle->height);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    case ELLIPSE:
        printf("[Ellipse] selected.\n");
        newform->type = ELLIPSE;
        newform->data.ellipse = create_ellipse();
        newform->data.ellipse->cx = ask_for_int("Please enter your starting x for your ellipse: ");
        newform->data.ellipse->cy = ask_for_int("Please enter your starting y for your ellipse: ");
        newform->data.ellipse->rx = ask_for_int("Please enter the x radius of your ellipse: ");
        newform->data.ellipse->ry = ask_for_int("Please enter the y radius of your ellipse: ");
        printf("You create an ellipse with the following parameters: x:%d y:%d rx:%d ry:%d.\n", newform->data.ellipse->cx, newform->data.ellipse->cy, newform->data.ellipse->rx, newform->data.ellipse->ry);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    case LINE:
        printf("[Line] selected.\n");
        newform->type = LINE;
        newform->data.line = create_line();
        newform->data.line->x_1 = ask_for_int("Please enter your x_1 for your line: ");
        newform->data.line->y_1 = ask_for_int("Please enter your y_1 y for your line: ");
        newform->data.line->x_2 = ask_for_int("Please enter the x_2 of your line: ");
        newform->data.line->y_2 = ask_for_int("Please enter the y_2 of your line: ");
        printf("You create a line with the following parameters: x1:%d y1:%d x2:%d y2:%d.\n", newform->data.line->x_1, newform->data.line->y_1, newform->data.line->x_2, newform->data.line->y_2);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    case SQUARE:
        printf("[Square] selected.\n");
        newform->type = SQUARE;
        newform->data.square = create_square();
        newform->data.square->x = ask_for_int("Please enter your starting x for your square: ");
        newform->data.square->y = ask_for_int("Please enter your starting y for your square: ");
        newform->data.square->width = ask_for_int("Please enter the width of your square: ");
        newform->data.square->height = newform->data.square->width;
        printf("You create a square with the following parameters: x:%d y:%d width:%d height:%d.\n", newform->data.square->x, newform->data.square->y, newform->data.square->width, newform->data.square->height);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    case CIRCLE:
        printf("[Circle] selected.\n");
        newform->type = ELLIPSE;
        newform->data.circle = create_circle();
        newform->data.circle->cx = ask_for_int("Please enter your starting x for your circle: ");
        newform->data.circle->cy = ask_for_int("Please enter your starting y for your circle: ");
        newform->data.circle->rx = ask_for_int("Please enter the x radius of your circle: ");
        newform->data.circle->ry = newform->data.circle->rx;
        printf("You create a circle with the following parameters: x:%d y:%d rx:%d ry:%d.\n", newform->data.circle->cx, newform->data.circle->cy, newform->data.circle->rx, newform->data.circle->ry);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    case POLYLINE:
        printf("[Polyline] selected.\n");
        newform->type = POLYLINE;
        newform->data.polyline = create_polyline();
        int x, y;
        int count = 1;
        while (1) {
            printf("--- Point %d ---\n", count);
            x = ask_for_int("Please enter x (or -1 to finish): ");
            if (x < 0) break;
            y = ask_for_int("Please enter y: ");
            if (!add_point_to_polyline(newform->data.polyline, x, y)) {
                fprintf(stderr, "Failed to add point, stopping input.\n");
                break;
            }
            count++;
        }
        size_t final_count = count_polyline_points(newform->data.polyline);
        printf("Polyline created with %lu points.\n", (unsigned long)final_count);
        insert_form_head(list, newform);
        display_list_shapes(list);
        break;
    }
}


list_shapes_t* create_list_shapes(){
    list_shapes_t* list = malloc(sizeof(list_shapes_t));
    list->head = NULL;
    return list;
}

void insert_form_head(list_shapes_t* list, form_t* new_form){
    if (list == NULL) {
        fprintf(stderr, "Error: Try of inserting a NULL list.\n");
        return;
    }
    node_t* newnode = malloc(sizeof(node_t));
    if (newnode == NULL) {
        fprintf(stderr, "Error: failing to allocate memory for the node. The shape has not been implemented.\n");
        return;
    }
    newnode->data_form = new_form;
    newnode->next = list->head;
    list->head = newnode;
}

void display_list_shapes(list_shapes_t* list) {
    node_t* current = list->head;
    int count = 1;
    printf("-----Your list of shapes-----\n");
    if (list == NULL || list->head == NULL) {
        printf("The list is empty.\n");
        printf("-----------------------------\n");
        return;
    }
    while (current != NULL) {
        form_t* form = current->data_form;
        if (form == NULL) {
             printf("Shapes %d : Type of shapes -> [ERROR: The node contain NULL shape.]\n", count);
        } else {
            printf("Shapes %d : Type of shapes -> ", count);
            
            switch (form->type) {
            case RECTANGLE:
                if (form->data.rectangle) {
                    printf("RECTANGLE: [x:%d y:%d width:%d height:%d]\n", 
                           form->data.rectangle->x, 
                           form->data.rectangle->y, 
                           form->data.rectangle->width, 
                           form->data.rectangle->height);
                } else {
                    printf("RECTANGLE: [ERROR: Data pointer from the rectangle is NULL]\n");
                }
                break; 
            case ELLIPSE:
                if (form->data.ellipse) {
                    printf("ELLIPSE: [cx:%d cy:%d rx:%d ry:%d]\n", 
                           form->data.ellipse->cx, 
                           form->data.ellipse->cy, 
                           form->data.ellipse->rx, 
                           form->data.ellipse->ry);
                } else {
                    printf("ELLIPSE: [ERROR: Data pointer from the ellipse is NULL]\n");
                }
                break;  
            case LINE:
                if (form->data.line) {
                    printf("LINE: [x1:%d y1:%d x2:%d y2:%d]\n", 
                           form->data.line->x_1, 
                           form->data.line->y_1, 
                           form->data.line->x_2, 
                           form->data.line->y_2);
                } else {
                    printf("LINE: [ERROR: Data pointer from the line is NULL]\n");
                }
                break;
            case SQUARE:
                if (form->data.square) {
                    printf("SQUARE: [x:%d y:%d width:%d height:%d]\n", 
                           form->data.square->x, 
                           form->data.square->y, 
                           form->data.square->width, 
                           form->data.square->height);
                } else {
                    printf("SQUARE: [ERROR: Data pointer from the square is NULL]\n");
                }
                break;
            case CIRCLE:
                if (form->data.circle) {
                    printf("CIRCLE: [cx:%d cy:%d rx:%d ry:%d]\n", 
                           form->data.circle->cx, 
                           form->data.circle->cy, 
                           form->data.circle->rx, 
                           form->data.circle->ry);
                } else {
                    printf("CIRCLE: [ERROR: Data pointer from the circle is NULL]\n");
                }
                break;
            case POLYLINE:
                polyline_t* poly = form->data.polyline;
                if (poly && poly->head) {
                    size_t point_count = count_polyline_points(poly);
                    printf("POLYLINE: [%lu points : ", (unsigned long)point_count);
                    points_t* current_point = poly->head;
                    size_t i = 0;
                    while (current_point != NULL && i < 3) {
                        printf("(%d,%d)%s", 
                               current_point->x, 
                               current_point->y, 
                               (current_point->next != NULL && i < 2) ? ", " : "");
                        current_point = current_point->next;
                        i++;
                    }
                    if (point_count > 3) printf(", ...");
                    printf("]\n");
                } else {
                    printf("POLYLINE: [ERROR: Data pointer from the polyline is NULL or there is no points]\n");
                }
                break;
            default:
                printf("[TYPE OF SHAPE UNKNOWN : %d]\n", form->type);
                break;
            }
        }
        current = current->next;
        count++;
    }
}

node_t* get_shapes_index(list_shapes_t* list, int index){
    if (!list){
        return NULL;
    }
    node_t* current = list->head;
    int count = 1;
    while (current != NULL){
        if (count == index){
            return current;
        }
        current = current->next;
        count++;
    }
    return NULL;
}

points_t* get_point_by_index(polyline_t* polyline, int index) {
    if (polyline == NULL || index <= 0) return NULL;
    points_t* current = polyline->head;
    int current_index = 1;
    while (current != NULL) {
        if (current_index == index) {
            return current;
        }
        current = current->next;
        current_index++;
    }
    return NULL;
}

int modify_point_at_index(polyline_t* polyline, int index, int x, int y) {
    points_t* target = get_point_by_index(polyline, index);
    if (target == NULL) {
        return 0;
    }
    target->x = x;
    target->y = y;
    return 1;
}

int delete_point_at_index(polyline_t* polyline, int index) {
    if (polyline == NULL || index <= 0) return 0;

    points_t* current = polyline->head;
    points_t* temp = NULL;

    if (index == 1) {
        if (current == NULL) return 0;
        polyline->head = current->next;
        free(current);
        return 1;
    }
    int current_index = 1;
    while (current != NULL && current_index < index - 1) {
        current = current->next;
        current_index++;
    }
    if (current == NULL || current->next == NULL) {
        return 0;
    }
    temp = current->next;
    current->next = temp->next;
    free(temp);
    return 1;
}

void edit_shapes(list_shapes_t* list){
    if (list == NULL || list->head == NULL){
        printf("Your list of shapes is empty so you have nothing to edit.");
        return;
    }
    display_list_shapes(list);

    int index_edit =0;
    node_t* shapes_edit = NULL;

    do {
        index_edit = ask_for_int("Please select the shapes you want to edit by pressing the corresponding index: ");
        shapes_edit = get_shapes_index(list, index_edit);
        if (shapes_edit == NULL){
            printf("Wrong input, please try again.");
        }
    } while (shapes_edit == NULL);
    
    form_t* form_edit = shapes_edit->data_form;

    printf("Starting editing process.\n");

    switch (form_edit->type) {
    case RECTANGLE:
        edit_rectangle_parameters(form_edit->data.rectangle);
        break;
    case ELLIPSE:
        edit_ellipse_parameters(form_edit->data.ellipse);
        break;
    case LINE:
        edit_line_parameters(form_edit->data.line);
        break;
    case SQUARE:
        edit_square_parameters(form_edit->data.square);
        break;
    case CIRCLE:
        edit_circle_parameters(form_edit->data.circle);
        break;
    case POLYLINE:
        edit_polyline_parameters(form_edit->data.polyline);
        break;
    default:
        printf("Error: unknown shapes.");
        break;
    }
    printf("\n--- List of shapes update ---\n");
    display_list_shapes(list);
    printf("--------------------------------\n");
}

void edit_rectangle_parameters(rectangle_t* rectangle){
    printf("--- Editing RECTANGLE ---\n");
    printf("Current value of x: %d", rectangle->x);
    rectangle->x = ask_for_int("New value for x: ");
    printf("Current value of y: %d", rectangle->y);
    rectangle->y = ask_for_int("New value for y: ");
    printf("Current value of the width: %d", rectangle->width);
    rectangle->width = ask_for_int("New value for the width: ");
    printf("Current value of the height: %d", rectangle->height);
    rectangle->height = ask_for_int("New value for the height: ");
    printf("RECTANGLE update : x:%d y:%d width:%d height:%d.\n", rectangle->x, rectangle->y, rectangle->width, rectangle->height);
}

void edit_ellipse_parameters(ellipse_t* ellipse){
    printf("--- Editing ELLIPSE ---\n");
    printf("Current value of cx: %d", ellipse->cx);
    ellipse->cx = ask_for_int("New value for cx: ");
    printf("Current value of cy: %d", ellipse->cy);
    ellipse->cy = ask_for_int("New value for cy: ");
    printf("Current value of rx: %d", ellipse->rx);
    ellipse->rx = ask_for_int("New value for rx: ");
    printf("Current value of ry: %d", ellipse->ry);
    ellipse->ry = ask_for_int("New value for ry: ");
    printf("ELLIPSE update : cx:%d cy:%d rx:%d ry:%d.\n", ellipse->cx, ellipse->cy, ellipse->rx, ellipse->ry);
}

void edit_line_parameters(line_t* line){
    printf("--- Editing LINE ---\n");
    printf("Current value for x1: %d", line->x_1);
    line->x_1 = ask_for_int("New value for x1: ");
    printf("Current value for y1: %d", line->y_1);
    line->y_1 = ask_for_int("New value for y1: ");
    printf("Current value for x2: %d", line->x_2);
    line->x_2 = ask_for_int("New value for x2: ");
    printf("Current value for y2: %d", line->y_2);
    line->y_2 = ask_for_int("New value for y2: ");
    printf("LINE update : x1:%d y1:%d x2:%d y2:%d.\n", line->x_1, line->y_1, line->x_2, line->y_2);
}

void edit_square_parameters(square_t* square){
    printf("--- Editing SQUARE ---\n");
    printf("Current value of x: %d", square->x);
    square->x = ask_for_int("New value for x: ");
    printf("Current value of y: %d", square->y);
    square->y = ask_for_int("New value for y: ");
    printf("Current value of the width: %d", square->width);
    square->width = ask_for_int("New value for the width: ");
    printf("Current value of the height: %d", square->height);
    square->height = square->width;
    printf("New value for the height: %d.", square->height);
    printf("square update : x:%d y:%d width:%d height:%d.\n", square->x, square->y, square->width, square->height);
}

void edit_circle_parameters(circle_t* circle){
    printf("--- Editing CIRCLE ---\n");
    printf("Current value of cx: %d", circle->cx);
    circle->cx = ask_for_int("New value for cx: ");
    printf("Current value of cy: %d", circle->cy);
    circle->cy = ask_for_int("New value for cy: ");
    printf("Current value of rx: %d", circle->rx);
    circle->rx = ask_for_int("New value for rx: ");
    printf("Current value of ry: %d", circle->ry);
    circle->ry = circle->rx;
    printf("New value for ry: %d", circle->ry);
    printf("circle update : cx:%d cy:%d rx:%d ry:%d.\n", circle->cx, circle->cy, circle->rx, circle->ry);
}

void edit_polyline_parameters(polyline_t* polyline){
    int choice = -1;
    int index_edit;
    int x_new, y_new;
    size_t count;

    printf("--- Editing POLYLINE ---\n");

    while (choice != 0) {
        count = count_polyline_points(polyline);
        printf("\nCurrent POLYLINE has %lu points.\n", (unsigned long)count);

        if (count == 0) {
            printf("The polyline is empty. Only option 1 (Add) is available.\n");
            choice = 1;
        } else {
            printf("Options:\n");
            printf("1. Add a new point (at the end)\n");
            printf("2. Modify an existing point\n");
            printf("3. Delete an existing point\n");
            printf("0. Finish editing this polyline\n");
            choice = ask_for_int("Your choice: ");
        }

        switch (choice) {
            case 1:
                printf("--- Adding Point (End of list) ---\n");
                x_new = ask_for_int("New x coordinate: ");
                y_new = ask_for_int("New y coordinate: ");
                
                if (add_point_to_polyline(polyline, x_new, y_new)) {
                    printf("Point successfully added.\n");
                } else {
                    printf("Error: Failed to add point.\n");
                }
                break;

            case 2:
                if (count == 0) { printf("No points to modify.\n"); break; }
                printf("--- Modifying Point ---\n");
                printf("Enter the index of the point to modify(1 to %lu): ", (unsigned long)count);
                index_edit = ask_for_int("Your choice:: ");
                
                if (index_edit < 1 || index_edit > (int)count) {
                    printf("Invalid point index.\n");
                    break;
                }
                
                x_new = ask_for_int("New x coordinate: ");
                y_new = ask_for_int("New y coordinate: ");
                
                if (modify_point_at_index(polyline, index_edit, x_new, y_new)) {
                    printf("Point %d successfully updated to (%d,%d).\n", index_edit, x_new, y_new);
                } else {
                    printf("Error: Failed to find or modify point at index %d.\n", index_edit);
                }
                break;

            case 3:
                if (count == 0) { printf("No points to delete.\n"); break; }
                printf("--- Deleting Point ---\n");
                printf("Enter the index of the point to delete (1 to %lu): ", (unsigned long)count);
                index_edit = ask_for_int("Your choice: ");
                
                if (index_edit < 1 || index_edit > (int)count) {
                    printf("Invalid point index.\n");
                    break;
                }
                
                if (delete_point_at_index(polyline, index_edit)) {
                    printf("Point %d successfully deleted.\n", index_edit);
                } else {
                    printf("Error: Failed to delete point at index %d.\n", index_edit);
                }
                break;

            case 0:
                printf("Finishing polyline editing.\n");
                break;

            default:
                printf("Invalid choice. Please select 0, 1, 2, or 3.\n");
                break;
        }
    }
    printf("POLYLINE edit finished.\n");
}