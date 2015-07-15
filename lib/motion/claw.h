/*******************************************************************************
Purpose: manage the claw if we implement one
Testing status: untested
Warning: we may not even use a claw, in which case this file is useless

This file assumes that the claw is a simplified human arm, so it anatomic vocab
used when talking about a human arm. These terms are very well defined, and help
to avoid confusion.

Possible design for the claw:
    proximal servo:
        purpose: rotate the arm up and down
        anatomic analog: a hinge joint like an elbow or knee
    long metal rod:
        purpose: extend the hand out so it can reach
        anatomic analog: part of your arm between the hand and elbow
    hand:
        purpose: grabs the objects and releases them
        parts:
            fixed half: stays in place
            distal servo: moves the other half to close the hand
*******************************************************************************/
#ifndef included__claw
#define included__claw true

// for the proximal servo
void raise(int deg);

// for the distal servo
void grab();
void release();

#endif
