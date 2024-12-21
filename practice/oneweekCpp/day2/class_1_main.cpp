#include <iostream>
#include "sample.h"

using namespace std;

int main()
{
    CSample obj; //クラスをインスタンス化
    int num;

    cout << "整数を入力してください:" << endl;
    cin >> num;

    obj.set(num);   //CSampleのメンバ変数をセット
    cout << obj.get() << endl;  //メンバ変数の値を出力

    return 0;
}