//Defs.h  define the Marco PRINT1 and PRINT2
#ifndef Defs_H// use conditional complization for the header file, to avoid multiple inclusion.
#define Defs_H

#ifndef PRINT1  // use conditional complization for PRINT1, to avoid multiple inclusion
#define PRINT1(a) printf("%s\n",a)  //definition of PRINT1, input should be in string type
#endif

#ifndef PRINT2  //we use conditional complization for PRINT2
#define PRINT2(a,b) printf("%s,%s\n",a, b) //definition of PRINT2, input should be in string type
#endif

#endif


