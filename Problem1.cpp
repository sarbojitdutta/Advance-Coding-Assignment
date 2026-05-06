#include<iostream>
#include<unordered_map>
using namespace std;

int charValue(char c){
    return c - 'a' + 1;
}

int maxCyclicSubstringSum(string s){
    int n = s.length();
    string t = s + s;

    unordered_map<char, int> freq;

    int left = 0, maxSum = 0, currSum = 0;
    for(int right = 0; right < t.size(); right++){

        freq[t[right]]++;
        currSum += charValue(t[right]);

        while(freq[t[right]] > 1 || (right - left + 1) > n){
            freq[t[left]]--;
            currSum -= charValue(t[left]);
            left++;
        }
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
int main(){
    string s = "abc";
    cout << maxCyclicSubstringSum(s) << endl;
    return 0;
}