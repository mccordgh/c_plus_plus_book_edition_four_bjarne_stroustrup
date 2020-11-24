// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>

using namespace std;

class Vector
{
public:
    Vector(int s) : elements{ new double[s]}, size{s}
    {}

    double& operator[](int i)
    {
        return elements[i];
    }

    int getSize() const
    {
        return size;
    }

private:
    double* elements;
    int size;
};

double square(double x)
{
    return x * x;
}

void printSquare(double x)
{
    cout << "the square of " << x << " is " << square(x) << endl;
}

void printIntDoubleConversions()
{
    double d{ 2.22 };
    int i{ 7 };

    cout << d << " + " << i << " = " << (d + i) << endl;
    cout << d << " * " << i << " = " << (d * i) << endl;

    d = d + i;
    i = d * i;

    cout << d << " / " << i << endl;
}

bool acceptOne()
{
    int attempts = 1;

    while (attempts < 4)
    {
        cout << "Do you want accept #1 (y or n)?" << endl;

        char answer = 0;
        cin >> answer;

        switch (answer)
        {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            cout << "Sorry, I don't understand. Please enter y or n." << endl;
            ++attempts;
        }
    }

    cout << "I'll take that as a no, then...";
    return false;
}

void printArray(array<int, 7> arr)
{
    for (auto x : arr)
        cout << x << " ";

    cout << endl;
}

void printNumbersFromArray()
{
    array<int, 7> v{ 0, 1, 2, 3, 4, 5, 6 };

    printArray(v);

    for (auto& x : v)
        ++x;

    for (auto x : v)
        cout << x << " ";

    cout << endl;
}

double readAndSumVector(int size)
{
    Vector v(size);

    cout << "Enter " << size << " elements:" << endl;

    for (int i = 0; i != size; ++i)
        cin >> v[i];

    double sum{ 0 };

    for (int i = 0; i != size; ++i)
    {
        if (i < 0 || i >= 3) throw out_of_range("readAndSumVector");

        sum += v[i];
    }

    return sum;
}

enum class Color { red, blue, green };

enum class TrafficLight { green, yellow, red };

TrafficLight operator++(TrafficLight& t)
{
    switch (t)
    {
    case TrafficLight::green:
        return t = TrafficLight::yellow;

    case TrafficLight::yellow:
        return t = TrafficLight::red;

    case TrafficLight::red:
        return t = TrafficLight::green;
    }
}

void describeTrafficLight(TrafficLight& t)
{
    switch (t)
    {
    case TrafficLight::green:
        cout << "The light is Green" << endl;
        break;

    case TrafficLight::yellow:
        cout << "The light is Yellow" << endl;
        break;

    case TrafficLight::red:
        cout << "The light is Red" << endl;
        break;

    default:
        cout << "I'm not familiar with this color of traffic light.." << endl;
    }
}

int main()
{
    //printSquare(12.34);
    //printIntDoubleConversions();

    /*bool acceptedOne = acceptOne();

    if (acceptedOne)
    {
        cout << "#1 was excepted" << endl;
    }
    else
    {
        cout << "#1 was not excepted" << endl;
    }*/

    try
    {
        printNumbersFromArray();
        double sum = readAndSumVector(8);

        cout << "Vector's sum = " << sum << endl;
    }
    catch (out_of_range)
    {
        cout << "Out of range error!!!!";
    }

   /* Color color = Color::red;
    TrafficLight light = TrafficLight::green;

    for (int i = 0; i < 4; ++i)
    {
        describeTrafficLight(light);
        ++light;
    }*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
