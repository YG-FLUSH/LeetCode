#include<iostream>
#include<sstream>
#include<vector>
#include<assert.h>
using namespace std;

string IntToString(int n){
    stringstream result;
    result << n;
    return result.str();
}

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<bool> secret_position_flag = init_secret_position(secret);
        vector<bool> guess_position_flag = init_guess_position(guess);
        int bull = this->getBull(secret, guess,
                            &secret_position_flag,
                            &guess_position_flag);

        int cows = this->getCows(secret, guess,
                            &secret_position_flag,
                            &guess_position_flag);
        return IntToString(bull) + 'A' + IntToString(cows) + 'B';

    }

    int getBull(string secret, string guess,
                vector<bool> *secret_position_flag,
                vector<bool> *guess_position_flag){
        // 位置相同且数字相同
        //
        int count = 0;
        for(int i=0; i < secret.length(); ++i){
            if(secret[i] == guess[i]){
                ++count;
                (*secret_position_flag)[i] = false;
                (*guess_position_flag)[i] = false;
            }
        }
        return count;
    }

    int getCows(string secret, string guess,
                vector<bool> *secret_position_flag,
                vector<bool> *guess_position_flag){
        // 位置不相同但数字相同

        int count = 0;
        for(int i=0; i < secret.length(); ++i){

            if(!(*secret_position_flag)[i])
                continue;

            for(int j=0; j < guess.length(); ++j){
                if(!(*guess_position_flag)[j]) continue;

                if(secret[i] == guess[j]){
                    ++count;
                    (*secret_position_flag)[i] = false;
                    (*guess_position_flag)[j] = false;
                    break;
                }
            }
        }
        return count;
    }

    vector<bool> init_secret_position(string secret){
        vector<bool> position_flag(secret.length());
        return init_position_flag(&position_flag);
    }

    vector<bool> init_guess_position(string guess){
        vector<bool> position_flag(guess.length());
        return init_position_flag(&position_flag);
    }

    vector<bool>& init_position_flag(vector<bool> * position_flag){
        for(vector<bool>::iterator iter=position_flag->begin();
                iter < position_flag->end(); iter++){
            *iter = true;
        }
        return *position_flag;
    }
};

int main(){
    assert(Solution().getHint("1807", "7810") == "1A3B");
    assert(Solution().getHint("1123", "0111") == "1A1B");
}
