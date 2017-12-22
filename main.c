/*********************
 *
 * main.c - entry point
 * Copyright (C) 2017 HypersonicKitsune <hypersonic.kitsune@gmail.com>
 * This file is a part of EmeraldEngine.
 *
 *********************
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 *********************/

// std
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// py
#include <python3.5/Python.h>

// allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

// project
#include "./draw_prims.h"

/* Tous les trucs d'Allegro */

ALLEGRO_DISPLAY *display = NULL;

/*  Exécute du code Python depuis un fichier externe */

bool run_py(char *path)
{

	FILE *file = _Py_fopen(path, "r");
	if(file != NULL)
	{
		PyRun_SimpleFile(file, path);
		return true;
	}
	else
		return false;
}

/* Fonction que l'on peut appeler depuis un script Python */

PyObject *carre(PyObject *self, PyObject *args)
{
	int n = 0;
	PyArg_ParseTuple(args, "i", &n);
	return Py_BuildValue("i", n*n);
}

int main(int argc, char *argv[])
{	
	/* Allegro */
	
	printf("Ok, voyons Allegro ...\n");
	
	if(!al_init())
		return EXIT_FAILURE;
		
	if(!al_init_primitives_addon())
		return EXIT_FAILURE;
		
	if(!al_init_image_addon())
		return EXIT_FAILURE;
		
	display = al_create_display(640, 480);
	if(!display)
		return EXIT_FAILURE;
		
	al_set_window_title(display, "EmeraldEngine Demonstration");
	
	al_clear_to_color(al_map_rgb(0, 0, 64));
	

	
	/* Python */
	
	PyImport_AppendInittab("draw_prims", &PyInit_draw_prims);
	
	Py_Initialize();

	run_py("./python.py");

	Py_Finalize();
	
	/* Fin Python */
	
	al_flip_display();
	
	al_rest(5);
	
	al_destroy_display(display);
	
	printf("Nickel chrome\n");
	
	/* Fin Allegro */
	
	return EXIT_SUCCESS;
}
