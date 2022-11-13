#include <stdio.h>
#include <stdlib.h>

/* Problema > Achar o elemento majoritário, com complexidade de tempo linear e de espaço O(1)
O elemento majoritário é o elemento que aparece mais ⌊n / 2⌋vezes. Você pode supor que o elemento majoritário sempre existe na matriz.
*/

/* //Esse eu fiz primeiro, mas a complexidade dele ta muito alta pro requisito do exercicio
int majorityElement (int* nums, int numsSize) {
	int *count = (int *) calloc (4,numsSize);

	for (int i = 0; i < numsSize; i++) {
		for (int j = i+1; j < numsSize; j++){
			if (nums[i] == nums [j]){
				count[i] += 1;
			}
		}
	}

	int times = count [0], major = 0;

	for (int i = 0; i < numsSize; i++) {
		if (count[i] > times){
			times = count[i];
			major = i;
		}
	}

	printf("\nMajor Number = %d, %d times",nums[major],times+1);

	free (count);
	return nums[major];
}
*/

//E este tem uma complexidade linear em seu melhor caso
int majorityElement (int* nums, int numsSize) {
	int times = 1;

	for (int i = 0; i < numsSize; i++) {
		for (int j = i+1; j < numsSize; j++){
			if (nums[i] == nums [j]){
				times++;
			}
			if (times > numsSize/2)
				return nums[i];
		}
	}
}

int main() {
	int nums [5] = {1,1,1,2,7};

	printf("\n%d",majorityElement(nums,5));
}