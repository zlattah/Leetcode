#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <limits>
#include <climits>
using namespace std;

int minmoves(string s){
    if (s.size() == 0) return 0;
    int minUDmoves = 0; // minimum moves you need to just change the letters from 'A' to your wanted letter
    int minLRmoves = INT_MAX; // minimum moves you need to get to all the letters you need to change

    for (int i=0;i<s.size();i++){
        int upmoves = s[i] - 'A'; // going in order to the letter like A->B->C->D
        int downmoves = 26 - upmoves; // going backwards to the letter like A->Z->Y->X
        minUDmoves += min(upmoves,downmoves);
    }
    // minUDmoves done.

    
    // Find all substrings of leters you need to change
    vector<pair<int,int>> needvisit; //beginning and end of the fragment you need to change
    for (int i=0;i<s.size();i++){
        if (s[i] != 'A'){
            int leftborder = i;
            while (i<s.size() && s[i] != 'A') i++; //find the next letter you dont need to change
            int rightborder = i-1;
            needvisit.push_back(make_pair(leftborder,rightborder));
        }
    }

    int currentmoves = 0;
    if (needvisit.size()>1){
        for (int i=0;i<needvisit.size()-1;i++){
            // see if its better to visit them from the front or the back first
            int side1 = needvisit[i].second;
            int side2 = s.size() - needvisit[i+1].first;
            if (side1<=side2){
                currentmoves = 2*side1 + side2;
            } else {
                currentmoves = side1 + 2*side2;
            }

            if (currentmoves < minLRmoves){
                minLRmoves = currentmoves;
            }
        }
        // See if its better to visit all at once
        int side1 = needvisit[needvisit.size()-1].second;
        int side2 = s.size() - needvisit[0].first;
        if (min(side1,side2)<minLRmoves) minLRmoves = min(side1,side2);

    } else if (needvisit.size() == 1){
        int side1 = needvisit[0].second;
        int side2 = s.size() - needvisit[0].first;
        minLRmoves = min(side1, side2);
    } else {
        minLRmoves = 0;
    }

    return minUDmoves + minLRmoves;
}
int main(){
    int T;
    cin>>T;
    string s;
    while(T--){
        cin>>s;
        cout<<minmoves(s)<<endl;
    }
    return 0;
}