//Problem #45 - Month Of Year

#include <iostream>
#include <string>
using namespace std;
enum enMonthOfYear { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

void showMonthOfYearMenu()
{
    cout << "****************************" << endl;
    cout << "         Month Of Year         " << endl;
    cout << "****************************" << endl;
    cout << "1: JAN" << endl;
    cout << "2: FEB" << endl;
    cout << "3: MAR" << endl;
    cout << "4: APR" << endl;
    cout << "5: MAY" << endl;
    cout << "6: JUN" << endl;
    cout << "7: JUL" << endl;
    cout << "8: AUG" << endl;
    cout << "9: SEP" << endl;
    cout << "10: OCT" << endl;
    cout << "11: NOV" << endl;
    cout << "12: DEC" << endl;

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

enMonthOfYear readMonthOfYear()
{
    return (enMonthOfYear)readNumberInRange("Enter a number from 1 to 12:", 1, 12);
}
string getMonthOfYear (enMonthOfYear month)
{

    switch (month)
    {
    case enMonthOfYear::JAN:
        return "Jan";
  
    case enMonthOfYear::FEB:
        return "Feb";
       

    case enMonthOfYear::MAR:
        return "Mar";
       

    case enMonthOfYear::APR:
        return "Apr";
       

    case enMonthOfYear::MAY:

        return "May";
       
    case enMonthOfYear::JUN:

        return "Jun";
       

    case enMonthOfYear::JUL:

        return "Jul";
    case enMonthOfYear::AUG:

        return "Aug";
    case enMonthOfYear::SEP:

        return "Sep";
    case enMonthOfYear::OCT:

        return "Oct";
    case enMonthOfYear::NOV:

        return "Nov";
    case enMonthOfYear::DEC:

        return "Dec";

    default:
        return "Invalid month";

    }
}
void printMonthOfYear(string month)
{
    cout << "Month is: " << month << endl;
}

int main()
{
    showMonthOfYearMenu();
    printMonthOfYear(getMonthOfYear(readMonthOfYear()));
    cout << endl;
}
