#include <iostream>
#include <ctime>


using namespace std;


long long binpow(long long a, long long e, long long m) {
	long long res = 1;
	while (e != 0) {
		if (e % 2 == 1)
			res = (res * a) % m;

		e = e / 2;
		a = (a * a) % m;
	}
	return res % m;
}
long long gcd(long long a, long long m)
{
	while (a != 0 && m != 0) {
		if (a > m)
			a = a % m;
		else
			m = m % a;
	}
	return a + m;
}
int JacobiSymbol(long long a1, long long p1)
{
	if (p1 < 1 || (p1 % 2 == 0))
		return 10;
	if (gcd(a1, p1) != 1)
		return 0;
	long long a = a1;
	long long p = p1;
	a = a % p;
	long long t = 1;
	while (a != 0) {
		while ((a % 2 == 0)) {
			a = a / 2;
			long long r = p % 8;
			if (r == 3 || r == 5)
				t = -t;
		}
		long long x = p;
		p = a;
		a = x;
		if (a % 4 == 3 && p % 4 == 3)
			t = -t;

		a = a % p;
	}
	if (p == 1)
		return t;
	return 0;
}
int TestSoloveya(long long a)
{
	const int N = 10000000;
	int res = 1;
	int i;

	for (int i = 0; i < N; i += 1)
	{
		long long k = 1 + rand() % (a - 1);

		if (gcd(a, k) > 1)
		{
			res = 0;
			break;
		}

		long long j = binpow(k, ((a - 1) / 2), a);
		int jacobiSymbol = JacobiSymbol(k, a);
		if (jacobiSymbol < 0)
			j = j - a;

		if (j != jacobiSymbol)
		{
			res = 0;
			break;
		}

	}
	return res;
}



int main()
{
	//2147483647
	//524827
	//131071
	long long n;
	cin >> n;
	double start_time = clock();
	string isPrime;
	if (TestSoloveya(n))
		isPrime = "";
	else
		isPrime = "not";
	cout << n << " is " << isPrime << " prime " << endl;
	long end_time = clock();
	cout << "Time " << end_time - start_time << endl;

	return 0;
}