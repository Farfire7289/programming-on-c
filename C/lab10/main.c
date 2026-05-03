#include <stdio.h>
#include <stdlib.h>
#define MAX(array, n)({int i; double max = (array)[0]; for(i = 0; i<(n); i++){if ((array)[i]>max) max = (array)[i]; }max;} )
int main() {
	
	char input[512];
	double nums[128];
	int count = 0;
	printf("Nums: ");
	fgets(input, sizeof(input), stdin);
	char *token = strtok(input, " \t\n");
	while(token != NULL && count<128){
		nums[count] = atof(token);
		count = count +1;
		token = strtok(NULL, " \t\n");
	}
	double max_num = MAX(nums, count);
	
	printf("Maximum: %.2lf", max_num);
	
	return 0;
}
