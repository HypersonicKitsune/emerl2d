#####################
#
# Makefile - compilation script
# Copyright (C) 2017-2018 HypersonicKitsune <hypersonic.kitsune@gmail.com>
# This file is a part of EmeraldEngine.
#
#####################
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.
#
#####################

# Internal variables

PYLIB=/usr/lib/python3.5/config-3.5m-x86_64-linux-gnu/libpython3.5m.a
PYINC=-I-I/usr/include -I/usr/include -I/usr/include/python3.5m -I/usr/include/python3.5m 
LIBS=-L/usr/lib -lexpat -L/usr/lib -lz  -lexpat -lpthread -ldl  -lutil -lm
LIBALLEG = -lallegro -lallegro_image -lallegro_primitives
OPTS=-DNDEBUG -g -fwrapv -O2 -Wall -Wstrict-prototypes
PROGRAMS=emerl

# Recipes

all: $(PROGRAMS)

emerl:main.o draw_prims.o
	gcc main.o draw_prims.o $(LIBS) $(LIBALLEG) $(PYLIB) -o $(PROGRAMS)
	
draw_prims.o: draw_prims.c
	gcc -c draw_prims.c $(OPTS)
	
main.o:main.c draw_prims.h
	gcc -c main.c $(PYINC) $(OPTS)

# Utils

clean:
	rm -f *.o *.pyc
mrproper: clean
	rm -f $(PROGRAMS)
