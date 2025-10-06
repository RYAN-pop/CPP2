#include <iostream>
  
using namespace std;

void f1()
{
    char grade[10], oneGrade('a');
    int i=oneGrade;
    cout<<oneGrade<<i<<(char)98<<endl;
    cout<<(oneGrade++)<<endl;
    cout<<(++oneGrade)<<endl;
}

int main( )
   {
const int SIZE = 5;       
int i, score[SIZE], max;

auto j=score;
decltype(score) k;
f1();
cout<<score<<endl;
       cout << "Enter 5 scores:\n";
       cin >> score[0];
       max = score[0];
       
for (i = 1; i < SIZE; i++)
       {
           cin >> score[i];
           
if (score[i] > max)
               max = score[i];
           
//max is the largest of the values score[0],..., score[i].
       }
       cout << "The highest score is " << max << endl
            << "The scores and their\n"
            << "differences from the highest are:\n";
       
for (i = 0; i < 5; i++)
           cout << score[i] << " off by "<< (max - score[i]) << endl;
       
return 0;
   }
   