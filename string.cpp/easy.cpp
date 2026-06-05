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

// use two undordered maps to map s to t and vice versa TC = O(n) (average) SC = O(n) (general) SC = O(1) (only ASCII values)
bool isIsomorphic(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m != n) return false; // unequal lengths
        unordered_map <char,char> mpp1; // s To t
        unordered_map <char,char> mpp2; // t TO s
        for(int i = 0 ; i < n ; i++){// iterate through s to map s to t TC = O(n)
         if(mpp1.find(s[i]) == mpp1.end()) mpp1[s[i]] = t[i]; // cheking if the char already exist TC = O(1)
         else{
            auto it = mpp1.find(s[i]);
            if(it -> second != t[i]) return false; // if mapping mismathces
         }
      }
             for(int i = 0 ; i < m ; i++){
         if(mpp2.find(t[i]) == mpp2.end()) mpp2[t[i]] = s[i];
         else{
            auto it = mpp2.find(t[i]);
            if(it -> second != s[i]) return false;
         }
        }
 return true; // if no mismatch occurs
    }

// double the intial string and use find TC = O(n) SC = O(n)
bool rotateString(string s, string goal) {
   int n = s.size();
   int m = goal.size();
   if(m != n) return false; // size mismatch
   // TC = O(n) SC = O(n) 
 string doubled = s+s; // goal is a subset of doubled
 // the TC for find funcion depends on the library being used
 if(doubled.find(goal) != string::npos) return true; // find function can take at min O(n) complexity
 return false;
    }

// create two hashmap and compare TC = O(n) SC = O(n)
bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m != n) return false; // size mismatch
        unordered_map <char,int> hash_map1; // freqeuncy of characters in s
        unordered_map <char,int> hash_map2;// frequency of characters in t
for(int i = 0 ; i < n ; i ++){ // storing frequency 
   hash_map1[s[i]]++;
   hash_map2[t[i]]++;
}

// for(int i = 0 ; i < n ; i++){ 
//    if(hash_map2.find(s[i]) == hash_map2.end()) return false; // character not found
//    else{
//     auto it = hash_map2.find(s[i]);
//     if(it -> second != hash_map1[s[i]]) return false; // frequnecy not matched
//    }
// }
return hash_map1 == hash_map2;
    }   

// Alternate where we use a sinlge hashmap
// bool isAnagram(string s, string t){
// unordered_map<char,int> freq;
// for(char c : s)
//     freq[c]++;
// for(char c : t)
// {
//     if(--freq[c] < 0)
//         return false;
// }
// return true;
// }


