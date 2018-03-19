#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int k = 2;
int **Hyoun;
int Height, Width;

int chec(int H, int W){
	if (H < 0 || H >= Height || W < 0 || W >= Width)
		return 0;

	if (Hyoun[H][W] == 1){
		Hyoun[H][W] = k;

		chec(H - 1, W - 1);
		chec(H - 1, W);
		chec(H - 1, W + 1);
		chec(H, W - 1);
		chec(H, W + 1);
		chec(H + 1, W - 1);
		chec(H + 1, W);
		chec(H + 1, W + 1);

		return 1;
	}
	else
		return 0;

}

int main() {
	scanf("%d %d", &Height, &Width);

	Hyoun = (int**)malloc(sizeof(int*)*Height);
	for (int i = 0; i < Height; i++){
		Hyoun[i] = (int*)malloc(sizeof(int)*Width);
	}

	for (int i = 0; i < Height; i++){
		for (int j = 0; j < Width; j++){
			scanf("%d", &Hyoun[i][j]);
		}
	}

	for (int j = 0; j < Height; j++){
		for (int i = 0; i < Width; i++){
			if (chec(j, i) == 1){
				k++;
			}
		}
	}

	printf("%d", k - 2);
	return 0;
}

