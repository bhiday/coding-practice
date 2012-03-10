#include <iostream>

using namespace std;

int main()
{
    unsigned int cases;
    cin >> cases;
    while (cases != 0)
    {
        unsigned int num;
        cin>> num;
        unsigned int pow5 = 5;
        int count = 0;
        while (pow5 <= num)
        {
            count += num / pow5;
            pow5 *= 5;
        }
        cout << count << endl;
        cases--;
    }
    return 0;
}

