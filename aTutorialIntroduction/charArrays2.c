#include <stdio.h>

/* remove trailing blanks, tabs, and blank lines from lines. */
main() {
	int c, i, j, k;
	char hold[1000];
	for (i = 0; (c = getchar()) != EOF; i++) {
		if (c == '\n') 
			for (j = i - 1; j > 0; j--) 
				if (hold[j] == '\t' || hold[j] == '\n' ||
					hold[j] == ' ') 
					i--;
				else 
					break;
		hold[i] = c;
	}
	for (k = 0; k < i; k++) 
		printf("%c", hold[k]);
}
