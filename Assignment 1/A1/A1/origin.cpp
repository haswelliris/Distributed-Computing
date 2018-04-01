#include"origin.h"

bool* prime_origin(int n)
{
	int i, num, l;
	bool* f = (bool*)malloc(sizeof(bool)*(n + 10));
	memset(f, 1, sizeof(f));
	for (int i = 2; i < sqrt(n); i++)
		if (f[i])
		{
			for (l = i << 1; l <= n;l+=i) {
				f[l] = false;
			}
		}
	return f;
}