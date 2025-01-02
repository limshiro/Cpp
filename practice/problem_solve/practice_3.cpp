#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace::std;

vector<string> rd_spiral(vector<vector<string>> words, int hight, int width)
{
    int x=0, y=0;
    int min_x = 0, min_y = 0, max_x = width, max_y = hight;
    int counter = 0;

    vector<string> spiral_words;
    while(counter<hight*width){
        while(x<max_x){
            spiral_words.push_back(words[y][x]);
            x++;
            counter++;
        }
        x--; //行き過ぎた分を戻す
        y++; //次の領域へ
        min_y += 1;
        while(y<max_y){
            spiral_words.push_back(words[y][x]);
            y++;
            counter++;
        }
        y--; //行き過ぎた分を戻す
        x--; //次の領域へ
        max_x -= 1;
        while(x>=min_x){
            spiral_words.push_back(words[y][x]);
            x--;
            counter++;
        }
        x++; //行き過ぎた分を戻す
        y--; //次の領域へ
        max_y -= 1;
        while(y>=min_y){
            spiral_words.push_back(words[y][x]);
            y--;
            counter++;
        }
        y++; //行き過ぎた分を戻す
        x++; //次の領域へ
        min_x += 1;
    }

    return spiral_words;
}

int main()
{
    int hight, width;
    cin >> hight >> width;
    cin.ignore();
    int left, right;
    cin >> left >> right;
    cin.ignore();

    string line;
    string literal;
    vector<string> word;
    vector<vector<string>> words;
    for(int i=0;i<hight;i++){
        word.clear();
        //getline(cin, line);
        if (!getline(cin, line)) {
        cerr << "Failed to read input!" << endl;
        return 1; // 入力が失敗したら終了
        }
        for(int j=0;j<width;j++){
            literal = line.at(j);
            word.push_back(literal);
        }
        words.push_back(word);
    }
    
    vector<string> ans;
    ans = rd_spiral(words, hight, width);

    for(int i=left-1;i<right;i++){
        cout << ans[i];
    }
    return 0;
}