#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max, min, cen;
int keng[3];
void maxnum(){
	max = keng[0];
	if (max < keng[1])
		max = keng[1];
	if (max < keng[2])
		max = keng[2];
}

void minnum(){
	min = keng[0];
	if (min > keng[1])
		min = keng[1];
	if (min > keng[2])
		min = keng[2];
}

void cennum(){
	for (int i = 0; i < 3; i++)
		if (keng[i] != max && keng[i] != min)
			cen = keng[i];
}


int main() {
	for (int i = 0; i < 3; i++)
		scanf("%d", &keng[i]);
	int k = 0;
	maxnum(); minnum(); cennum();
	while (1){
		if (cen == min + 1 && cen == max - 1)
			break;

		if (max - cen > cen - min){
			int temp;
			temp = cen;
			cen = max - 1;
			min = temp;
			k++;
		}
		else{
			int temp;
			temp = cen;
			cen = min + 1;
			max = temp;
			k++;
		}
	}
	printf("%d", k);
	return 0;
}



