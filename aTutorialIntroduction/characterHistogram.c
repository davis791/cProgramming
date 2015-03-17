#include <stdio.h>

/* program prints a histogram of frequencies of different characters */
int main(int argc, char ** argv) {
	if (argc < 2) {
		printf("Wrong\n");
		return 0;
	}
	char * filename = argv[1];
	FILE *fd = fopen(filename, "r");
	int c, i, j, hold, hol1, charsLength, match, count;
	int flag = 1;
	char x;
	char chars[300];
	int charNums[300];
	int shifNums[300];

	i = j = charsLength = match = count = hold = hol1 = 0;
	while ((c = fgetc(fd)) != EOF) {
		if (c >= 'A' && c <= 'Z')
			c += ('a' - 'A');
		for (i = 0; i < charsLength; i++) {
			if ((unsigned char) c == (unsigned char) chars[i]) {
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
		match = 0;
	}
	while (flag) {
		flag = 0;
		for (i = 0; i < charsLength - 1; i++) {
			if (charNums[i + 1] > charNums[i]) {
				hold = chars[i];
				hol1 = charNums[i];
				chars[i] = chars[i + 1];
				charNums[i] = charNums[i + 1];
				chars[i + 1] = hold;
				charNums[i + 1] = hol1;
				flag = 1;
			}
		}	
	}
	for (i = 0; i < charsLength; i++)
		shifNums[i] = charNums[i];
	
	int max = shifNums[0];
	while (max > 111) {
		//printf("hi%d\n", shifNums[0]);
		for (i = 0; i < charsLength; i++) {
			if (shifNums[i] % 2) 
				shifNums[i] = (shifNums[i] + 1) / 2; 
			else
				shifNums[i] = shifNums[i] / 2;
		}
		max = shifNums[0];
	}
	float percent, per, cent;
	int totalChars = 0;
	for (i = 0; i < charsLength; i++)
		totalChars += charNums[i];	
	for (i = 0; i < charsLength; i++) {
		x = chars[i];
		per = (float) charNums[i];
		cent = (float) totalChars;
		percent = per/cent;
		if (x == '\n') {
			printf("%8d [new line] : ", charNums[i]);
		}
		else if (x == '\t') {
			printf("%8d      [tab] : ", charNums[i]);
		}
		else if (x == ' ') {
			printf("%8d    [space] : ", charNums[i]);
		}
		else {
			if (chars[i] < 32 || chars[i] > 126) 
				printf("%8d 0x%8.0x : ", charNums[i], (signed int) chars[i]);
			else
				printf("%8d          %c : ", charNums[i], chars[i]);
		}
		for (j = 0; j < shifNums[i]; j++) {
			printf("-");
		}
		printf("\n");
	}
	
	printf("------ Total Characters : %d ------\n", totalChars);
	char charsUsed[26];
	for (i = 0; i < 26; i++) { 
		for (j = 0; j < charsLength; j++) {
			//printf("hi\n");
			if ('a' + i == chars[j]) {
				charsUsed[i] = 1;
			}
		}
	}
	for (i = 0; i < 26; i++) {
		if (!charsUsed[i]) { 
			printf("Letters not used: %c", 'a' + i);
			for (j = i + 1; j < 26; j++) {
				if (!charsUsed[j])
					printf(", %c", 'a' + i);
			}
			printf("\n");
			break;
		}
	} 
	return 0;
}
