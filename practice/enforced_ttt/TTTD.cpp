#include <iostream>
#include <vector>

using namespace std;

class Field{
    public:
        vector<vector<bool>> o_f;
        vector<vector<bool>> x_f;
        char mode;

    Field() : o_f(3, vector<bool>(3,false)), x_f(3, vector<bool>(3, false)) {
        mode = 'o';
    }

    void mode_change(){
        if(mode=='o') mode = 'x';
        else if(mode=='x') mode = 'o';
        else{
            cout << "code incl typo in mode_change" << endl;
        }
    }

    bool insert_sig(int num){
        bool err_flag = false;

        if(num<1 || 9<num)  err_flag = true;
        if(mode!='o' && mode!='x'){
            cout << "code incl typo in insert_sig" << endl;
            return false;
        }

        int num_x = (num-1)%3;
        int num_y = (num-1)/3;

        if(!err_flag && !o_f[num_y][num_x] && !x_f[num_y][num_x]){
            if(mode=='o')    o_f[num_y][num_x] = true;
            else x_f[num_y][num_x] = true;
        } else {
            cout << "Error: " << num << " is invalid." << endl;
            return false;
        }
        return true;
    }

    bool display(){
        int x, y;
        int idx;
        for(y=0;y<3;y++){
            for(x=0;x<3;x++){
                idx = 3*y + x;
                if(o_f[y][x]) cout << 'o';
                else if(x_f[y][x]) cout << 'x';
                else cout << idx+1;
                
                if(x<2) cout << '|';
                if(x==2) cout << endl;
            }
        }
        return true;
    }

    private:
        vector<vector<bool>> inv_board(vector<vector<bool>> board){
            vector<vector<bool>> result(3, vector<bool>(3, false));
            for(int y=0;y<3;y++){
                for(int x=0;x<3;x++){
                    result[y][x] = board[y][2-x];
                }
            }
            return result;
        }    
};

bool pipeline(Field);

int main()
{
    Field f;
    pipeline(f);
    return 0;
}

bool pipeline(Field f)
{
    int getnum=0;

    int counter=0;
    f.display();
    while(counter<5){
        cout << f.mode << ">> ";
        cin >> getnum;
        if(f.insert_sig(getnum)){
            f.mode_change();
            f.display();
        }
        counter++;
    }
    return true;
}