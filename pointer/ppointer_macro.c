#include <stdio.h>
#include <malloc.h>
#include <math.h>

// Macro cap phat mang hai chieu co m hang n cot, kieu type
#define ALLOC2D(x, m, n, type) {\
	type *tmpmem = (type *)malloc((m)*(n)*sizeof(type));\
	x = (type **)malloc((m)*sizeof(type *));\
	for (int i=0;i<m;i++) x[i] = tmpmem+i*(n);\
}
// Macro giai phong mang hai chieu
#define FREE2D(x) {free(x[0]);free(x);}

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
	int	m, n;

	// Doc so dong tu ban phim
	printf("Nhap so hang va so cot cua ma tran: ");
	scanf("%d%d", &m, &n);
	// Cap phat vung nho lien tuc cho ma tran
	ALLOC2D(matrix, m, n, double)

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
	FREE2D(matrix)
	return(0);
}
