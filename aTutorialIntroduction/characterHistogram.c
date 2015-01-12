#include <stdio.h>

/* program prints a histogram of frequencies of different characters */
main() {
	int c, i, j, charsLength, match, count;
	char x;
	char chars[100];
	int charNums[100];

	i = j = charsLength = match = count = 0;
	while ((c = getchar()) != EOF && count < 25) {
		for (i = 0; i < charsLength; i++) {
			if (c == chars[i]) {
				charNums[i]++;
				match = 1;
				break;
			}
		}
		if (match == 0) {
			++charsLength;
			chars[charsLength - 1] = c;
			charNums[charsLength - 1] = 1;
		}
		count++;
		match = 0;
	}
	for (i = 0; i < charsLength; i++) {
		x = chars[i];
		if (x == '\n') {
			printf("[new line] : ");
		}
		else if (x == '\t') {
			printf("[tab] : ");
		}
		else if (x == ' ') {
			printf("[space] : ");
		}
		else {
			printf("%c : ", chars[i]);
		}
		for (j = 0; j < charNums[i]; j++) {
			printf("-");
		}
		printf("\n");
	}
}