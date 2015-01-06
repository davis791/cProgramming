#include <stdio.h> 

/* print Fahrenheit-Celsius table
	for fahr = 0, 20, ..., 300; floating point version */
main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;		/* lower limit of temp table */
	upper = 300;	/* upper limit */
	step = 20;		/* step size */

	celsius = lower;
	printf("This is the celsius to fahrenheit conversion table\n");
	while (celsius <= upper) {
		fahr = ((9.0/5.0) * celsius)+ 32.0;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}