// Defs.h: define the Marco MAX2 MAX3

#ifndef Defs_H// use conditional to avoid the multiple inclusion of Defs.h
#define Defs_H

#define MAX2(x,y) x>y ?x:y   //define MAX2, return the bigger value between x,y
#define MAX3(x,y,z) MAX2(x,y)>z ? MAX2(x,y):z//define MAX3, return the bigger of MAX2(x,y) and z, that is , 
                                             //the biggest of x,y,x
#endif

