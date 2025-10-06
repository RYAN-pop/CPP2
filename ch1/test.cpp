#include <iostream>
using namespace std;

int main1() {
  int myNum = 9;
  cout << myNum;
  return 0;
}
   
int main( )
   {
       
     
const double COST_PER_SQ_FT = 10.50;
 double budget, area, lengthSide;
       cout << "Enter the amount budgeted for your doghouse $";
       cin >> budget;
       area = budget / COST_PER_SQ_FT;
       lengthSide = sqrt(area);
       cout.setf(ios::fixed);
       cout.setf(ios::showpoint);
       cout.precision(2);
          cout << "For a price of $" << budget << endl
            << "I can build you a luxurious square doghouse\n"
            << "that is " << lengthSide
            << " feet on each side.\n";
       
  }