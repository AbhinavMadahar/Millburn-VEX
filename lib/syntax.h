/*******************************************************************************
This file improves upon the built-in syntax to make it more readible by:
	* allowing for the use of keywords like 'and' in place of '&&'
	* converting quantities like 'percent' to a pure number
	* making simpler syntax like repeat(...) to make intentions clear

If the keywords are already defined in a program, it will not redefine them.
*******************************************************************************/

#ifndef included__syntax
#define included__syntax true

// Boolean logic operators
	#ifndef and
		#define and &&
	#endif

	#ifndef or
		#define or ||
	#endif

	#ifndef xor
		#define xor ^
	#endif

	#ifndef not
		#define not !
	#endif

	#ifndef unless(x)
		#define unless(x) if(!(x))
	#endif

#endif
