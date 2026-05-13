// Problem #16/2 - print Words From AAA to ZZZ
#include <iostream>
#include <string>
using namespace std;

void printFrom_AAA_To_ZZZ()
{
    
    for (int i = 65 ; i <= 90; i++)
    {
        
        for (int j = 65; j <= 90; j++)
        {
            
            for (int k = 65; k <= 90; k++)
            {

                cout << char(i) << char(j) << char(k) << endl;

              
            }
            

        }

        cout << "\n----------------------\n";

    }
    
}


int main()
{
    printFrom_AAA_To_ZZZ();

    return 0;
}