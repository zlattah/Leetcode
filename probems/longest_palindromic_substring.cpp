#include <iostream>
#include <vector>
#include <string>
using namespace std;
//Given a string s, return the longest palindromic substring in s.
class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            int maxsize = 1;
            int starti = 0;

            vector<vector<bool>> pal(n); // for each i,j pal[i][j] says if the string s[i..j] is a palindrom
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    pal[i].push_back(false);

            for(int i=0;i<n;i++) pal[i][i] = true;
            for(int i=0;i<n-1;i++){
                if(s[i] == s[i+1]) {
                    pal[i][i+1] = true;
                    if (maxsize == 1){
                        maxsize = 2;
                        starti = i;
                    }
                }
                else pal[i][i+1] = false;
            }
            for(int len = 3; len<=n;len++){
                for (int i =0; i<n-len+1;i++){
                    int j = i+len-1;
                    if (s[i] == s[j] && pal[i+1][j-1]) {
                        pal[i][j] = true;
                        if (maxsize < len){
                            maxsize = len;
                            starti = i;
                        }
                    }
                    else pal[i][j] = false;
                }
            }
            return s.substr(starti, maxsize);
            
        }
};
int main(){
    cin.tie(0);
    Solution s;
    cout<<s.longestPalindrome("cgbjsnaba");
    return 0;
}