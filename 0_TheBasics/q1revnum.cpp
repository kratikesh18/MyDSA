#include <iostream>
using namespace std;
int revnum(int n)
{
    int ans=0;
    while(n!=0)
    {
         ans = ans * 10 + n % 10;
        n /= 10;
    }

return ans;
}
int main()
{

    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << "the reverse of the num is: " << revnum(num) << endl;
    return 0;
}