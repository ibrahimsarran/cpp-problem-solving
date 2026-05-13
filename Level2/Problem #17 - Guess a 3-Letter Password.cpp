// Problem #17/2 - Guess a 3-Letter Password
#include <iostream>
#include <string>
using namespace std;

string readPassword(string message)
{
    string password = "AAA";
    
   
        cout << message;
        cin >> password;

    return password;

}
bool guessPassword(string password)
{
    string word = "";
    int counter = 1;
    for (int i = 65 ; i <= 90; i++)
    {
        
        for (int j = 65; j <= 90; j++)
        {
            
            for (int k = 65; k <= 90; k++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);

                cout << "Trial[" << counter << "]:" << word << endl;
                if (word == password)
                {
                    cout << "\nPassword is " << word << endl;
                    cout << "\nFound After " << counter << " Trial(s)." << endl;
                    return true;
                }
                counter++;
                word = "";

              
            }
            
            
        }

        cout << "\n----------------------\n";

    }
    return false;
}


int main()
{
    guessPassword(readPassword("Enter a 3-letter uppercase password (AAA to ZZZ): "));

    return 0;
}