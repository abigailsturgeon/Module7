// File: mytime.cpp
// Created by Abigail Sturgeon on 10/12/2017 for CS1410.
// Copyright (c) 2017 WSU

#include <iostream>

using namespace std;

// Constants, Structure, Classes
class time12
{
private:        // true = pm, false = am
    bool pm;
    int hrs;
    int mins;
public:
    time12() : pm(true), hrs(0), mins(0)
    {}
    time12(bool ap, int h, int m)
    {
        pm = ap;
        hrs = h;
        mins = m;
    }
    void display() const    // Format: 12:24 p.m.
    {
        cout << hrs << ':';
        if(mins < 10)
            cout << '0';
        cout << mins << ' ';
        /*  if(pm)
              am_pm = "p.m."
          else
              am_pm = "a.m."
         */ // Same as:
        string am_pm = pm ? "p.m" : "a.m.";
        cout << am_pm;
    }
};
class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time24(): hours(0), minutes(0), seconds(0)      // Default constructor no arguments
    {}
    time24(int h, int m, int s)       // Constructor with arguments
    {
        hours = h;
        minutes = m;
        seconds = s;
    }
    void display() const        // Format: 23:13:01 HH:MM:SS
    {
        if(hours < 10)
            cout << '0';
        cout << hours << ":";

        if(minutes < 10)
            cout << '0';
        cout << minutes << ":";

        if(seconds < 10)
            cout << '0';
        cout << seconds;
    }
    operator time12() const;
};
time24::operator time12() const
{
    int hrs24 = hours;
    bool pm = hours < 12 ? false : true;        // Find am or pm
    int roundMins = seconds < 30 ? minutes : minutes+1;
    if(roundMins == 60)     // Carry mins?
    {
        roundMins = 0;
        ++hrs24;
        if(hrs24 == 12 || hrs24 == 24)
            pm = (pm == true) ? false : true;       // Toggle am/pm
    }
    int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
    if(hrs12 == 0)
    {
        hrs12 = 12;
        pm = false;
    }
    return time12(pm, hrs12, roundMins);
}

// Main Program Program
int main()
{
    time24 t1;
    time24 t2(18, 2, 40);
    t1.display();
    cout << endl;
    t2.display();
    cout << endl;
    time12 t3;
    time12 t4(false, 2, 40);
    t3.display();
    cout << endl;
    t4.display();
    cout << endl;
    // Convert time24 to time12
    time12 t12 = t2;
    t12.display();

    return 0;

}

// Function Definitions