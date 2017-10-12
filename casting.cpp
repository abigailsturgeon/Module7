#include <iostream>
using namespace std;

class Distance
{
private:
    const float MTF;        // Constant float meters to feet
    int feet;
    float inches;

public:
    Distance(): feet(0), inches(0.0), MTF(3.280833F)      // 1. Constructor with no arg
    {};
    Distance(int meters): MTF(3.280833F)    // 2. Constructor with 1 arg
    {
        float fltfeet = MTF * meters;       // Convert to float feet
        feet = int(fltfeet);        // Same as -- feet = static_cast<int>(fltfeet)
                                    // Feet is the integer part
        inches = 12 * (fltfeet - feet);     // Inches is what is left
    };
    Distance(int f, float i): MTF(2.280833F)       // 3.Constructor with 2 args
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
    void operator += (Distance);
    operator float() const      // Convert to inches
    {
        float fracfeet = inches/12;
        fracfeet += static_cast<float>(feet);
        return fracfeet/MTF;
    }
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
void Distance::operator += (Distance d2)
{
    feet += d2.feet;
    inches += d2.inches;
    if(inches >= 12.0)
    {
        inches -= 12.0;
        feet++;
    }
}
// Main Program Program

int main()
{
    Distance d1;        // 1. Constructor
    Distance d2(11, 6.25);      // 3. Constructor
    Distance d3(5);      // 2. Constructor
    //d1.getDist();
    float mtrs;
    cout << "Distance d1: ";
    d1.showDist();
    cout << endl;
    cout << "Distance d2: ";
    d2.showDist();
    cout << endl;
    mtrs = static_cast<float>(d2);      // User conversion operator
    cout << "Distance d2: " << mtrs << "meters" << endl;
    // Add binary operator
    d3 = d1 + d2;
    cout << "Distance d3: ";
    d3.showDist();
    cout << endl;
    d2 += d3;
    cout << "Distance d2: ";
    d2.showDist();
    cout << endl;
    return 0;

}

// Function Definitions