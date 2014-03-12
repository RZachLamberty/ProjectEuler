#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

/* in terms of usability: a *developer* might consider createing a fibonacci
 * number generator for re-use. well... they would realize they should do it
 * after doing it three times.
 *
 * Never do something more than twice.
 */
int pb2(int max)
{
  int i=1, j=2, sum=0, temp=j;
  while( j < max )
    {
      // this would be a place where brackets and formatting would make the
      // code more legible.
      if( j%2 == 0 ) sum += j;
      temp=j;
      j=j+i;
      i=temp;
    }
  cout << "The sum is " << sum << endl;
  return sum;
}

int main()
{
  int max=4e6;
  int sol=pb2(max);
  return 0;
}
