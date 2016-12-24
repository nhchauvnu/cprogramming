#include <stdio.h>
#include <malloc.h>
#include <memory.h>

#define MINE	'*'
#define NOMINE	'.'
#define ZERO	'0'
#define INCREASE(x)	{ if (x != MINE) x += 1; }
// Macro cap phat mang hai chieu co m hang n cot, kieu type
#define ALLOC2D(x, m, n, type) {\
	type *tmpmem = (type *)malloc((m)*(n)*sizeof(type));\
	x = (type **)malloc((m)*sizeof(type *));\
	for (int i=0;i<m;i++) x[i] = tmpmem+i*(n);\
}
// Macro giai phong mang hai chieu
#define FREE2D(x) {free(x[0]);free(x);}

// Vao: ma tran khu dat land, so hang m va so cot n
void printRecommend(char **cell, int m, int n)
{
	int	i, j;
	char	**rec;

	ALLOC2D(rec, m+2, n+2, char)
	// Khoi dong: khong co min o bat ky o nao
	memset(rec[0], ZERO, (m+2)*(n+2));
	for (i=1;i<m+1;i++)
		for (j=1;j<n+1;j++)
			if (cell[i-1][j-1] == MINE) {
				// Gan gia tri cac o co min
				rec[i][j] = MINE;
				// sau do tang gia tri 8 o xung quanh o nay len 1
				// neu gia tri cac o nay khong phai la MINE
				INCREASE(rec[i-1][j-1])	// Hang i-1
				INCREASE(rec[i-1][j])
				INCREASE(rec[i-1][j+1])

				INCREASE(rec[i][j-1])	// Hang i
				INCREASE(rec[i][j+1])

				INCREASE(rec[i+1][j-1])	// Hang i+1
				INCREASE(rec[i+1][j])
				INCREASE(rec[i+1][j+1])
			}
	for (i=1;i<m+1;i++){
		for (j=1;j<n+1;j++)
			printf("%c", rec[i][j]);
		printf("\n");
	}
	FREE2D(rec)
	return;
}

int main(int argc, char *argv[])
{
	FILE	*fp;
	int	m, n;
	char	**cell, buf[BUFSIZ];
	int	i, j;

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Khong doc duoc file");
		return(1);
	}
	// Doc kich thuoc khu dat
	if (fgets(buf, BUFSIZ, fp) != NULL) {
		sscanf(buf, "%d%d", &m, &n);
	}
	else {
		fprintf(stderr, "Khong biet kich thuoc khu dat");
		fclose(fp);
		return(2);
	}
	// Cap phat bo nho cho cac o trong khu dat
	ALLOC2D(cell, m, n, char)
	// Doc gia tri vao tung o cua khu dat
	for (i=0;i<m;i++) {
		// Ngam dinh cac o khong co min
		for (j=0;j<n;j++)
			cell[i][j] = NOMINE;
		if (fgets(buf, BUFSIZ, fp) != NULL)
			for (j=0;j<n;j++)
				cell[i][j] = buf[j];
	}
	printRecommend(cell, m, n);
	fclose(fp);
	FREE2D(cell)
	return(0);
}

