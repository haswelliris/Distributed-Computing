#include"prime_openmp.h"

bool* prime_openmp(int n)
{
	int i, num, l;
	bool* f = (bool*)malloc(sizeof(bool)*(n+10));
	memset(f, 1, sizeof(f));
#pragma omp parallel num_threads(20)
	for (int i = 2; i < sqrt(n); i++)
		if (f[i])
		{
			#pragma omp for
			for (l=i<<1; l <= n; l = l + i) {
				f[l] = false;
			}
		}
	return f;
}