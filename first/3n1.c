#include <stdio.h>

int cycleLength(int n)
{
	int	count = 1;
	while (n != 1) {
		count++;
		if (n % 2 == 0)
			n /= 2;
		else
			n = n*3 + 1;
	}
	return(count);
}

int main(int argc, char *argv[])
{
	FILE	*fp;
	int 	tmp, i, j, k, max;
	char	buf[BUFSIZ];
	
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		perror("Khong doc duoc file");
		return(1);
	}
	while (fgets(buf, BUFSIZ, fp) != NULL) {
		// Doc hai so i, j
		sscanf(buf, "%d%d", &i, &j);
		for (k=i;k<=j;k++) {
			tmp = cycleLength(k);
			if (k == i)
				max = tmp;
			else if (tmp > max)
				max = tmp;
		}
		printf("%d %d %d\n", i, j, max);
	}
	fclose(fp);
	return(0);
}

