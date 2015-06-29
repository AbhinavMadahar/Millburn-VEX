/******************************************************************************
This file manages the color sensor and makes it simpler to use.

Before using it, please make sure the correct #pragma is used
TODO: figure out the right #pragma to use
******************************************************************************/
#define included__color true

#ifndef included__syntax
	#include "../syntax.h"
#endif

typedef enum Color {
	grey,
	yellow,
	orange,
	red,
	blue
};
