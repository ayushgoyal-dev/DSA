#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(N)
// Space complexity = O(N)
void print_name(int n)
{
    if (n == 0)
        return;
    cout << "Ayush ";
    n--;
    print_name(n);
}

void print_numbers(int n, int i)
{
    if (i > n)
        return;
    cout << i << " ";
    print_numbers(n, i + 1);
}

void print_numbers_backtracking(int n, int i)
{
    if (i < 1)
        return;
    print_numbers_backtracking(n, i - 1);
    cout << i << " ";
}

void sum_numbers_a(int n, int sum)
{
    if (n < 1)
    {
        cout << sum;
        return;
    }
    sum_numbers_a(n - 1, sum + n);
}

int sum_numbers_b(int n)
{
    if (n == 1)
        return 0;
    return n + sum_numbers_b(n - 1);
}

// TIme complexity = O(N)
// Space complexitu = O(N)
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void reverse_array(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    reverse_array(i + 1, arr, n);
}

// TIme complexity = O(N/2)
bool palindrome_string(int i, string &s ){
if ( i >= s.size() /2) return true;
if ( s[i] != s[s.size() - i -1]) return false;
return palindrome_string(i+1,s);
}

// Time complexity = O(2^n)  => Exponential Timr Complexiy
//not exactly 2^n but close to it for bigger numbers
int fibonacci(int n){
    if ( n <= 1) return n;
    int last = fibonacci(n-1);
    int second_last = fibonacci(n-2);
    return last + second_last;
   // return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    
    int n;
    cin >> n;

    // print_name(n);
    // print_numbers(n,1);
    // printid_numbers_backtracking(n,n);
    // sum_numbers_a(n,0);
    // cout << sum_numbers_b(n);
    // cout << factorial(n);

    // int arr[n];
    // for(int i =0; i< n; i++) cin >> arr[i];
    // reverse_array(0,arr,n);
    // for(int i =0; i< n; i++) cout << arr[i] << " ";

    // string s = "madam";
    // cout << palindrome_string(0,s);
    
cout << fibonacci(n);
}

// Watched the lectures till multiple recursion calls(5th)