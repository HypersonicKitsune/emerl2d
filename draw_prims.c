/*********************
 *
 * draw_prims.c - basic drawing operations
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

#include <stdlib.h>
#include <stdbool.h>

#include <python3.5/Python.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "./draw_prims.h"

/* Useful functions */

ALLEGRO_COLOR color_picker(int code)
{
	switch(code)
	{
		case 0:
			return BLACK;
			break;
		case 1:
			return RED;
			break;
		case 2:
			return GREEN;
			break;
		case 3:
			return BLUE;
			break;
		case 23: // green + blue -> 23
			return CYAN;
			break;
		case 13: // red + blue -> 13
			return MAGENTA;
			break;
		case 12: // I think you've understood ...
			return YELLOW;
			break;
		case 123:
			return WHITE;
			break;
		case 50: // medium white
			return MED_GREY;
			break;
		case 31: // blue, var 1
			return DARK_BLUE;
			break;
		default:
			return MAGENTA;
			break;
	}
}

/* Python module creation */

static PyMethodDef methods[] = {{"draw_square", draw_square, METH_VARARGS, NULL},
								{"draw_rect", draw_rect, METH_VARARGS, NULL},
								{NULL, NULL, 0, NULL}
							   };
static PyModuleDef modDef = {PyModuleDef_HEAD_INIT, "draw_prims", NULL, -1,
							 methods, NULL, NULL, NULL, NULL
							};

PyObject* PyInit_draw_prims(void)
{
	return PyModule_Create(&modDef);
}

/* Python functions */


/*
 * PyObject *draw_square(PyObject *self, PyObject *args)
 * 
 * For Python. Draws a square on the screen.
 */
 
PyObject *draw_square(PyObject *self, PyObject *args)
{
	int x = 0;
	int y = 0;
	int side = 0;
	int col_num;
	ALLEGRO_COLOR color;

	PyArg_ParseTuple(args, "iiii", &x, &y, &side, &col_num);
	
	color = color_picker(col_num);
	al_draw_filled_rectangle(x, y, x+side, y+side, color);
	return Py_None;
}

/*
 * PyObject *draw_rect(PyObject *self, PyObject *args)
 * 
 * For Python. Draws a rectangle on the screen.
 */

PyObject *draw_rect(PyObject *self, PyObject *args)
{
	int x = 0;
	int y = 0;
	int sidex = 0;
	int sidey = 0;
	int col_num;
	ALLEGRO_COLOR color;

	PyArg_ParseTuple(args, "iiiii", &x, &y, &sidex, &sidey, &col_num);
	
	color = color_picker(col_num);
	al_draw_filled_rectangle(x, y, x+sidex, y+sidey, color);
	return Py_None;
}
