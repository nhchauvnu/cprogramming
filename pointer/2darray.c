#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define M	3
#define N	2

// Su dung mang hai chieu, khai bao kich thuoc co dinh
void printMatrix(double a[M][N])
{
	printf("printMatrix:\n");
	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++)
			printf("%.2f ", a[i][j]);
		printf("\n");
	}
	return;
}

int main(int argc, char *argv[])
{
	FILE	*fp = fopen(argv[1], "r");
	char	buf[BUFSIZ];
	double	matrix[M][N];

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Khong doc duoc file");
		return(1);
	}
	for (int i=0;i<M;i++) {
		for (int j=0;j<N;j++)
			// Chu y: Neu doc kieu float thi dung %f
			// Neu dung %f cho kieu double thi ket qua doc se sai!
			fscanf(fp, "%lf", &matrix[i][j]);
	}
	fclose(fp);
	printMatrix(matrix);
	return(0);
}
