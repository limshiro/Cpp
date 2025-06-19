#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    vector<string> maze = {
        "1111111",
        "1001000",
        "1010011",
        "1000001",
        "1111111"
    };

    int Height = maze.size();
    int Width = maze[0].size();

    pair<int, int> start = {1, 2};
    pair<int, int> goal = {1, 6};

    vector<pair<int, int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };

    vector<vector<bool>> visited(Height, vector<bool>(Width, false));
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        cout << "現在地: (" << x << "," << y << ")" << endl;
        if(x==goal.first && y==goal.second){
            cout << "ゴールに到着しました！" << endl;
            break;
        }

        for(auto [dx, dy] : directions){
            int nx = x + dx;
            int ny = y + dy;

            if(nx>=0 && nx<Height && ny>=0 && ny<Width && !visited[nx][ny] && maze[nx][ny] == '0'){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}