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

#ifndef _HEADER_STRINGTABLE
#define _HEADER_STRINGTABLE

#include <stdint.h>

#include "res.h"

class Stringtable {
	char **table;
	int num;
	char *buf;
	bool mustfree;
	void parse(char *buf, uint32_t size);
public:
	Stringtable(const ResName& nam);
	Stringtable(uint8_t *buf, uint32_t size);
	virtual ~Stringtable();
	int size() const {
		return num;
	}
	const char *get(const int quel) const {
		if(quel<num)
			return table[quel];
		else
			return "###";
	}
};

extern Stringtable *stringtable;

#endif
