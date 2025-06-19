#include <iostream>
#include <vector>

using namespace std;

vector<int> madeQsort(vector<int> arr)
{
    if(arr.size()>1){
        int pivot = arr[0];
        int vec_size = arr.size();
        vector<int> smaller, larger;
        for (auto num : arr){
            if(num<pivot) smaller.push_back(num);
            else larger.push_back(num);
        }

        cout << "processing : " << vec_size << endl;

        vector<int> sorted_smaller = madeQsort(smaller);
        vector<int> sorted_larger = madeQsort(larger);

        copy(sorted_larger.begin(), sorted_larger.end(), back_inserter(sorted_smaller));

        return sorted_smaller;
    } else {
        cout << "reached one or zero" << endl;
        return arr;
    }
}

/*
vector<int> count_sort(vector<int> arr)
{
    if(!arr.empty()){
        int size = arr.size();
    } else {
        return arr;
    }
}
*/

int main()
{
    vector<int> test = {4,5,2,6,1,3};
    vector<int> sorted = madeQsort(test);
    for(auto r : test){
        cout << r << ", "; 
    }
    cout << endl;
    return 0;
}