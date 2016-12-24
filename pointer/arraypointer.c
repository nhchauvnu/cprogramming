#include <stdio.h>
#include <malloc.h>
#include <math.h>

#define M	3

// Su dung mang con tro, can su dung cap phat bo nho.
// a[i] la cac hang cua ma tran, chua duoc cap phat
// bo nho
void printMatrix(double *a[M], int n)
{
	printf("printMatrix:\n");
	for (int i=0;i<M;i++) {
		for (int j=0;j<n;j++)
			printf("%.2f ", a[i][j]);
		printf("\n");
	}
	return;
}

int main(int argc, char *argv[])
{
	FILE	*fp = fopen(argv[1], "r");
	char	buf[BUFSIZ];
	double	*matrix[M];
	int	n;

	// Doc so dong tu ban phim
	printf("So cot cua ma tran: ");
	scanf("%d", &n);
	// Cap phat bo nho
	for (int i=0;i<M;i++)
		matrix[i] = (double *)malloc(n*sizeof(double));
	// Mo file
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Khong doc duoc file");
		return(1);
	}
	for (int i=0;i<M;i++) {
		for (int j=0;j<n;j++)
			// Chu y: Neu doc kieu float thi dung %f
			// Neu dung %f cho kieu double thi ket qua doc se sai!
			fscanf(fp, "%lf", &matrix[i][j]);
	}
	fclose(fp);
	printMatrix(matrix, n);
	// Giai phong bo nho da cap phat
	for (int i=0;i<M;i++)
		free(matrix[i]);
	return(0);
}
