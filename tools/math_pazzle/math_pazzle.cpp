#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "exprtk.hpp"

using namespace std;

char oper[] = {'+', '-', '*', '/'};

int main()
{
    int a=1, b=2;

    string result = to_string(a) + oper[2] + to_string(b);
    cout << result;
}

