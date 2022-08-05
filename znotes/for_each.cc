#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void addOne(int &n){
    ++n;
}

int main(){
    int arr [5] = {1,2,3,4,5};
    for_each(arr, arr+5, addOne);
    for (auto i : arr){
        cout << i << endl;
    }

    vector<int> v {1,2,3,4,5};
    for_each(v.begin(), v.end(), addOne);
    for (auto i : v){
        cout << i << endl;
    }

    try{
        int fail = v[6];
        throw 2;
    } catch (...){
        cout << "hi" << endl;
    }

    cout << v[6];
}