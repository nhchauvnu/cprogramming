#include <stdio.h>
#include <malloc.h>
#include <math.h>

// Su dung con tro tro den con tro
// trong do m la so hang, n la so cot cua ma tran
void printMatrix(double **a, int m, int n)
{
	printf("printMatrix:\n");
	for (int i=0;i<m;i++) {
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
	double	**matrix;
	double	*memory;
	int	m, n;

	// Doc so dong tu ban phim
	printf("Nhap so hang va so cot cua ma tran: ");
	scanf("%d%d", &m, &n);
	// Cap phat vung nho lien tuc cho ma tran
	memory = (double *)malloc(m*n*sizeof(double));
	// Cap phat bo nho cho cac con tro den dau moi hang cua ma tran
	matrix = (double **)malloc(m*sizeof(double *));
	// va gan dia chi cho cac con tro do
	for (int i=0;i<m;i++)
		matrix[i] = memory+i*n;

	// Mo file
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Khong doc duoc file");
		return(1);
	}
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++)
			// Chu y: Neu doc kieu float thi dung %f
			// Neu dung %f cho kieu double thi ket qua doc se sai!
			fscanf(fp, "%lf", &matrix[i][j]);
	}
	fclose(fp);
	// Giai phong bo nho da cap phat
	printMatrix(matrix, m, n);
	free(matrix);
	free(memory);
	return(0);
}
