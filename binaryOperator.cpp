#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    float inches;

public:
    Distance() : feet(0), inches(0.0)       // Constructor with no arg
    {};
    Distance(int f, float i)       // Constructor with 2 args
            {
                feet = f;
                inches = i;
            };
    void getDist()
    {
        cout << "\nEnter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }
    void showDist()     // Display distance
    {
        cout << feet << "\'-" << inches << "\"";
    }
    Distance operator +(Distance) const;        // Add 2 distances
    //Distance operator += (Distance);
};
// Return the sum of both
Distance Distance::operator+(Distance d2)const
{
   int f = feet + d2.feet;
    float i = inches + d2.inches;
    if(i >= 12.0)
    {
        i -= 12.0;
        f++;
    }
    return Distance(f, i);
}
// Main Program Program

int main()
{
    Distance d1, d3;
    Distance d2(11, 6.25);
    d1.getDist();
    cout << "Distance d1: ";
    d1.showDist();
    cout << endl;
    cout << "Distance d2: ";
    d2.showDist();
    cout << endl;

    // Add binary operator
    d3 = d1 + d2;
    cout << "Distance d3: ";
    d3.showDist();
    cout << endl;
    return 0;

}

// Function Definitions