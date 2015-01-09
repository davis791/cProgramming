#include <stdio.h>

/* copy its input to output, replacing each string 
	with one or more blanks with one blank */
main() {
	int c;
	char hold;

	while ((c = getchar()) != EOF) {
		if (!(c == hold && c == ' ')) {
			printf("%c", c);
		}
		hold = c;
	}
}