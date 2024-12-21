#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#define MAX_VALUE 1000

using namespace::std;

int main()
{
    int a, b;
    cin >> a >> b;
    cin.ignore();

    string line;
    vector<int> small_vec;
    vector<vector<int>> large_vec;
    int num;
    for(int i=0;i<a;i++){
        small_vec.clear();
        getline(cin, line);
        istringstream iss(line);
        while(iss >> num){
            small_vec.push_back(num);
        }
        large_vec.push_back(small_vec);
    }

    int min_value;
    int min_set;
    vector<int> need_set;
    for(int i=0;i<b;i++){
        min_value = MAX_VALUE + 1;
        for(int j=0;j<a;j++){
            if(large_vec[j][i] < min_value){
                min_value = large_vec[j][i];
                min_set = j;
            }
            
        }
        if(find(need_set.begin(), need_set.end(), min_set) == need_set.end()){
            need_set.push_back(min_set);
        }
    }

    cout << need_set.size() << endl;
    return 0;
}