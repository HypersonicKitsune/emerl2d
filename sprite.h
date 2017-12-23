/*********************
 *
 * sprite.h - sprite (2D renderable objects) operations
 * Copyright (C) 2017-2018 HypersonicKitsune <hypersonic.kitsune@gmail.com>
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

#ifndef SPRITE_H_DEF
#define SPRITE_H_DEF

typedef struct Sprite Sprite;
struct Sprite
{
	ALLEGRO_BITMAP *img;
	int x;
	int y;
};

#endif // SPRITE_H_DEF
