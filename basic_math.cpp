#include <bits/stdc++.h>
using namespace std;

void count_digits_a(int n){
   int count = 0; 
    while( n > 0){
        n /= 10;
        count++;
    }
    cout << count;
}

int count_digits_b(int n){
 int count = log10(n) + 1;
    cout << count;
    return count;
}

// Time complexity = O(log10(N))

void reverse_number(int n){
    int reverse_number = 0;
while(n > 0){
    int digit = n%10;
    reverse_number = reverse_number* 10 + digit; 
    n /= 10; 
}
cout << reverse_number;
  }

int armstrong_number(int n){
    int sum = 0;
    int count = count_digits_b(n);

    while(n > 0){
        int digit = n%10;
        int power = 1;
        for( int i = 1; i <= count; i++){
        power *= digit ; 
        }
        sum += power;
        n = n/10;
    }
    return sum;
}

void all_divisors_a(int n){
    int count = 0;
for(int i = 1; i<= 36; i++ ){
    if(n%i == 0) count++;
}
cout << count;
}
 
// Time Complexity = O(N);

void all_divisors_b(int n){
    vector<int> ls;
   // for(int i = 1 ; i <= sqrt(n); i++){     This takes time as sqrt is a function 
     for(int i = 1; i*i <= n; i++){
        if(n%i == 0 ){
             ls.push_back(i);
        if( i != n/i) ls.push_back(n/i);
      //  cout << i << " " << n/i << " ";
    }
}
    sort(ls.begin(), ls.end()); // O(n log n) where n is number of factors
    for(auto it : ls) cout << it << " "; // O(n)
}

// Time Complexity = O(sqrt(N)) + O(n) + O(n log n)

void finding_HCF(int n1, int n2){
    int divisor = n1;
    int dividend = n2;
if( n1 > n2 ){
    divisor = n2;
    dividend = n1;
}
int remainder = 1;
while(remainder != 0 ){
remainder = dividend % divisor; 
dividend = divisor;
divisor = remainder; 
}
cout << dividend;
}

// Time Complexity = O(log (min(n1,n2)) )

int main(){
    int n1, n2; 
    cin >> n1 >> n2;

// int sum = armstrong_number(n);
// if( sum == n) cout << "True";
// else cout << "False";
  


    return 0;
}