#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>

typedef struct People{
	int x;
	int y;
	int rank;
}People;


int main() {
	int k = 0;
	People people[50];

	scanf("%d", &k);

	for (int i = 0; i < k; i++){
		int x = 0, y = 0;
		scanf("%d %d", &x, &y);
		people[i].x = x;
		people[i].y = y;
		people[i].rank = 1;
	}

	for (int i = 0; i < k; i++){
		for (int j = 0; j < k; j++){
			if (i == j)
				continue;
			if (people[i].x < people[j].x && people[i].y < people[j].y)
				people[i].rank++;
		}
	}

	for (int i = 0; i < k; i++)
		printf("%d ", people[i].rank);


}