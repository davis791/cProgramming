#include <stdio.h>

/* counts blanks, tabs, and newlines. */
main() {
	int c, blanks, tabs, newlines;

	blanks = 0;
	tabs = 0;
	newlines = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			newlines++;
		}
		else if (c == '\t') {
			tabs++;
		}
		else if (c == ' ') {
			blanks++;
		}
	}
	printf("Blanks : %d\nTabs : %d\nNew lines : %d\n", blanks, tabs, newlines);
}