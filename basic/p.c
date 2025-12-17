// ------------------------
// Macro Definitions
// ------------------------
#include <stdio.h>

#define subm(a,b) ((a)-(b))
#define cubem(a) ((a)*(a)*(a))
#define minm(a,b) ((a)<=(b)?(a):(b))
#define oddm(a) ((a)%2==1)


// ------------------------
// Function Definitions
// ------------------------
int subf(int a, int b) {
	return a - b;
}
int cubef(int a) {
	return a * a * a;
}
int minf(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}
int oddf(int a)
{
	if (a % 2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int x = 3;
	int y = 4;
	// function call
	printf("subf(%d,%d) = %d\n", x, y, subf(x, y));
	printf("cubef(%d) = %d\n", x, cubef(x));
	printf("minf(%d,%d) = %d\n", x, y, minf(x, y));
	printf("oddf(%d) = %d\n\n", x, oddf(x));

	// macro calls
	printf("SUB(%d,%d) = %d\n", x, y, subm(x, y));
	printf("CUBE(%d) = %d\n", x, cubem(x));
	printf("MIN(%d,%d) = %d\n", x, y, minm(x, y));
	printf("ODD(%d) = %d\n\n", x, oddm(x));
}
