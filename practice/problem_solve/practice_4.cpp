#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    const int LENGTH_REQUEST1 = 6; //"request1の文字数"
    const string REQUEST2 = "request2"; //直書き防止のrequest2の定数化
    int query_num;
    cin >> query_num;
    cin.ignore();

    vector<string> stack_query = {"start"};
    string line;
    string request;

    for(int i=0;i<query_num;i++){
        getline(cin, line);
        if(line == REQUEST2 ){
            stack_query.pop_back();
        } else {
            request = line.substr(LENGTH_REQUEST1); 
            if (stack_query.back() != request){
                stack_query.push_back(request);
            }
        }
        cout << stack_query.back() << endl;
    }

    return 0;
}