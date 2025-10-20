### Editor SVG 

This a prototype for SVG editor in C. The program contains several functions, i'll describe them right after and presenting the use of the program in general.

##### Starting the program:

When the user starts the program, he'll have to insert the parameter of the viewbox or he'll have the choice to leave the program.
Then, the menu will launch and the user will have to choose between differents options: create a shape, edit a shape, delete a shape or exit the SVG Editor.
Except for the exiting option, the menu will always launch after the completion of the option selected.

###### Create:

When the user choose the creation, he will have to choose between 6 shapes: rectangle, square, circle, ellipse, line and polyline.
Then he will have to choose the parameter of the shape.

###### Edit:

If the user choose edit without an existing shape, the system will inform him that there's nothing to edit and he will be sent back to the menu.
If the user choose edit with an existing shape, he will have to choose a shape to edit in the list of shapes. After that he will insert the new parameters for the chosen shape.
Besides, for the polyline a new menu will open.

###### Delete:

If the user choose delete without an existing shape, the system will inform him that there's nothing to delete and he will be sent back to menu.
If the user choose delete with an existing shape, he will have to choose a shape to delete in the list of shapes.

###### Cancel:

The user will simply exit the program.

###### Note for the future:

The program is pretty solid and viable for the moment but lack of some functionnalities. Maybe in the future they will be new shapes as the polygone, the path or the group. Moreover, the program doesn't have any personnalisation for the shapes like the color for exemple. Maybe i'll add this in the future.

Enjoy using my svg editor.
