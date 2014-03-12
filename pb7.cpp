#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

/*
 *  The "sieve" approach is best when you know roughly how many primes you
 *  need BUT (more importantly) want to have frequent lookups of whether or not
 *  something is prime
 *
 *  I would recommend, for this problem, filling in the mask (primes) as you
 *  go up, rather than in advance. For a given N, cycle through all primes less
 *  than sqrt(N) and see if N is divisible. If it is, then mark the primes
 *
 *  That is to say, mark products only when you have to, rather than ahead of
 *  time.
 */

const int N0=2000000;
int pb7(int n)
{
  int primes[N0]={};
  // std:: is unecessary if you have used namespace std
  std::fill_n(primes,N0,1);
  primes[0]=0;
  primes[1]=0;
  //remove products
  for( int i=2; i<N0; i++ )
    {
      for( int j=2; i*j<N0; j++ )
        {
          primes[i*j]=0;
        }
    }
  //search for the nth prime term
  int nthPrime=0, count=0;
  for( int i=0; i<N0; i++ )
    {
      if( primes[i]==1 )
        {
          count++;
          if( count==n )
            {
              nthPrime=i;
              break;
            }
        }
    }
  cout << "The " << n << "th prime is " << nthPrime << endl;
  return nthPrime;
}

int main()
{
  int n=10001;
  int sol=pb7(n);
  return 0;
}
