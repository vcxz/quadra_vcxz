/* -*- Mode: C++; c-basic-offset: 2; tab-width: 2; indent-tabs-mode: nil -*-
 * 
 * Quadra, an action puzzle game
 * Copyright (C) 1998-2000  Ludus Design
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "SDL.h"

#include "error.h"
#include "video.h"

#ifndef NDEBUG
	bool _debug = true;
#else
	bool _debug = false;
#endif

void fatal_msgbox(const char* m, ...) {
	char st[1024];
	va_list marker;
	va_start(marker, m);
	vsnprintf(st, sizeof(st) - 1, m, marker);
	va_end(marker);
	SDL_LogCritical(SDL_LOG_CATEGORY_APPLICATION, "fatal error: %s", st);
	exit(1);
}

void msgbox(const char* m, ...) {
	if(_debug) {
		char st[1024];
		va_list marker;
		va_start(marker, m);
		vsnprintf(st, sizeof(st) - 1, m, marker);
		va_end(marker);
		SDL_Log("%s", st);
	}
}

void skelton_msgbox(const char* m, ...) {
	if(_debug) {
		char st[1024];
		va_list marker;
		va_start(marker, m);
		vsnprintf(st, sizeof(st) - 1, m, marker);
		va_end(marker);
		SDL_Log("%s", st);
	}
}

void user_output(const char* title, const char *msg) {
	printf("%s\n%s\n",title,msg);
}
