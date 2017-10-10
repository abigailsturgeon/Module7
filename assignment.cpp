#include <iostream>

using namespace std;

class Counter
{
private:
    unsigned int count;     // count

public:
    Counter():count(0)    // constructor with no args
    {};
    Counter(int c):count(c)     // constructor with arg
    {};

    unsigned int getcount()     // return count
    {
        return count;
    }
    // The operator keyword is used to overload the operator in hand
    Counter operator ++()      // increment prefix
    {
        ++count;
        return Counter(count);
    }

};

int main()
{
    Counter c1, c2, c3;
    cout << "C1 = " << c1.getcount() << endl;
    cout << "C2 = " << c2.getcount() << endl;
    ++c1;
    ++c2;
    cout << "C1 = " << c1.getcount() << endl;
    cout << "C2 = " << c2.getcount() << endl;
    c3 = ++c1;
    cout << "C3 = " << c3.getcount() << endl;
    return 0;
}