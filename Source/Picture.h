/*
Copyright (c) 2010 - Wii Banner Player Project

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not
claim that you wrote the original software. If you use this software
in a product, an acknowledgment in the product documentation would be
appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be
misrepresented as being the original software.

3. This notice may not be removed or altered from any source
distribution.
*/

#ifndef _PICTURE_H_
#define _PICTURE_H_

#include "Pane.h"
#include "Material.h"

class Picture : public Pane
{
public:
	Picture(std::istream& file, const std::vector<Material*>& materials);

protected:
	void Draw() const;

	void Print(unsigned int level) const
	{
		std::cout << std::string(level, '\t') << "pic: " << name << '\n';
	}

	const Material* material;
	
	struct TexCoord tex_coords[4];

	u8 vertex_colors[4][4];

	u16 mat_index;
};

#endif
