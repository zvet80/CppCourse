// 07.MultithreadingAndMultiprocessing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <thread>
#include <math.h>
#include <mutex>
#include <climits>
#include <chrono>

using namespace std;
mutex mtx;
void calcPrime(unsigned long long n)
{	
	bool isPrime = true;
	unsigned long long start = clock();
	for (unsigned long long i = 2; i < n; i++)
	{
		isPrime = true;
		for (int j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
		{
			mtx.lock();
			printf("Prime %llu, %0.1f ms\n", i, clock() - start);
			mtx.unlock();
			start = clock();
		}
	}	
}

void calcFibonacci(unsigned long long n)
{	
	unsigned long long start = clock();
	unsigned long long fib0 = 0;
	unsigned long long fib1 = 1;

	for (int i = 1; i <= n; i++)
	{	
		unsigned long long fib2 = fib0 + fib1;
		fib0 = fib1;
		fib1 = fib2;

		mtx.lock();
		printf("Fibonacci %llu, %0.1f ms\n", fib0, clock() - start);
		mtx.unlock();
		start = clock();
	}

}

int main()
{
	unsigned long long start = clock();

	thread threadPrime = thread(calcPrime, 100);
	thread threadFib = thread(calcFibonacci, 50);
	threadPrime.join();
	threadFib.join();

	mtx.lock();
	printf("Time for all %0.1f\n", (float)(clock() - start )/ CLOCKS_PER_SEC);
	mtx.unlock();
    return 0;
}

