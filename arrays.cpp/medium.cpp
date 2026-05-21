#include <bits/stdc++.h>
using namespace std;

// using single pass hash map TC = O(n) SC = O(n)
// here in case of duplicates use of map overwrites the previous index in case of duplicates
// this does not create a problem in two sum but in higher k sum problem this will cause issues 
// change your thinking from "where is the complement" to "have i seen the complement before"
// vector <int> two_sum(vector <int> &nums , int target){
//     int n = nums.size();
// unordered_map <int,int> mpp;
// for(int i  = 0 ; i < n ; i++){
//     int complement = target -  nums[i];
//     if(mpp.find(complement) != mpp.end()){
//         return{mpp[complement], i};
//     }
//     mpp[nums[i]] = i;
// }
// return {-1,-1};
// }

// using vector of pairs and two pointers TC =O(n log n) SC =O(n)
vector<int> two_sum(vector<int> &nums, int target){
int n = nums.size();
vector<pair<int,int>> arr;
for(int i = 0 ; i < n ;i++) arr.push_back({nums[i],i});
sort(arr.begin(),arr.end());
int left = 0; 
int right = n-1;
while(left < right){
    int sum = arr[left].first + arr[right].first;
    if(sum == target) return {arr[left].second,arr[right].second};
    if(sum < target) left++;
    if(sum > target) right --;
}
return{-1,-1};
}

// by separately sorting 0,1,2 TC = O(n) SC = O(1)
// void sort_0_1_2(vector<int> &nums){
//     int n = nums.size();
//     int i =0;
//   int j = 0;
//   int k =0;
//     while(i < n && j < n){
//     if(nums[j]==k){
//         swap(nums[i],nums[j]);
//         i++;
//     }
//     j++;
// if(j == n){
//     k++;
//     if(k == 3) return;
//     j = i;
// }
//     }
//     return;
// }

// dutch national flag algorithm TC = O(n) SC = O(1)
void sort_0_1_2(vector<int> &nums){
int n = nums.size();
int low = 0;
int mid = 0;
int high= n-1;
while(mid <= high){
    if(nums[mid] == 0) {
        swap(nums[mid],nums[low]);
        low++;
        mid++;
    }
    else if(nums[mid] == 1){
        mid++;
    }
    else{
        swap(nums[mid],nums[high]);
        high--;
    }
}
}

// using hash_map TC = O(n) SC = O(n)
// int majority_element(vector<int> &nums){
//     int n = nums.size();
//     unordered_map <int,int> hash_map;
//     for(int i = 0; i < n ; i++) hash_map[nums[i]]++;
//     int maxi = 0;
//     int number = -1;
//     for(int i  =0 ; i < n ; i++){
//      if(hash_map[nums[i]] > maxi ){
//         maxi = hash_map[nums[i]];
//          number = nums[i];
//      }
//     }
//     return number;
// }

//
int majority_element(vector <int> &nums){
    
}

// using two pointers TC = O(n^2) SC = O(1)
// int max_sum_subarray(vector<int> &nums){
//     int n = nums.size();
//     int temp = INT_MIN;
//     int first = 0; 
//     int second = 0;
//     while(first < n){
//         int sum = 0;
//         second = first;
//         while(second < n){
//         sum += nums[second];
//         temp = max(sum,temp);
//         second++;
//         }
//         first++;
//     }
//     return temp;
// }

// reset when sum is negative TC = O(n) SC = O(1)
int max_sum_subarray(vector<int> &nums){
int n = nums.size();
int sum = 0;
int temp = INT_MIN;
for(int i = 0 ; i < n ; i++){
    sum += nums[i];
temp = max(sum,temp);
    if(sum < 0) sum = 0;
}
return temp;
}

// print the subarray too
// change when sum > temp TC = O(n) SC = O(1)
// vector <int> max_sum_subarray(vector<int> &nums){
//     int n = nums.size();
//     int sum = 0;
//     int temp = INT_MIN;
//     int first = 0;  
//     int second = 0;
//     int a = -1;
//    for(int i  =0 ; i < n ; i++){
//    sum += nums[i];
//    if(sum > temp){
//     temp = sum;
//     second = i;
//     first = a +1;
//    }
//    if(sum < 0){
//     sum = 0;
//     a = i;
//    }
//    }
//    return vector <int> (nums.begin() + first, nums.begin() + second + 1);
// }

// Divide and conquer TC = O(nlogn) SC = O(logn)
// int maxcrossingsum(vector<int> &arr, int low, int mid, int high)
//     {
    //     int sum = 0;
    //     int left = INT_MIN;
    //     int right = INT_MIN;
    //     // left to mid
    //     for (int i = mid; i >= low; i--)
    //     {
    //         sum += arr[i];
    //         left = max(left, sum);
    //     }
    //     sum = 0;
    //     // mid+1 to high
    //     for (int i = mid + 1; i <= high; i++)
    //     {
    //         sum += arr[i];
    //         right = max(right, sum);
    //     }
    //     return left + right;
    // }
    // int maxsubArray(vector<int> &nums, int low, int high)
    // {
    //     if (low == high)
    //         return nums[low];
    //     int mid = (high + low) / 2;
    //     // int ans=INT_MIN;
    //     int left = maxsubArray(nums, 0, mid);
    //     int right = maxsubArray(nums, mid + 1, high);
    //     int cross = maxcrossingsum(nums, low, mid, high);
    //     return max({left, right, cross});
    // }
    // int maxSubArray(vector<int> &nums)
    // {
    //     return maxsubArray(nums, 0, nums.size() - 1);
    // }

// using two for loops TC = O(n^2) SC = O(1)
// int max_profit(vector <int> &price){
//     int n = price.size();
//     int profit = 0 ;
//    for(int i = 0 ; i < n-1 ; i++){
//     for(int j = i +1 ; j < n ; j++){
//        profit = max(price[j] - price[i] , profit);
//     }
//    }
//    return profit;
// }

// keep check of minimum purchase and maximum profit while iterating through the loop
int max_profit(vector<int> &price){
    int n = price.size();
    int minimum = INT_MAX;
    int profit = 0 ; 
for(int  i = 0 ; i < n ; i++){
if(price[i] < minimum ) minimum = price[i];
if(price[i] - minimum > profit) profit = price[i] - minimum;

}
return profit;
}

// using for loop TC  = O(n) SC = O(n)
vector <int> rearrange_array(vector<int> &nums){
int n = nums.size();
vector<int> positive;
vector<int> negative;
for(int i = 0 ; i < n ; i++){
    if(nums[i] < 0) negative.push_back(nums[i]);
    else positive.push_back(nums[i]);
}
 int pos = 0 ; int neg = 0 ; 
 for(int i = 0 ;i < n ; i++){
    if(i %2 == 0 ) {
        nums[i] = positive[pos];
        pos++;
    }
    else{
        nums[i] = negative[neg];
        neg++;
    }
 }
return nums;
}

// Using sort TC = O(nlogn) SC = O(logn) 
void next_permutation(vector<int> &nums){
    int n = nums.size();
 for(int i = n-1; i > 0 ; i--){
    if(nums[i-1] < nums[i] ) {
        int j = i ;
        while(j < n){
            if(nums[i-1] >= nums[j]) break;
            j++;
        }
        swap(nums[i-1],nums[j-1]);
        sort(nums.begin() + i,nums.end());
        return;
    }
}
sort(nums.begin(),nums.end());
return;
}

// can use reverse to make the SC constant TC = O(n) Sc = O(1)
list<int> leaders_array(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return {};
    int maximum = nums[n-1];
    list <int> result;
    result.push_front(nums[n-1]); 
    for(int i = n -2 ; i >= 0; i--){
    if(nums[i] > maximum ){
        result.push_front(nums[i]);
        maximum = nums[i];
    }
    }
    return result;
}

// sort then track longest length TC = O(nlogn) SC = O(n)
// vector <int> longest_consecutive_sequence(vector <int> &nums){
//   int n = nums.size();
//   if(n== 0) return {};
// sort(nums.begin(),nums.end());
// vector <int> current_subarray;
// vector <int> final_subarray;
// current_subarray.push_back(nums[0]);
// final_subarray = current_subarray;
// for(int i = 1 ; i < n ; i++){
//     if(nums[i] == nums[i-1]) continue;
//     if(nums[i] == nums[i-1] +1){
//         current_subarray.push_back(nums[i]);
//     } 
//     else{
//         current_subarray.clear();
//         current_subarray.push_back(nums[i]);
//     }
//     if(current_subarray.size() > final_subarray.size()) final_subarray = current_subarray;
// }
// return final_subarray;
// }

// using unordered set  TC =O(n) (average) in worst case scenarioes O(n^2) due to collisons SC =O(n)
vector <int> longest_consecutive_subarray(vector<int> &nums){
    int n = nums.size();
    if(n == 0) return {};
    unordered_set <int> hash_set;
    vector <int> final_subarray;
    for(auto x : nums) hash_set.insert(x);
   for(auto x : hash_set){
if(hash_set.find(x-1) == hash_set.end()){
    vector <int> current_subarray;

    int curr = x;
   while(hash_set.find(curr) != hash_set.end()){
    current_subarray.push_back(curr);
    curr++;
   }
   if(final_subarray.size() < current_subarray.size()) final_subarray = current_subarray;
}
}
return final_subarray;
}

// Brute force TC = O(m*n + m +n ) SC = O(m*n)
// void set_zeroes(vector <vector<int>> &matrix){
// int row_number = matrix.size();
// if(row_number == 0) return;
// int column_number = matrix[0].size();
//  vector<pair<int,int>> zeroes;
// for(int i = 0 ; i < row_number ; i++){
//     for(int j = 0; j < column_number ; j++){
//     if(matrix[i][j] == 0) zeroes.push_back({i,j});
//     }
// }
//     int n = zeroes.size();
//     for(int i = 0 ; i < n; i++ ){
//         int row = zeroes[i].first;
//         int column = zeroes[i].second;
//         for(int j = 0 ; j < column_number; j++) matrix[row][j] =0 ;
//         for(int j = 0 ; j < row_number ; j++) matrix[j][column] = 0;
// }
// return;
//      }
  
// using unordered set TC = O(m*n) SC = O(m+n)
// void set_zeroes(vector<vector<int>> &matrix){
//     int m = matrix.size();
//     if(m == 0) return;
//     int n = matrix[0].size();
//     unordered_set <int> row;
//     unordered_set <int> column;
// for(int i =0 ; i < m ; i++ ){
//     for(int j = 0 ; j < n ; j++){
//    if(matrix[i][j] == 0 ){
//     row.insert(i);
//     column.insert(j);
//    }
//     }
// }
//     for(auto it : row){
//         int x = it;
//         for(int i = 0 ; i < n ; i++) matrix[x][i] = 0;
//     }
//     for(auto it : column){
//         int x = it;
//         for(int i = 0 ; i < m ; i++) matrix[i][x] = 0;
//     }
// return;
// }

// using firt row and columns as markers TC = O(m*n) SC = O(1)
void set_zeroes(vector<vector<int>> &matrix){
int m =  matrix.size();
if(m== 0) return;
int n = matrix[0].size();
bool row = false ; bool column = false;
for(int i = 0 ; i < m ; i++) if(matrix[i][0] == 0) column = true;
for(int i = 0 ; i < n ; i++) if(matrix[0][i] == 0) row = true;
for(int i = 1 ; i < m ; i++){
 for(int j = 1; j < n ; j++){
    if(matrix[i][j] == 0){
        matrix [i][0] =0 ;
        matrix [0][j] = 0;
    }
 }
}
for(int i = 1 ; i < m ; i++){
 for(int j = 1; j < n ; j++){
  if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] =0;
 }
}
if(row == true)  for(int i = 0; i < n ; i++) matrix[0][i] = 0;
if(column == true)  for(int i = 0; i < m ; i++) matrix[i][0] = 0;
return;
}
    
// first transpose then reverse TC = O(n^2) SC = O(1)
void rotate_clockwise(vector<vector<int>> &matrix){
    int n = matrix.size();
    if(n == 0) return;
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            if(i > j)  swap(matrix[i][j],matrix[j][i]);
        
    }
    reverse(matrix[i].begin(),matrix[i].end());
    }
return;
}

// first reverse then transpose TC = O(n^2) SC = O(1)
// More popular way transpose then reverse columns TC = O(n^2) SC = O(1)
void rotate_anticlockwise(vector<vector<int>> &matrix){
    int n = matrix.size();
    if(n ==0 ) return;
    for(int i =0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
        for(int j = i; j < n ; j++){
    swap(matrix[i][j],matrix[j][i]);
        }
    }
    return;
}

// using four boundaries to peel matrix like a onion TC = O(m*n) SC = O(1)
vector<int> spiral_print(vector<vector<int>> &matrix){
    int m = matrix.size();
    if(m == 0) return {};
    int n = matrix[0].size();
    vector <int> result;
    int start_rindex = 0;
    int start_cindex = 0;
    int stop_rindex = m -1 ;
    int stop_cindex = n -1;

    while(start_rindex <= stop_rindex && start_cindex <= stop_cindex){
        for(int i = start_cindex ; i <= stop_cindex ; i++){
            result.push_back(matrix[start_rindex][i]);
        }
        start_rindex++;

        for(int i = start_rindex; i <= stop_rindex ; i++){
            result.push_back(matrix[i][stop_cindex]);
        }
        stop_cindex--;
        if(stop_cindex >= start_cindex){
        for(int i = stop_cindex; i >= start_cindex ; i--){
         result.push_back(matrix[stop_rindex][i]);
        }
        stop_rindex--;
       }
        if(stop_rindex >= start_rindex){
        for( int i = stop_rindex ; i >= start_rindex ; i--){
            result.push_back(matrix[i][start_cindex]);
        }
        start_cindex++;
      }
    }
return result;
}

// using nested loops TC = O(n^2) SC = O(1)
// int count_subarray(vector<int> &nums, int k){
// int n = nums.size();
// if(n == 0) return 0;
// int count = 0;
// for(int first = 0; first < n ; first++){
//     int sum = 0;
//     for(int last = first ; last < n ; last++){
//    sum += nums[last];
//    if(sum == k) {
//     count++;
//    }      
//     }
// }
// return count;
// }

// using prefix sum + hash map TC = O(n) SC = O(n)
int count_subarray(vector<int> &nums , int k){
int n = nums.size();
if(n ==0) return 0;
unordered_map <int,int> hash_map ={{0,1}};
int sum = 0;
int count = 0;
for(int i = 0 ; i < n ; i++){
sum += nums[i];
if(hash_map.find(sum - k) != hash_map.end()){
count += hash_map[sum-k];
}
hash_map[sum]++;
}
return count;
}

int main(){

// int n;
// cin >> n;
// vector <int> nums;
// int x; 
// for(int i = 0; i < n ; i++){
// cin >> x; 
// nums.push_back(x);
// }




//  list <int> ls = leaders_array(nums);
// for(int x : ls){
//     cout << x << " ";
// }


// int target;
// cin >> target;
// vector<int> pair = two_sum(nums,target);
// cout << pair[0] << " "  << pair[1];



//    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
//     set_zeroes(matrix);
//     for (auto &row : matrix) {
//         for (auto &val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }


// vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
// vector <int> result = spiral_print(matrix);
// for(int i = 0 ; i < result.size() ; i++){
//     cout << result[i] << " ";
// }




return 0;
 }