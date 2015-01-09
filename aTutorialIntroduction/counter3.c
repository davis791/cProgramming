#include <stdio.h>

/* copy input to output, replace a lot of stuff */
main() {
	int c;
	
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			printf("[tab]");
		}
		else if (c == '\b') {
			printf("[backspace]");
		}
		else if (c == '\\') {
			printf("[backslash]");
		}
		else {
			printf("%c", c);
		}
	}
}