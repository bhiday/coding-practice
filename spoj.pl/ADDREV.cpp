#include <iostream>

using namespace std;

void rev(int &num)
{
    int rev = 0;
    while (num != 0)
    {
        int digit = num % 10;
        num = num / 10;
        rev = 10 * rev + digit;
    }
    num = rev;
}

int main()
{
    int cases;
    cin >> cases;
    while (cases != 0)
    {
        int num1, num2, ans;
        cin >> num1 >> num2;
        rev(num1);
        rev(num2);
        ans = num1 + num2;
        rev(ans);
        cout<< ans << endl;
        cases--;
    }
    return 0;
}

