#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    t = "入力された文字列は";
    cout << "文字を入力" << endl;
    cin >> s;
    cout << t+s << "です" << endl;
    return 0;
}