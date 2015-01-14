#include <stdio.h>

/* conversion using a function */
float convertFahrTocelsius(int h);

main() {
	float fahr;
	int lower, upper, step;

	lower = 0;		/* lower limit of temp table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	fahr = lower;
	while (fahr <= upper) {
		printf("%3.0f\t%6.1f\n", fahr, convertFahrTocelsius(fahr));
		fahr = fahr + step;
	}
}
float convertFahrTocelsius(int fahr) {
	float celsius;
	celsius = (5.0/9.0) * (fahr - 32.0);
	return celsius;
}