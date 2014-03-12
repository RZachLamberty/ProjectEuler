#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

const int Ndigi=6; //999*999=998001 has 6 digits
int pb4()
{
  int digits[Ndigi]={};
  int maxProd=0;
  int sum=0;
  for( int i=1; i<1000; i++ )
    {
      for( int j=1; j<1000; j++ )
        {
          int a=i*j;
          //reset array of digits in base 10
	  digits[0]=a%10;
          sum=digits[0];
          for( int k=1; k<Ndigi; k++ )
            {
                // You're calculating this 1000 * 1000 times -- you could make
                // an array or list to do a lookup instead and save the time
              digits[k]=(a%int(pow(10,k+1))-sum)/pow(10,k);
              sum+=pow(10,k)*digits[k];
            }
          //check whether a is a palindrome
          // awwwww yeah ternary operators
          int Ncheck = (Ndigi%2==0) ? Ndigi/2 : (Ndigi-1)/2;
          bool pal=true;
          for( int k=0; k<=Ncheck; k++ )
            {
              if( digits[k] != digits[Ndigi-k-1] )
                {
                  pal=false;
                  break;
                }
            }
            // there is usually a max function -- if there is, no need to check
            // if a > maxProd. replace both pieces with a = max(a, maxProd)
          if( pal==true && a>maxProd ) maxProd=a;
        }
    }
  cout << "The largest palindrome made from the product of two 3-digit numbers is " << maxProd << endl;
  return maxProd;
}

int main()
{
  int sol=pb4();
  return 0;
}
