s#include <stdio.h>

/* verify that the expression getchar() != EOF is 0 or 1 */
main() {
   char value;
   
   value = (getchar() != EOF);
   printf("getchar() != EOF returns: (char) %i\n", value);
   printf("EOF = %d\n", EOF);
   return 0;
}