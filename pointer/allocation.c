#include <stdio.h>
#include <malloc.h>

int main()
{
	int	i, n, *a;

	printf("Nhap n: ");
	scanf("%d", &n);
	// Cap phat bo nho
	a = (int *)malloc(n*sizeof(int));
	for (i=0;i<n;i++) a[i] = i*2;
	for (i=0;i<n;i++) printf("%d ", a[i]); printf("\n");
	// Giai phong bo nho truoc khi thoat khoi chuong trinh
	free(a);
	return(0);
}

