#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    //辞書の宣言
    std::unordered_map<std::string, int> dict;
    
    //要素の挿入
    dict["apple"] = 1000;
    dict["banana"] = 2000;

    //値の出力
    std::cout << "banana: " << dict["banana"] << std::endl;

    //存在の確認
    if(dict.find("apple") != dict.end()) std::cout << "apple exists." << std::endl;

    //値を全部出力する
    for(const auto& pair : dict){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}