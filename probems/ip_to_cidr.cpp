#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

class Solution {
    public:
        vector<string> ipToCIDR(string ip, int range) {
            vector<string> result;
            unsigned int cur = ipToInt(ip);

            while(range) {
                int step = cur & -cur;
                while (step>range) step/=2;
                int leadingZeros = power_of_2(step);
                result.push_back(ipStr(cur, leadingZeros-1));
                range -= step;
                cur += step;
            }

            return result;
        }

        int power_of_2(int n){
            int res = 0;
            while(n>0){
                n/=2;
                res++;
            }
            return res;
        }

        unsigned int ipToInt(string ip) {
            unsigned int result = 0;

            for(int i = 0, start = 0; i < 4; i++) {
                int pos = ip.find('.', start);
                result = (result << 8) + stoi(ip.substr(start, pos-start));
                start = pos+1;
            }

            return result;
        }

        string ipStr(unsigned int ip, int lz) {
            return to_string(ip>>24)        + "." +
                        to_string(ip>>16&255) + "." +
                        to_string(ip>>8&255)  + "." +
                        to_string(ip&255)     + "/" +
                        to_string(32-lz);
        }
};
int main(){
    Solution s;
    string ip = "255.0.0.7";
    vector<string> res = s.ipToCIDR(ip, 10);
    for (string s: res){
        cout<<s<<endl;
    }
    return 0;
}