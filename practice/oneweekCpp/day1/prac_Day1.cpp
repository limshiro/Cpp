#include <iostream>
#include <string>

using namespace std;

bool judge(int n);

int main()
{
    int n;
    cout << "数字を入力：" << endl;
    cin >> n;
    if(judge(n)){
        cout << "数" << n << "はゼロより大きい" << endl;
    }
    else{
        cout << "数" << n << "はゼロより小さい" << endl;
    }
    return 0;
}

bool judge(int n)
{
    if(n >= 0)
        return true;
    else
        return false;
}