// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int end = n;
        int start = 1;
        while (true){
            int mid =  (end + start) / 2;
            if(mid == end || mid == start){
                if(isBadVersion(start))
                    return start;
                else
                    return end;
            }
            if(isBadVersion(mid)){
                end = mid;
            }
            else{
                start = mid;
            }
        }
    }

};
