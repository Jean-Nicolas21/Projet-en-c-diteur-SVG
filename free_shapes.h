#ifndef free_shapes
#define free_shapes
#include <stdio.h>
#include <stdlib.h>
#include "shapes.h"
#include <stdbool.h>

void free_form(form_t* form);

bool delete_shape_at_index(list_shapes_t* list, int index);

#endif