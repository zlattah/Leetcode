#include <iostream>
#include <vector>
using namespace std;

int sort_and_count(vector<int> l){
    //split l into two halves.
    if (l.size()<0) return 0;
    int n = l.size();
    vector<int> l1(l.begin(), l.end() - n/2);
    vector<int> l2(l.begin() + n/2, l.end());
    int r1 = sort_and_count(l1);
    int r2 = sort_and_count(l2);
    int r3 = merge_and_count(l1,l2);
    vector<int> merged = merge_lists(l1,l2);
    return r1 + r2 + r3 + sort_and_count(merged);
}
int merge_and_count(vector<int>l1, vector<int>l2){
    vector<int> res;
    int count = 0;
    int i =0, j=0;
    while (i<l1.size() && j<l2.size()){
        if (l1[i]<l2[j]){
            res.push_back(l1[i]);
            i++;
        }
        else{
            res.push_back(l2[j]);
            j++;
            count += l1.size() - i;
        }
    }
    while(i<l1.size()){
        res.push_back(l1[i]);
        i++;
    }
    while(j<l2.size()){
        res.push_back(l2[j]);
        j++;
    }
    return count;
}
vector<int> merge_lists(vector<int>l1,vector<int>l2){
    vector<int> res;
    int i =0, j=0;
    while (i<l1.size() && j<l2.size()){
        if (l1[i]<l2[j]){
            res.push_back(l1[i]);
            i++;
        }
        else{
            res.push_back(l2[j]);
            j++;
        }
    }
    while(i<l1.size()){
        res.push_back(l1[i]);
        i++;
    }
    while(j<l2.size()){
        res.push_back(l2[j]);
        j++;
    }
    return res;
}
int main(){
    return 0;
}