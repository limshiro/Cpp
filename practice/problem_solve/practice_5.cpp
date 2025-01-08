#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//入力形式e.g. 5 La_3 Lb_2 Lb_5 Ra_1 Rb_4

bool judge_key(vector<string> need_key)
{
    vector<set<int>> regions;
    set<int> setLa, setLb, setRa, setRb;
    int key_num = stoi(need_key[0]);

    //setに突っ込む処理
    for(auto i=0;i<key_num;i++){
        if(need_key[i+1][0] == 'L' && need_key[i+1][1] == 'a')  setLa.insert(need_key[i+1][3] - '0');
        else if(need_key[i+1][0] == 'L' && need_key[i+1][1] == 'b')  setLb.insert(need_key[i+1][3] - '0');
        else if(need_key[i+1][0] == 'R' && need_key[i+1][1] == 'a')  setRa.insert(need_key[i+1][3] - '0');
        else setRb.insert(need_key[i+1][2] - '0');
    }
    if(!setLa.empty()) regions.push_back(setLa);
    if(!setLb.empty()) regions.push_back(setLb);
    if(!setRa.empty()) regions.push_back(setRa);
    if(!setRb.empty()) regions.push_back(setRb);
    
    /*
    for(auto j=0;j<regions.size();j++){
    cout << "Checking region " << j << ": ";
        cout << *regions[j].begin();
    cout << endl;
    }
    */
    
    //判定処理
    if(regions.size()>=3) return false; //impossible
    else if(regions.size() <= 1) return true; //possible
    else {
        for(auto j=0;j<regions.size();j++){
            if(regions[j].count(1)>0 && regions[j].count(6)>0){
                return false; //impossible
            }
        }
        return true;
    }
    
    return true;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();

    string line;
    vector<vector<string>> need_keys;
    vector<string> need_key;
    string key;

    for(int i=0;i<N;i++){
        getline(cin, line);
        istringstream iss(line);
        while(iss>>key){
            need_key.push_back(key);
        }
        need_keys.push_back(need_key);
        need_key.clear();
    }

    for(auto i=0;i<N;i++){
        if(!judge_key(need_keys[i])) cout << i+1 << endl;
    }
}
