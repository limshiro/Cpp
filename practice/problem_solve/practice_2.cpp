#include <iostream>
#include <vector>

using namespace std;
int main(void){
    int T, B, U, D, L, R;
    cin >> T >> B >> U >> D >> L >> R;

    vector<int> TBset = {T,B};
    vector<int> UDset = {U,D};
    vector<int> LRset = {L,R};

    if(T<B) TBset = {B,T};
    if(U<D) UDset = {D,U};
    if(L<R) LRset = {R,L};

    int N;
    cin >> N;
    int num;
    vector<int> step;
    for(int i=0;i<N;i++){
        cin >> num;
        step.push_back(num);
    }
    
    int counter=0;
    vector<int> two_step_set;
    for(int i=0;i<N-1;i++){
        if(step[i] > step[i+1]){
            two_step_set = {step[i], step[i+1]};
            if(two_step_set == TBset || two_step_set == UDset || two_step_set == LRset) counter += 2;
            else counter++;
        } else if(step[i] < step[i+1]){
            two_step_set = {step[i+1], step[i]};
            if(two_step_set == TBset || two_step_set == UDset || two_step_set == LRset) counter += 2;
            else counter++;
        }
    }
    
    cout << counter << endl;
}