#include <bits/stdc++.h>
using namespace std;

int frequency_array_integer(int n,int m,int a ){
int arr[n];
for(int i = 0; i< n; i++)  cin >> arr[i];
int hash_arr[m+1] = {0};
for(int i = 0 ; i < n ; i++){
    hash_arr[arr[i]]++;
}
return hash_arr[a];
}

int frequency_array_string(string &s,char ch){
int hash_arr[26] = {0};
// for all characters use hash_arr[256] = {0};
for(int i = 0; i < s.size(); i++){
    hash_arr[s[i] - 'a']++;
    // for all characters use hash_arr[s[i]]++;
}
return hash_arr[ch - 'a'];
// for all characters use return hash_arr[ch];
}


int main(){

// int n,m,a; 
// cin >> n >> m >> a;
// cout << frequency_array_integer(n,m,a);

// string s;
// cin >> s;
// char ch;
// cin >> ch;
// cout << frequency_array_string(s,ch);


// using maps 
int n;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++) cin >> arr[i];

map<int,int>mpp;
for(int i =0; i <n; i++) mpp[arr[i]]++;

int q;
cin >> q;
while(q--){
    int number;
    cin >> number;
    cout << mpp[number] << "\n";
}
}