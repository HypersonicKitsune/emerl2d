/*********************
 *
 * draw_prims.h - basic drawing operations
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
 
#ifndef DRAW_PRIMS_INC
#define DRAW_PRIMS_INC


/* Defines */

#define RED al_map_rgb(255, 0, 0)
#define GREEN al_map_rgb(0, 255, 0)
#define BLUE al_map_rgb(255, 0, 255)
#define CYAN al_map_rgb(0, 255, 255)
#define MAGENTA al_map_rgb(255, 0, 255)
#define YELLOW al_map_rgb(255, 255, 0)
#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define MED_GREY al_map_rgb(128, 128, 128)
#define DARK_BLUE al_map_rgb(0, 0, 64)

/* Prototypes */

ALLEGRO_COLOR color_picker(int code);

PyObject* PyInit_draw_prims(void);

/*
 * PyObject *draw_square(PyObject *self, PyObject *args)
 * 
 * For Python. Draws a square on the screen.
 */

PyObject *draw_square(PyObject *self, PyObject *args);

/*
 * PyObject *draw_rect(PyObject *self, PyObject *args)
 * 
 * For Python. Draws a rectangle on the screen.
 */

PyObject *draw_rect(PyObject *self, PyObject *args);

#endif
