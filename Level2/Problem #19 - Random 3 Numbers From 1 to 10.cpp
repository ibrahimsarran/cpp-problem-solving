// Problem #19/2 - Random 3 Numbers From 1 to 10 
#include <iostream>
#include <cstdlib>
using namespace std;


int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}



int main()
{
    srand((unsigned)time(NULL));
    
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;
    cout << randomNumber(1, 10) << endl;

    return 0;

}