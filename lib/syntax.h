/*******************************************************************************
This file improves upon the built-in syntax to make it more readible by:
	* allowing for the use of keywords like 'and' in place of '&&'
	* ignoring units like 'cm' so they can be used in files without
	  affecting performance or behavior
	* converting quantities like 'percent' to a pure number
	* making simpler syntax like repeat(...) to make intentions clear

If the keywords are already defined in a program, it will not redefine them.
*******************************************************************************/

// force redefinition
#undef included__syntax
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

	#ifndef nor
		#define nor &&! // define nor as: and not
	#endif

	#ifndef neither
		#define neither !
	#endif

// quantity definitions
	#ifndef percent
		#define percent /100.0
	#endif

	#ifndef dozen
		#define dozen *12
	#endif

// units of measurements are ignored to specify units without changing execution

	#ifndef cm
		#define cm /**/
	#endif

	#ifndef sec
		#define sec /**/
	#endif

	#ifndef msec // millisecond
		#define msec /**/
	#endif

	#ifndef per // so that we can say 'cm per sec'
		#define per /**/
	#endif

	#ifndef deg
		#define deg /**/
	#endif

	#ifndef Hz
		#define Hz /**/
	#endif

	#ifndef bit
		  #define bit /**/
	#endif

	#ifndef byte
		#define byte /**/
	#endif

	#ifndef dB // decibel
		  #define dB /**/
	#endif

// code flow
	#ifndef repeat(x) // repeats a segment of code up to 2 ** 16 = 65536 times
		#define repeat(x) for(unsigned short uegeuo=0; uegeuo<x; uegeuo++)
	#endif

	#ifndef unless(x)
		#define unless(x) if(!(x))
	#endif
