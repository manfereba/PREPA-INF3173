#include <stdio.h>
extern int etext, edata, end;

 int  main( ){

        printf( "Adr etext: %p\n",(&etext) );

        printf( "Adr edata: %p\n",(&edata) );

        printf( "Adr end: %p\n",(&end ));
return 0;
 }
