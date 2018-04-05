// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
typedef long int li;
 
void SieveOfEratosthenes(ll n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    li x=li(n);
    bool prime[x+1];
    memset(prime, true, sizeof(prime));
 
    for (ll p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[li(p)] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<=n; i += p)
                prime[li(i)] = false;
        }
    }
 
    // Print all prime numbers
    /*for (ll p=2; p<=n; p++)
       if (prime[p])
          cout << p << " ";*/
          
    ll count=0;
          
    //counting number of such primes
    for (ll p=2; p<=n; p++)
       if (prime[li(p)])
          count++;
          
    cout<<"No of such primes smaller than or equal to "<<n<<" :\t"<<count<<endl;
}
 
// Driver Program to test above function
int main()
{
    ll n;
    n=1000000;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    SieveOfEratosthenes(n);
    return 0;
}
