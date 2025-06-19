#include <iostream>
#include <vector>

using namespace std;

class SShort{
    vector<short> val;

    SShort(): val(1, 0){
        val[0] = 0;
    }
};

SShort add(SShort num1, SShort num2)
{
    return num1;
}