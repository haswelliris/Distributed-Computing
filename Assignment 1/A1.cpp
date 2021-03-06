// A1.cpp: 定义控制台应用程序的入口点。
//

#define _CRT_SECURE_NO_WARNINGS
#include "origin.h"
#include "prime_openmp.h"
#include<ctime>
#include"omp.h"

int main(int argc, char *argv[])
{
	
	//int n = atoi(argv[1]);
	int n;
	cout << "please input n: ";
	cin >> n;
	double start = omp_get_wtime();
	bool* f = prime_origin(n);
	double end = omp_get_wtime();
	double dur = (double)(end - start);
	printf("Origin Prime use Time:%.3f\n", dur);
	start = omp_get_wtime();
	bool* f2 = prime_openmp(n);
	end = omp_get_wtime();
	dur = (double)(end - start);
	printf("OpenMP Prime use Time:%.3f\n", dur);
	for (int i = 2; i<n; i++) {
		if (f[i] != f2[i])
			cout << "error!" << endl;
	}
	system("pause");
    return 0;
}

