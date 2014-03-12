/*
 *  This is the nittest of picks -- eventually people will care about the
 *  overhead of importing unneeded things. In a general c++ program -- from
 *  *my* possibly ridiculous experience -- you really only need iostream, and
 *  then vector or map for whatever data containers you need.
 *
 *  And boost is the best thing ever.
 */

#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>

// The only acceptable namespace
using namespace std;

int pb1(int max)
{
  int sum=0;
  /* some people will give a shit about formatting and tab delimitting and all
   * that biz. e.g.
   *    for (int i = 0; i < max, i++) {
   *        blah
   *    }
   * This doesn't mean you need to do it. It means you need to not be married
   * to your way :).
   */
  for(int i=0; i<max; i++)
    {
      /* Probably not a consideration here BUT -- always put the most decisive
       * boolean statement first:
       *    (most likely to fail) and / or (less likely to fail)
       * basically, know the order that booleans are checked, and use that to
       * your advantage. bools in c++ and python are evaluated left to right (I
       * think?? check that), so think of them as a nested loop. You want to
       * break out of it as soon as possible.
       */
      if( (i%3)==0 || (i%5)==0 ) sum += i;
    }
  cout << "The sum is " << sum << endl;
  return sum;
}

int main()
{
  int max=1000;
  return pb1(max);
}
