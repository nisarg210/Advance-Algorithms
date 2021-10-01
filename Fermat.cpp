#include<bits/stdc++.h>
using namespace std;

int power(long long int a, unsigned long long int n, long long int p){
	int res = 1;
	a = a % p;
	while(n>0){
		if(n & 1){
			res = (res * a) % p;
		}
		n = n/2;
		a = (a * a) % p;
	}
	return res;
}

long long int gcd(int a, int b){
	if(a < b){
		return gcd(b, a);
	}
	else if(a % b == 0){
		return b;
	}
	else{
		return gcd(b, a % b);
	}
}

bool isPrime(unsigned int n, int k){
	srand(rand());
	if(n <= 1 || n ==4){
		return false;
	}
	if(n <= 3){
		return true;
	}
	while(k > 0){
		long long int a = 2 + rand() % (n-4);
		if(gcd(n, a) != 1){
			return false;
		}
		if(power(a, n-1, n) != 1){
			return true;
		}
		k--;
	}
	return true;
}

int main()
{
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

	long long int k = 10;
	long long int n;
	cin >> n;
	srand(time(0));
	isPrime(n, k) ? cout << "prime" << endl : cout << " not prime" <<endl;
	return 0;
}
