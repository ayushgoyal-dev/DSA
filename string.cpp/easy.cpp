#include <bits/stdc++.h>
using namespace std;

// A primitive is the shortest substing with equal number of '(' and ')' TC = O(n) SC = O(1)
string removeOuterParentheses(string s)
{
   int n = s.size();
   int count = 0; // number or '(' and ')'
   int start = 0; // index for starting of next primitive
   string final = {};
   for (int i = 0; i < n; i++)
   {
      if (s[i] == '(')
         count++;
      else
         count--;
      if (count == 0)
      {
         string subset = s.substr(start + 1, i - start - 1); // substring of primitive excludeing outer paranthesis
         final += subset;                                    // answer
         start = i + 1;
         count = 0;
      }
   }
   return final;
}

// iterate through string from back and add words as you find them in the answer string TC = O(n) SC = O(1)
string reverseWords(string s)
{
   int n = s.size();
   int stop = -1; // stop index of a word
   string final = {};
   // iteration through the sting
   for (int start = n - 1; start >= 0; start--)
   {
   // marking the ending of the word
 if(s[start] != ' ' && stop == -1)  stop = start;
 // marking the start of the word
 else if(s[start] == ' ' && stop != -1){
   final += s.substr(start +1,stop-start) + " "; // adding the word
stop = -1; 
 }
}
if(stop != -1) final += s.substr(0,stop + 1); // adding the first word if it starts without empty space
 int m = final.size();
 if(!final.empty() && final.back() == ' ')final.pop_back(); // removing empty space at the last of final string
 return final;
}

// iterate from end of string until you find a odd integer TC = O(n) SC = O(1)
string largestOddNumber(string num) {
   int n = num.size();
    int stop = -1;
    string final = {};
  for(int i = n-1; i >= 0 ; i--)if(num[i]%2 == 1){stop =i;break;}
 if(stop != -1) final = num.substr(0,stop+1);
 return final; 
    }
 
// take min string and compare every other string with it to get ans TC = O(m*n) SC = O(1)
string longestCommonPrefix(vector<string>& strs) {
int n = strs.size();
string final = {};
int minimum = INT_MAX;
// find shortest string TC = O(n)
for(int i = 0 ; i < n ; i++){if(strs[i].size() < minimum) {minimum = strs[i].size();final = strs[i];} }
// comparing every character to final and updating it TC = O(m*n) 
for(int i = 0 ; i < n ; i++){
   int m = final.size(); 
   /// substr takes roughly O(m) n times so TC = O(n*m) SC = O(m)
for(int j = 0; j < m; j++)if(strs[i][j] != final[j]) final = final.substr(0,j);
}
return final;
  }      

bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n) return false;
        unordered_map <char,char> mpp;
    for(int i = 0; i< m ; i++) mpp[s[i]] = '-1';
    for(int i = 0 ; i < n; i++) {
        if(mpp[s[i]] == '-1') mpp[s[i]] = t[i];
        
      }
    return true;
    }