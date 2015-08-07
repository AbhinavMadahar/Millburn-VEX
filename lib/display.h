/*******************************************************************************
This file manages time-related activities such as:
	* printing text to the screen

It will treat the output like a terminal, where new text will make the old text
move up by 1 line.
*******************************************************************************/
#ifndef included__display
#define included__display true

#include "syntax.h"

#define numLINES 8 // XXX: can this be converted to a const variable?
string onscreen[numLINES];

// tries to find the highest blank line
// if none of them are blank, it returns -1
int emptyLine() {
	for (unsigned char i = 0; i < numLINES; i++)
		if (onscreen[i] == 0 or onscreen[i] == "")
			return i;

	return -1; // if none of the lines were blank
}

void printf(string); // forward declare for shiftUp

// moves the lines up by 1 line
inline void shiftUp() {
	// update onscreen[]
	for (unsigned char i = 0; i < numLINES - 1; i++)
		onscreen[i] = onscreen[i+1];
	clear(numLINES - 1);

	// update the screen
	for (unsigned char i = 0; i < numLINES; i++)
		printf(onscreen[i]);
}

void printf(const string text) {
	int line;

	if (emptyLine() == -1) { // if the screen is full
		shiftUp();
		line = numLINES - 1;
	} else {
		line = emptyLine();
	}

	nxtDisplayTextLine(line, text);
	onscreen[line] = text;
}

void printf(const bool condition) {
	// because the string literals cannot be passed, we have to declare these
	const string trueString = "true", falseString = "false";
	printf(condition ? trueString : falseString);
}

void printf(const int number) {
	printf("" + number); // coerse to a string
}

void printf(const char letter) {
	printf("" + letter); // coerse to a string
}

void printf(const float number) {
	printf("" + number); // TODO: remove trailing zeros when outputting
}

void printf(const byte number) {
	printf((int) number);
}

// TODO: printf(Color)

void clear(const unsigned char line) {
	nxtDisplayTextLine(line, "");
	onscreen[line] = "";
}

void clear() {
	for (unsigned char line = 0; i < numLINES; i++)
		clear(line);
}

#endif
