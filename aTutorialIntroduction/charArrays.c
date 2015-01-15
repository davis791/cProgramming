#include <stdio.h>

/* print all input lines that are longer than 80 characters */
main() {
	int c, i, j, k, lineLength, newLine, index;
	char hold[1000];
	lineLength = i = newLine = k = 0;
	while ((c = getchar()) != EOF) {
		hold[i] = c;
		i++;
	}
	for (j = 0; j < i; j++) {
		lineLength++;
		if (hold[j] == '\n') {
			if (lineLength > 80) {
				index = lineLength + k;
				while (k < index) {
					printf("%c", hold[k]);
					k++;
				}
			}
			else {
				k = lineLength + k;
			}
			lineLength = 0;
		}
	}
}
