#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Field{
    public:
    char mode;

    Field(): o_f(3*3*3*3, false), x_f(3*3*3*3, false){
        mode = 'o';
    }

    bool insert_sig(const int num){
        if(num<0 || 81 <= num || num == (81-1)/2){
            cout << "Error: This position is out of range." << endl;
            return false;
        }

        if(o_f[num] || x_f[num]){
            cout << "Error: This position is already filled." << endl;
            return false;
        } else if(mode == 'o'){
            o_f[num] = true;
        } else {
            x_f[num] = true;
        }
        mode_change();
        return true;
    }
     
    void display_str(){
        int w, x, y, z;
        int disp_idx, idx; 
        
        for(auto wi=1;wi<=3;wi++){
            cout << "Dim:" << wi;
            if(wi<3)    cout << "                     | ";
            else cout << endl;
        }

        string s0;
        for(y=0;y<3;y++){
            s0 = "";
            for(w=0;w<3;w++){
                for(z=0;z<3;z++){
                    for(x=0;x<3;x++){
                        disp_idx = 3*y + x + 1;
                        idx = 27*w + 9*z + 3*y + x;
                        
                        if(idx == (81-1)/2){
                            s0 += color("Q", 33);
                        } else if(o_f[idx]){
                            s0 += color("o", 32);
                        } else if(x_f[idx]){
                            s0 += color("x", 31);
                        } else {
                            s0 += to_string(disp_idx);
                        }

                        if(x<2) s0 += "|";
                    }
                    if(z<3-1) s0 += "     ";
                }
                if(w<3-1) s0 += " | ";
                else cout << s0 << endl;
            }
        }
    }
    
    /*void display(){
        int w, x, y, z;
        int disp_idx, idx; 
        
        for(auto wi=1;wi<=3;wi++){
            cout << "Dim:" << wi;
            if(wi<3)    cout << "                     | ";
            else cout << endl;
        }

        for(y=0;y<3;y++){
            for(w=0;w<3;w++){
                for(z=0;z<3;z++){
                    for(x=0;x<3;x++){
                        disp_idx = 3*y + x + 1;
                        idx = 27*w + 9*z + 3*y + x;
                        
                        if(idx==(81-1)/2){
                            cout <<"\033[33mQ\033[m";
                            goto cutQ;
                        }
                        if(o_f[idx])    cout << "\033[32mo\033[m";
                        else if(x_f[idx])   cout << "\033[31mx\033[m";
                        else cout << disp_idx;
                        
                        cutQ:
                        if(x<3-1) cout << "|";
                    }
                    if(z<3-1) cout << "     ";
                }
                if(w<3-1) cout << " | ";
                else cout << endl;
            }
        }
    }
    */

    bool judge(){
        if(judge_4D(o_f)){
            cout << "o win!" << endl;
            return true;
        } else if(judge_4D(x_f)){
            cout << "x win!" << endl;
            return true;
        } else {
            for(auto i=0;i<81;i++){
                if(o_f[i]||x_f[i]) continue;
                else return false;
            }
            cout << "Even" << endl;
            return true;
        }
    }
    
    private:
    vector<bool> o_f;
    vector<bool> x_f;

    void mode_change(){
        if(mode=='o') mode = 'x';
        else if(mode=='x') mode = 'o';
        else{
            cout << "code incl typo in mode_change" << endl;
        }
    }

    string color(string s, int id){
        return "\033[" + to_string(id) + "m" + s + "\033[m";
    }

    vector<bool> _4Dto3D(const vector<bool> f, int idx, char fixed){
        vector<bool> result;

        if(fixed == 'w'){
            for(auto i = 27*idx; i<27*(idx+1); i++) result.push_back(f[i]);
        } else if(fixed == 'z'){
            for(auto w =0; w<3; w++){
                for(auto y =0; y<3; y++){
                    for(auto x =0; x<3; x++){
                        result.push_back(f[27*w + 9*idx + 3*y + x]);
                    }
                }
            }
        } else if(fixed == 'y'){
            for(auto w =0; w<3; w++){
                for(auto z =0; z<3; z++){
                    for(auto x =0; x<3; x++){
                        result.push_back(f[27*w + 9*z + 3*idx + x]);
                    }
                }
            }
        } else if(fixed == 'x'){
            for(auto w =0; w<3; w++){
                for(auto z =0; z<3; z++){
                    for(auto y =0; y<3; y++){
                        result.push_back(f[27*w + 9*z + 3*y + idx]);
                    }
                }
            }
        } else {
            cout << "This code incl typo" << endl;
            exit(1);
        }
        return result;
    }

    vector<bool> _3Dto2D(const vector<bool> f, int idx, char fixed){
        vector<bool> result;
        if(fixed == 'z'){
            for(auto i = 9*idx; i<9*(idx+1); i++) result.push_back(f[i]);
        } else if(fixed == 'y'){
            for(auto z =0; z<3; z++){
                for(auto x =0; x<3; x++){
                    result.push_back(f[9*z + 3*idx + x]);
                }
            }
        } else if(fixed == 'x'){
            for(auto z =0; z<3; z++){
                for(auto y =0; y<3; y++){
                    result.push_back(f[9*z + 3*y + idx]);
                }
            }
        } else {
            cout << "This code incl typo" << endl;
            exit(1);
        }
        return result;
    }

    bool judge_2D(const vector<bool> f2d){
        //縦方向
        for(int x=0;x<3;x++){
            if(f2d[x]&&f2d[x+3]&&f2d[x+6]) return true;
        }
        //横方向
        for(int y=0;y<3;y++){
            if(f2d[3*y]&&f2d[3*y+1]&&f2d[3*y+2]) return true;
        }
        //斜め方向
        if((f2d[0]&&f2d[4]&&f2d[8]) || (f2d[2]&&f2d[4]&&f2d[6])) return true;

        return false;
    }

    bool judge_3D(const vector<bool> f3d){
        char set[] = {'x', 'y', 'z'};

        for(auto cut=0;cut<3;cut++){
            for(int layer=0;layer<3;layer++){
                vector<bool> f2d = _3Dto2D(f3d, layer, set[cut]);
                if(judge_2D(f2d)) return true;
            }
        }

        int idx;
        for(int x=0; x<3; x+=2){
            for(int y=0; y<3; y+=2){
                idx = 3*y+x;
                if(f3d[idx]&&f3d[(27-1)/2]&&f3d[(27-1)-idx]){
                    return true;
                }
            }
        }

        return false;
    }

    bool judge_4D(const vector<bool> f4d){
        char set[] = {'x', 'y', 'z', 'w'};

        for(auto cut=0;cut<4;cut++){
            for(int layer=0;layer<3;layer++){
                vector<bool> f3d = _4Dto3D(f4d, layer, set[cut]);
                if(judge_3D(f3d)) return true;
            }
        }
        int idx;
        for(int x=0; x<3; x+=2){
            for(int y=0; y<3; y+=2){
                for(int z=0; z<3; z+=2){
                    idx = 9*z + 3*y + x;
                    if(f4d[idx]&&f4d[(81-1)/2]&&f4d[(81-1)-idx]){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

class Input{
    public: 
    void getinput(){
        getline(cin, in);
    }

    int converse(){
        int w=0, z=0, yx=0;

        for(char& c:in)     if(!isdigit(c)) c = ' ';
        stringstream ss(in);
        ss >> w >> z >> yx;
        if(w<1 || 3<w) return -1;
        else if(z<1 || 3<z) return -1;
        else if(yx<1 || 9<yx) return -1;
        else return 27*(w-1) + 9*(z-1) + yx - 1;
    }

    private:
    string in;
};

int main()
{
    Field f;
    f.display_str();
    cout << "Input Style:" << endl;
    cout << "Dim z number\n"<< endl;

    Input line;
    int num;
    
    while(true){
        cout << f.mode << " >> ";
        line.getinput();
        
        if(f.insert_sig(line.converse())){
            f.display_str();
            if(f.judge())   break;
        }
    }
    return 0;
}