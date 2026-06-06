#include <bits/stdc++.h>
using namespace std;

// use a hashmap then store frequency first in pair and sort TC = O(n + mlogm) SC = O(m) 
// if only ascii values used then m is constant so TC  =O(n) SC = O(1)
string frequencySort(string s) {
   int n = s.size();
   unordered_map <char,int> mpp; // hashmap
   string final = {}; // answer
        for(int i = 0; i < n ; i++) mpp[s[i]]++; // upating hashmap TC = O(n)
      vector<pair<int,char>> p; 
      int m = mpp.size();
      for(auto it : mpp) p.push_back({it.second,it.first}); // storing characters frequency first
        sort(p.begin(),p.end()); // ascending order TC = O(mlogm)
        reverse(p.begin(),p.end()); // descendign order TC = O(m)
        // string(freq,char) creates string of char freq times
        for(int i = 0 ; i < m ; i++) final += string(p[i].first,p[i].second); // updating the answer
        return final;
    }

// iterate through the string and update count and store its max TC = O(n) SC = O(1)
int maxDepth(string s) {
    int count =0;
    int ans = INT_MIN;
    for(char c : s) {
      if(c == '(') count++;
      else if(c == ')') count--;
      ans = max(ans,count);
    }
    return ans;
    }

// used conditional stamenets to update sum TC = O(n) SC = O(1)
// int romanToInt(string s) {
//    int n = s.size();
//    int sum = 0;
//    for(int i = 0 ; i < n; i++){
//     if(i != n-1){
//         if(s[i] == 'I' && s[i+1] == 'V') {sum += 4; i += 1; continue;}
//         else if(s[i] == 'I' && s[i+1] == 'X') {sum += 9;i += 1; continue;}
//         else if (s[i] == 'X' && s[i+1] == 'L') {sum += 40;i += 1; continue;}
//         else if (s[i] == 'X' && s[i+1] == 'C') {sum += 90;i += 1; continue;}
//         else if(s[i] == 'C' && s[i+1] == 'D') {sum += 400;i += 1; continue;}
//         else if (s[i] == 'C' && s[i+1] == 'M') {sum += 900;i += 1; continue;}
//     }
//           if(s[i] == 'I') sum += 1;
//           else if(s[i] == 'V') sum += 5;
//           else if(s[i] == 'X') sum += 10;
//           else if(s[i] == 'L') sum += 50;
//           else if(s[i] == 'C') sum += 100;
//           else if(s[i] == 'D') sum += 500;
//           else if(s[i] == 'M') sum += 1000;
//           else return -1;
//    }     
//    return sum;
//     }

// save the value of char in unordered map and subtract from sum if value of current is smaller than next 
int romanToInt(string s){
    int n = s.size();
    int sum = 0;
    unordered_map <char,int> roman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
for(int i = 0 ; i< n-1; i++){
    if(roman[s[i]] < roman[s[i+1]]) sum -= roman[s[i]]; // constitutes the six cases
    else sum += roman[s[i]]; // all other instances
}
return sum + roman[s[n-1]]; // adding the last character
}

// iterate from start of the string to the end while simulating every condition TC = O(n) SC = O(1)
int myAtoi(string s) {
int n = s.size();
int i = 0;
// ignoring starting whitespaces
while(i < n && s[i] == ' ')i++;
// determining the sign
int sign = 1;
if(i < n && (s[i] == '+' || s[i] == '-')){sign = (s[i] == '-') ? -1 : 1; i++;}
// ignoring leading zeros
while(i < n && s[i] == '0') i++;
// initilising answert and limit
long long num = 0;
long long limit = (sign == -1) ? -(long long)INT_MIN : INT_MAX;
// parsing string and cheking overflow
while( i < n && s[i] >= '0' && s[i] <= '9'){
   int digit = s[i] -'0';
   if(num > (limit-digit)/10) {num = limit;break;}
   else num = num*10 + digit;
   i++;
}
return (int)(num*sign);
}

// use sliding window to control number of distinct characters in substring 
int atmost_kdistinct(string &s, int k){
    int n = s.size();
    int count = 0; // number of substring 
    int left = 0; // left pointer
unordered_map <char,int> mpp; // hashmap
// iterating through the string using right pointer
for(int right = 0; right < n ; right++){
mpp[s[right]]++; // updating map
while(mpp.size() > k){ // shrinking the window by moving left pointer
    mpp[left]--;
    if(mpp[left] == 0) mpp.erase(left);
    left++; // reduing the number of distinct
}
// number of substring in current window
count += right-left+1;
}
return count;
}

// use helper function TC = O(n) SC = O(n) 
int exactly_kdistinct(string &s,int k){return atmost_kdistinct(s,k) - atmost_kdistinct(s,k-1);}

// string longestPalindrome(string s) {
// int n = s.size();
// if( n == 1 || n == 2) return s;
// int centre = n/2;
// int left = centre -1;
// int right = centre +1;
// int length = 0;
// string final = {};
// while(left >= 0 && right < n){
//     if(s[left] == s[right]){if(right-left+1 > length ){length = right-left+1;final = s.substr(left,length);}; left--;right++;}
//     else {
//         centre++;
//         left = centre - 1;
//         right = centre + 1;
// }
//     }
// centre = n/2;
// left = centre -1;
// right = centre +1;
// while(left >= 0 && right < n ){
//     if(s[left] == s[right]){if(right-left+1 > length ){length = right-left+1;final = s.substr(left,length);}; left--;right++;}
//     else {
//         centre--;
//         left = centre - 1;
//         right = centre + 1;
// }
//     }
// if(!final.empty())return final;
// else {
//     for(int i = 1; i < n; i++) if(s[i] == s[i-1]) return s.substr(i-1,2);
//     return s.substr(0,1);
// }
// }

// iterate over the wtring and search for valid odd length and even length palindromes using while loop
// expanding around centre method TC = O(n^2) SC = O(1)
string longestPalindrome(string s) {
        int n = s.size();
        int left,right;
        pair<int,int> p = {INT_MIN,0};  // length of palindrome and starting index of palindrome respectively
        // checking for even length palindrome
        for(int i = 1 ; i< n ;i++){
            left = i-1;
            right = i;
            while( left >= 0 && right < n && s[left] == s[right]){
                if(p.first < right -left +1){  p.first = right-left+1; p.second = left;}
                left--;
                right++;
        }
        }
// checking for odd length palindrome
for(int i = 1;i < n-1;i++){
    left = i-1;
    right = i+1;
            while( left >= 0 && right < n && s[left] == s[right]){
 if(p.first < right -left +1){  p.first = right-left+1; p.second = left;}
    left--;
    right++;
    }
}
if(p.first == INT_MIN) return s.substr(0,1); // single length palindrome
return s.substr(p.second,p.first);
    }

// Iterate over all possible strings and use hashmap TC = O(n^2) SC = O(1) (map is of constant size)
int beautySum(string s) {
  int n = s.size();
  int sum = 0; // sum of beauty of substrings
  // All possible substrings TC = O(n^2)
  for(int i = 0 ; i < n ; i++){ 
    unordered_map <char,int> mpp; // hashmap
    for(int j = i ; j < n;j++){
        mpp[s[j]]++;
        int high = INT_MIN; int low = INT_MAX; // max and min freqeuncy 
        // if alphabets were unrestrained then TC = (n^3) but currently TC = O(n^2) as only 26 alphabets 
    for(auto it : mpp){
   low = min(low,it.second);
   high = max(high,it.second); 
    }
    sum += high - low;
    }
  }   
  return sum;   
    }

  
