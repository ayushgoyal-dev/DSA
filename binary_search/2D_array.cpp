#include <bits/stdc++.h>
using namespace std;

// function to calculate number of 1s in a row TC = O(log m)
int number_1s(vector<vector<int>> &matrix, int n, int m, int i)
{
    int low = 0;
    int high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (matrix[i][mid] == 1)
            high = mid - 1;
        else
            low = mid + 1;
    }
    // low points to first occurence of 1
    return m - low;
}

// iterate over rows and calculate maximum number of 1s TC = O(n*log m)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int maximum = INT_MIN;
    for (int i = 0; i < n; i++)
        maximum = max(maximum, number_1s(matrix, n, m, i));
    if (maximum == 0)
        return -1; // -1 if no 1 in the entire matrix
    for (int i = 0; i < n; i++)
        if (number_1s(matrix, n, m, i) == maximum)
            return i;
    return -1; // we never reach this step
}

// we treat 2D matrix as a virtual 1D matrix TC = O(log m*n)
bool searchMatrixI(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
        return false;
    int m = matrix[0].size();
    long long low = 0;
    long long high = m * n - 1;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        int row = mid / m;    // real row index
        int column = mid % m; // real column index
        if (matrix[row][column] == target)
            return true;
        else if (matrix[row][column] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}

// Use BS on column to search for the element TC = O(log m)
// bool search_element(vector<vector<int>> &matrix,int target,int i){
// int n = matrix.size();
// if(n==0) return false;
// int m = matrix[0].size();
// int low = 0;
// int high = m-1;
// while(low <= high){
//     int mid = low + (high-low)/2;
//     if(matrix[i][mid] == target) return true;
//     if(matrix[i][mid] < target) low = mid +1;
//     else high = mid -1;
// }
// return false;
// }

// Use helper function for each row TC = O(n * log m)
// bool searchMatrixII(vector<vector<int>>& matrix, int target) {
//         int n= matrix.size();
//         for(int i = 0; i< n; i++) if(search_element(matrix,target,i)) return true;
//         return false;
//     }

// start from [0][m-1] and iterate till [m-1][0] while comparing with target TC = O(m+n)
bool searchMatrixII(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    if (n == 0)
        return false;
    int m = matrix[0].size();
    int row = 0;        // current row number
    int column = m - 1; // current  column number
    while (row < n && column >= 0)
    {
        if (matrix[row][column] == target)
            return true; // target found
        else if (matrix[row][column] > target)
            column--; // rest elements greater than target
        else
            row++; // rest element greater than target
    }
    return false; // target not found
}

// // The solution got accepted at leetcode but if fails on test case as mentioned in int main 
// // The problem is i am discarding the whole row in case my chosen row peak is not global peak which does not gurantee that other row peak is not global peak or that by discarding the row i will necessary find the global peak
// bool check_peak(vector<vector<int>> &mat, int i, int j){
// int n = mat.size();
// int m = mat[0].size();
// int upper,lower,left,right;
// if(i == 1 )  upper = -1;
// else upper = mat[i-2][j-1]; 
// if(i == n)  lower = -1;
// else lower = mat[i][j-1];
// if(j == 1)  left = -1;
// else left = mat[i-1][j-2];
// if(j == m)  right = -1;
// else right = mat[i-1][j];
// // Checking if number is greater than its neighbours
// if(mat[i-1][j-1] > upper && mat[i-1][j-1] > lower && mat[i-1][j-1] > left && mat[i-1][j-1] > right) return true;
// else return false;
// }
// // i made a function to add -1 om borders but it took TC =O(mn)
// // create a virtual boundary of -1 on borders on matrix
// // i am currently going to a single row peak of every row and cheking if it is a global peak if not i discard the whole row
// vector<int> findPeakGrid(vector<vector<int>> &mat)
// {
//     int n = mat.size();
//     if (n == 0)
//         return {};
//     int m = mat[0].size();
//     bool peak = false;
//     for(int i  = 1; i < n+1; i++){
//   int low = 1;
//   int high = m;
//   while(low < high){
//     int mid = low + (high-low)/2;
//     if(mat[i-1][mid-1] < mat[i-1][mid]) low = mid+1;
//     else high = mid;
//     }  
//        if(check_peak(mat,i,low)) return {i-1,low-1};
//     }
//     return {}; 
// }

// use BS on columns and find maximum in each column TC = O(nlogm) SC = O(1)
vector<int> findPeakGrid(vector<vector<int>>& mat) {
 int n = mat.size();
 if(n == 0 ) return {};
 int m = mat[0].size();
 int low = 0;
 int high = m-1;
 // BS on columns TC = O(log m)
 while(low <= high){
    int left,right;
    int index = 0;
    int mid = low + (high-low)/2; // choosing the column
    for(int i = 0; i < n; i++) if(mat[i][mid] > mat[index][mid]) index = i; // finding maximum in the column TC = O(n)
    int current = mat[index][mid];
    // -1 left boundary
    if(mid == 0)  left = -1;
    else  left = mat[index-1][mid];
    // -1 right boundary
    if(mid == m-1)  right = -1;
    else right = mat[index+1][mid];
    if(current > left && current > right) return {index,mid}; // peak element found
    else if(current < left ) high = mid -1; // if left > current then peak exists in left part
    else low = mid +1; 
}
return {};
    }

// m = number of rows n = number of columns
// iterate each row and use BS to count numbers TC = O(mlogn)
int count_numbers(vector<vector<int>> &matrix, int m, int n, int mid)
{
    int count = 0; // number of elements equal or smaller than mid 
    for (int i = 0; i < m; i++) count += upper_bound(matrix[i].begin(),matrix[i].end(),mid) - matrix[i].begin(); // index of element just greater than mid
    return count;
}

// Perform BS on range of numbers in matrix then count the number of elements less than equal to mid to move mid TC = O(m*log(max-min)*log(n))
int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX; int high = INT_MIN;
    for(int i = 0 ; i < m ; i++){ // TC = O(m)
    low  = min(low,matrix[i][0]); // min element of matrix
    high = max(high,matrix[i][n-1]); // max element of matrix
    }

    while (low <high) // TC = O(log (max-min))
    {
        int mid = low + (high - low) / 2; // candidate median
        int count = count_numbers(matrix, m, n, mid); // number less than or equal to candidate TC = O(mlogn)
         if (count < (m * n) / 2 + 1) // m and n are odd so total elements in matrix are also odd
            low = mid + 1; // inplausible candidate
        else 
            high = mid ; // plausible candidate
    }
    return high; 
}

int main(){
    // vector<vector<int>> mat = {{5,4,3},{6,1,0}};
    // vector <int> result = findPeakGrid(mat);
    // for(int i = 0; i < result.size(); i++) cout << result[i] << " ";

}