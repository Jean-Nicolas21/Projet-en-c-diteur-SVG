#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include "free_shapes.h"
#include <stdbool.h>


void free_form(form_t* form) {
    switch (form->type) {
    case RECTANGLE:
        free_rectangle(form->data.rectangle);
        break;
    case ELLIPSE:
        free_ellipse(form->data.ellipse);
        break;
    case LINE:
        free_line(form->data.line);
        break;
    case SQUARE:
        free_square(form->data.square);
        break;
    case CIRCLE:
        free_circle(form->data.circle);
        break;
    case POLYLINE:
        free_polyline(form->data.polyline);
        break;
    }
}

bool delete_shape_at_index(list_shapes_t* list, int index) {
    if (!list || !list->head || index <= 0) {
        return false;
    }
    node_t* current = list->head;
    node_t* previous = NULL;
    int count = 1;
    while (current != NULL && count < index) {
        previous = current;
        current = current->next;
        count++;
    }
    if (current == NULL) {
        return false; 
    }
    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free_form(current->data_form); 
    free(current->data_form); 
    free(current);
    return true;
}