//Problem #20 Circle Area Inscribed in a Square

#include <iostream>


using namespace std;

float readSquareSide()
{
    float A;

    cout << "Please enter square side A ? " << endl;
    cin >> A;

    return A;
}

float circleAreaInscribedInSquare(float A)
{
    const float PI = 3.141592653589793238;
    return (PI * A * A) / 4;

}

void printResult(float Area)
{
    cout << "\nCircle Area = " << Area << endl;
}

int main()
{
    printResult(circleAreaInscribedInSquare(readSquareSide()));

    return 0;
}