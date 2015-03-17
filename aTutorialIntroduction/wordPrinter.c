#include <stdio.h>

#define IN 	1 	/* inside a word */
#define OUT 0	/* outside a word */

/* prints its input one word per line */
main() {
	int c, nw, state;

	state = OUT;
	nw = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t') {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			++nw;
		}
		if (state == IN) {
			printf("%c", c);
		}
		else if (state == OUT) {
			printf("\n");
		}
	}
	printf("%d\n", nw);
}
