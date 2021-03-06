/****************************************************************************
* MeshLab                                                           o o     *
* An extendible mesh processor                                    o     o   *
*                                                                _   O  _   *
* Copyright(C) 2005, 2009                                          \/)\/    *
* Visual Computing Lab                                            /\/|      *
* ISTI - Italian National Research Council                           |      *
*                                                                    \      *
* All rights reserved.                                                      *
*                                                                           *
* This program is free software; you can redistribute it and/or modify      *
* it under the terms of the GNU General Public License as published by      *
* the Free Software Foundation; either version 2 of the License, or         *
* (at your option) any later version.                                       *
*                                                                           *
* This program is distributed in the hope that it will be useful,           *
* but WITHOUT ANY WARRANTY; without even the implied warranty of            *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the             *
* GNU General Public License (http://www.gnu.org/licenses/gpl.txt)          *
* for more details.                                                         *
*                                                                           *
****************************************************************************/

#ifndef SHDRSTRUCTS
#define SHDRSTRUCTS

#include <map>
#include <QString>
#include <vector>

struct UniformVariable {
	short type;
	short widget;
	float min;
	float max;
	float step;
	int location;
	union {
		int ival[4];
		float fval[4];
	};
};

struct TextureInfo {
	QString path;
	GLuint tId;
	short MinFilter;
	short	MagFilter;
	short	Target;
	short	WrapS;  
	short	WrapT;
	short	WrapR;
};


struct ShaderInfo {
	QString vpFile;
	QString fpFile;
	std::map<QString, UniformVariable> uniformVars;
	std::map<int, QString> glStatus;
	std::vector<TextureInfo> textureInfo;
	int shaderProg;
};

enum {
	SINGLE_INT = 1,
	SINGLE_FLOAT = 5,
	ARRAY_2_FLOAT = 6,
	ARRAY_3_FLOAT = 7,
	ARRAY_4_FLOAT = 8
};

static int getVarsNumber(int i) {
	switch (i) {
		case SINGLE_INT: return 1; break; 
		case SINGLE_FLOAT: return 1; break;
		case ARRAY_2_FLOAT: return 2; break;
		case ARRAY_3_FLOAT: return 3; break;
		case ARRAY_4_FLOAT: return 4; break;
		default: return 0; break;
	}
}


enum {
	WIDGET_NONE = 0,
	WIDGET_COLOR = 1,
	WIDGET_SLIDER = 2
};

enum {
	SHADE = 0,
	ALPHA_TEST,
	ALPHA_FUNC,
	ALPHA_CLAMP,
	BLENDING,
	BLEND_FUNC_SRC,
	BLEND_FUNC_DST,
	BLEND_EQUATION,
	DEPTH_TEST,
	DEPTH_FUNC,
	CLAMP_NEAR,
	CLAMP_FAR,
	CLEAR_COLOR_R,
	CLEAR_COLOR_G,
	CLEAR_COLOR_B,
	CLEAR_COLOR_A
};

#endif
