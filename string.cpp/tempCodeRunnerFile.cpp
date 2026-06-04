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