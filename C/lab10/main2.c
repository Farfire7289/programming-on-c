#include <stdio.h>
#include <stdlib.h>
#define MAXN(array, n)({int i; double maxN = array[0]; for (i = 0; i<n; i++){maxN = array[i];}maxN;})
int main() {
	char input[256];
	int numbers[256];
	int k;
	int i;
	printf("Num amount: ");
	scanf("%d", &k);
	printf("Array of %d amount: ", k);
	for (i = 0; i<k; i++){
		scanf("%d", &numbers[i]);
	}
	for (i = 0; i<k; i++){
		printf("%d ", numbers[i]);
	}
	double max_num = MAXN(numbers, k);
	printf("Maximum: %.2lf", max_num);
	return 0;
}
