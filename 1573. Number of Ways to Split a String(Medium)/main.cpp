#include <string>

using namespace std;
class Solution {
private:
    long long factorial(int n) {
        long long result = 1;
        for (int i = 2; i <= n; i++) {
            result = ((result%mod)*(i%mod)) % mod;
        }
        return result;
    }
public:
    long long mod = 1e9 + 7;
    int numWays(string s) {
        int numberOfOnes = 0;
        for (char c : s){
            if (c == '1') numberOfOnes++;
        }
        if (numberOfOnes%3 != 0) return 0;
        else if (numberOfOnes == 0) return int(((s.length()-1)*(s.length()-2)/2)%mod);
        int partNumberOfOnes = (int)numberOfOnes/3;
        long long partOneZeros = 0, partTwoZeros = 0;
        int partOneOnes = 0, partTwoOnes = 0;
        for (char c : s){
            if (c == '1'){
                if (partOneOnes != partNumberOfOnes)partOneOnes++;
                else if (partTwoOnes != partNumberOfOnes)partTwoOnes++;
                else break;
            }
            else{
                if (partTwoOnes == partNumberOfOnes)partTwoZeros++;
                else if (partOneOnes == partNumberOfOnes && partTwoOnes == 0) partOneZeros++;
            }
        }
        return ((++partOneZeros % mod)*(++partTwoZeros % mod)) % mod;
    }
};
