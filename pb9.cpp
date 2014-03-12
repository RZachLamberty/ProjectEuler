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
 *  The most important thing in project euler -- and one of the more important
 *  things in real development -- is reducing the search size.
 *
 *  a < b < c and a + b + c               ==> a < 1000 / 3
 *  Given a, b < c and a + b = 1000 - c   ==> b < (1000 - a) / 2
 *  Given a and b, c = 1000 - a - b
 */
int pb9()
{
  int a0=0, b0=0, c0=0;
  for( int a=1; a<997; a++ )
    {
      for( int b=a+1; b<998; b++ )
        {
          // it is WAY easier to check if the ONE acceptable c is pythagorean
          // than it is to check if ANY of the MANY c's are acceptable
          //
          // BETTER YET -- check if, for a and b, c = sqrt(a**2 + b**2), is an int
          // (int)a == a
          for( int c=b+1; c<999; c++ )
            {
              if( a*a + b*b != c*c ) continue;
              if( a + b + c == 1000)
                {
                  a0=a;
                  b0=b;
                  c0=c;
		  break; //we are told there is only one
                }
            }
        }
    }
  cout << a0 << " " << b0 << " " << c0 << endl;
  cout << a0*b0*c0 << endl;
  return a0*b0*c0;
}

int main()
{
  int sol=pb9();
  return 0;
}
