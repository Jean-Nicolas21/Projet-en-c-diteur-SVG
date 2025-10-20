#ifndef shapes
#define shapes
#include <stdio.h>
#include <stdlib.h>


typedef struct viewbox_s{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
}viewbox_t;

viewbox_t* create_viewbox(void);
void free_viewbox(viewbox_t* viewbox);

typedef struct rectangle_s{
    int x;
    int y;
    int width;
    int height;
}rectangle_t;

rectangle_t* create_rectangle(void);
void free_rectangle(rectangle_t* rectangle);

typedef struct square_s{
    int x;
    int y;
    int width;
    int height;
}square_t;

square_t* create_square(void);
void free_square(square_t* square);

typedef struct ellipse_s{
    int cx;
    int cy;
    int rx;
    int ry;
}ellipse_t;

ellipse_t* create_ellipse(void);
void free_ellipse(ellipse_t* ellipse);

typedef struct circle_s{
    int cx;
    int cy;
    int rx;
    int ry;
}circle_t;

circle_t* create_circle(void);
void free_circle(circle_t* circle);

typedef struct line_s{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
}line_t;

line_t* create_line(void);
void free_line(line_t* line);

typedef struct points_s{
    int x;
    int y;
    struct points_s* next;
}points_t;

typedef struct polyline_s{
    points_t* head;
}polyline_t;

polyline_t* create_polyline(void);
void free_polyline(polyline_t* polyline);
void free_point_list(points_t* head);
int add_point_to_polyline(polyline_t* polyline, int x, int y);
size_t count_polyline_points(const polyline_t* polyline);
points_t* get_point_by_index(polyline_t* polyline, int index);
int modify_point_at_index(polyline_t* polyline, int index, int x, int y);
int delete_point_at_index(polyline_t* polyline, int index);

typedef struct polygone_s{

}polygone_t;

typedef struct path_s{

}path_t;

typedef struct group_s{

}group_t;

typedef union shapes_s{
    rectangle_t* rectangle;
    ellipse_t* ellipse;
    line_t* line;
    square_t* square;
    circle_t* circle;
    polyline_t* polyline;
}shapes_t;

typedef enum form_type_s{
    RECTANGLE = 1,
    ELLIPSE = 2,
    LINE = 3,
    SQUARE = 4,
    CIRCLE = 5,
    POLYLINE = 6,
}form_type_t;

typedef struct form_s{
    form_type_t type;
    shapes_t data;
}form_t;

void choice_shapes_and_insert();

//void choice_form(form_t form);

//liste en dessous

typedef struct node_s{
    form_t* data_form;
    struct node_s* next;
}node_t;

typedef struct list_shapes_s{
    node_t* head;
}list_shapes_t;

list_shapes_t* create_list_shapes();

void insert_form_head(list_shapes_t* list, form_t* new_form);

void display_list_shapes(list_shapes_t* list);

node_t* get_shapes_index(list_shapes_t* list, int index);

void edit_rectangle_parameters(rectangle_t* rectangle);

void edit_ellipse_parameters(ellipse_t* ellipse);

void edit_line_parameters(line_t* line);

void edit_square_parameters(square_t* square);

void edit_circle_parameters(circle_t* circle);

void edit_shapes(list_shapes_t* list);

void edit_polyline_parameters(polyline_t* polyline);

#endif