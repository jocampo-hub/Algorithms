#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

////// This function is a good resource that appears in interviews
int gcd(int a, int b)
{

    while (b!= 0)
    {
        int temp = b; // temporary variable b is the second number
        b = a % b; // b is now equal to the remainder of a / b.
        a = temp; // a is the second number
    }
 return a; //
}


// 7/15 -> sum of distinct unit fractions
// ceil (15 / 7) = 3, (7/15) - (1/3) = 2/ 15 [1/ 3]
// ceil(15/ 2) = 8, 2/15 - 1/8 = ? [1/3, 1/8]
// ceil(15/2) = 8, (2*8)/(15*8) - (1*15) / (8*15) = 16/120 - 15/ 120 = 1/120 [1/3, 1/8, 1/120]


vector<int> egyptianFraction(int num, int den)
{
    vector<int> result;

   while (num != 0)
  {
       int ceilVal = ceil((double) den / num);
      result.push_back(ceilVal);

       num = num * ceilVal - den;
       den = den * ceilVal;

       int gcdVal = gcd(num, den);

      num /= gcdVal;
      den /= gcdVal;
  }
 return result;
}

//// Take for example, 5/121 -> 1/33+1/121+1/363
int main() {

    vector<int> denoms = egyptianFraction(7, 15);
    for (int den : denoms)
    {
        cout << "1/" << den << " ";
    }
}

