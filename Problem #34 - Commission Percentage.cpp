Problem #34 - Commission Percentage
#include <iostream>
using namespace std;

float readTotalSales()
{
    float totalSales;

    cout << "Please enter Total Sales? " << endl;
    cin >> totalSales;

    return totalSales;
}

float getCommissionPercentage(float totalSales)
{
    if (totalSales >= 1000000)
        return 0.01;
    else if (totalSales >= 500000)
        return 0.02;
    else if (totalSales >= 100000)
        return 0.03;
    else if (totalSales >= 50000)
        return 0.05;
    else
        return 0.00;
}

float calculateTotalCommission(float totalSales)
{
    return getCommissionPercentage(totalSales) * totalSales;
}

int main()
{
    float totalSales = readTotalSales();

    cout << endl << "Commission Percentage = " << getCommissionPercentage(totalSales) * 100 << "%" << endl;
    cout << endl << "Total Commission = " << calculateTotalCommission(totalSales) << endl;

    return 0;
}