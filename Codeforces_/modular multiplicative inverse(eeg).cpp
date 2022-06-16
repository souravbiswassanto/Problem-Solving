// C++ program to find multiplicative modulo inverse using 
// Extended Euclid algorithm. 
#include<iostream> 
using namespace std; 
#define ll long long

ll gcdExtended(ll a, ll b, ll *x, ll *y); 
void modInverse(ll a, ll m) 
{ 
	ll x, y; 
	ll g = gcdExtended(a, m, &x, &y); 
	if (g != 1) 
		cout << "Inverse doesn't exist"; 
	else
	{ 
		// m is added to handle negative x 
		ll res = (x%m + m) % m; 
		cout << "Modular multiplicative inverse is " << res; 
	} 
} 

// C function for extended Euclidean Algorithm 
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
	// Base Case 
	if (a == 0) 
	{ 
		*x = 0, *y = 1; 
		return b; 
	} 

	ll x1, y1; // To store results of recursive call 
	ll gcd = gcdExtended(b%a, a, &x1, &y1); 

	// Update x and y using results of recursive 
	// call 
	*x = y1 - (b/a) * x1; 
	*y = x1; 

	return gcd; 
} 

// Driver Program 
int main() 
{ 
	ll a = 3, m = 11; 
	modInverse(a, m); 
	return 0; 
} 
