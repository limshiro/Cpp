#include <iostream>
#include <vector> 
#include <sstream>
#include <string>
#include <algorithm>

#define MAX_PRICE 1000

using namespace std;
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    int N, K;
    cin >> N >> K;
    cin.ignore();
    string get_price;
    int price;
    vector<int> price_tb;
    
    for(int i=0;i<N;i++){
        getline(cin, get_price);
        istringstream iss(get_price);
        while(iss>>price){
            price_tb.push_back(price);
        }
    }
    
    
    /*
    for( const auto& p : price_tb){
        cout << p << endl; 
    }
    */
    
    vector<int> trans_price_tb;
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            trans_price_tb.push_back(price_tb[K*j+i]);
        }
    }
    
    /*
    cout << "---" << endl;
    
    for( const auto& t : trans_price_tb){
        cout << t << endl; 
    }
    */

    int min_price;
    int store_num;
    vector<int> must_visit;
    for(int i=0;i<N*K;i++){
        if(i%N==0) min_price = MAX_PRICE + 1;
        if(trans_price_tb[i]<min_price){
            min_price = trans_price_tb[i];
            store_num = i%N;
        }
        if(i%N == N-1){
            if(find(must_visit.begin(), must_visit.end(), store_num) == must_visit.end()){
                must_visit.push_back(store_num);
            }
        }
        
    }
    
    cout << must_visit.size() << endl;
    
    
    return 0;
}