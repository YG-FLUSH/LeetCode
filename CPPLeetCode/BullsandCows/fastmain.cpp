#include<iostream>
#include<sstream>
#include<assert.h>

using namespace std;

string IntToString(int n){
    stringstream result;
    result << n;
    return result.str();
}

class Solution{
    public:
        string getHint(string secret, string guess){
            int secretarr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int guessarr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            int bull=0, cows=0;
            for(int i=0; i < secret.length(); i++){
                if(secret[i] == guess[i]){
                    ++bull;
                }
                else{
                    ++secretarr[secret[i] - '0'];
                    ++guessarr[guess[i] - '0'];
                }
            }

            for(int i=0; i < 10; ++i){
                cows += min(secretarr[i], guessarr[i]);
            }
            return IntToString(bull) + 'A' + IntToString(cows) + 'B';
        }
};

int main(){
    assert(Solution().getHint("1807", "7810") == "1A3B");
    assert(Solution().getHint("1123", "0111") == "1A1B");
}
