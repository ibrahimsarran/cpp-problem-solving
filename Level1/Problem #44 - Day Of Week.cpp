//Problem #44 - Day Of Week

#include <iostream>
#include <string>
using namespace std;
enum enWeekDays { Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7 };

void showWeekDayMenu()
{
    cout << "****************************" << endl;
    cout << "         Week days          " << endl;
    cout << "****************************" << endl;
    cout << "1: Sunday" << endl;
    cout << "2: Monday" << endl;
    cout << "3: Tuesday" << endl;
    cout << "4: Wednesday" << endl;
    cout << "5: Thursday" << endl;
    cout << "6: Friday" << endl;
    cout << "7: Saturday" << endl;
    cout << "****************************" << endl;
}

int readNumberInRange(string Message, int from, int to )
{
    int number = 0;

    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number < from || number>to);

    return number;
}

enWeekDays readDayOfWeek()
{
    return (enWeekDays)readNumberInRange("Enter a number from 1 to 7:", 1, 7);
}
string getDayOfWeek(enWeekDays day)
{

    switch (day)
    {
    case enWeekDays::Sunday:
        return "Sunday";
  
    case enWeekDays::Monday:
        return "Monday";
       

    case enWeekDays::Tuesday:
        return "Tuesday";
       

    case enWeekDays::Wednesday:
        return "Wednesday";
       

    case enWeekDays::Thursday:

        return "Thursday";
       
    case enWeekDays::Friday:

        return "Friday";
       

    case enWeekDays::Saturday:

        return "Saturday";

    default:
        return "Invalid day";

    }
}
void printDayOfWeek(string day)
{
    cout << "Today is: " << day << endl;
}

int main()
{
    showWeekDayMenu();
    printDayOfWeek(getDayOfWeek(readDayOfWeek()));
    cout << endl;
}
