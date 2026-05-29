#include <bits/stdc++.h>
using namespace std;
 
// The elements are distinct 
// move mid according to target TC = O(log n) SC = O(1)
// int iterative_search(vector <int> &nums,int target){
//     int n = nums.size();
//     int low = 0; 
//     int high = n-1;
//     while(low <= high){
//   int mid = low + (high-low)/2;
//   if(nums[mid] > target)  high = mid -1;
// else if(nums[mid] < target) low = mid +1;
//   else return mid;
//     }
//     return -1;
// }

// works only on sorted arrays TC = O(log n) SC = O(1)
int recursive_search(vector<int> &nums,int low,int high,int target){
    if(low > high) return -1;
    int mid = low + (high-low)/2;
    if(nums[mid] > target) return recursive_search(nums,low,mid-1,target);
    else if(nums[mid] < target) return recursive_search(nums,mid+1,high,target);
    else return mid;
}

// There might be duplicates present
// just store the possible answer in a variable  TC =O(log n) SC = O(1)
// for coding rounds lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin()
int lower_bound(vector<int> &nums,int x){
int n = nums.size();
int low = 0 ; 
int high = n - 1;
int ans = n ;
// binary search
while(low <= high){
    int mid = low + (high-low)/2;
    if(nums[mid] < x) low = mid + 1;
    else{
        // stores  the possbile answer
        ans = mid;
        high = mid - 1;
    }
}
return ans;
}

// just store the possible answer in a variable  TC =O(log n) SC = O(1)
int upper_bound(vector<int> &nums,int x){
    int n = nums.size();
int low = 0 ; 
int high = n - 1;
int ans = n ;
// binary search
while(low <= high){
    int mid = low + (high-low)/2;
    if(nums[mid] <= x) low = mid + 1;
    else{
        // stores  the possbile answer
        ans = mid;
        high = mid - 1;
    }
}
return ans;
}

// The elements are distinct
// just return the index of low if element not found TC  = O(log n) SC = O(1)
int insert_element(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0; int high = n - 1;
while(low <= high){
    int mid  = low +(high-low)/2;
    if(nums[mid] < target)low = mid + 1;
    else if(nums[mid] > target) high = mid - 1;
    else return mid;
}
return low;
}

// could be done using lb an ub directly TC = O(log n) SC = O(1)
pair<int,int> floor_ceiling(vector <int> &nums, int x){
    int n = nums.size();
    int low  = 0;
    int high = n -1;
    int floor = -1;
    int ceiling = -1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(nums[mid] > x){
            ceiling = nums[mid];
            high = mid -1;
        }
        else if(nums[mid] < x){
            floor = nums[mid];
            low = mid + 1;
        }
    else return {nums[mid],nums[mid]};
    }
    return {floor,ceiling};
}

// just use lb and ub TC = O(log n ) SC = O(1)
// pair <int,int> occurence_range(vector<int> &nums, int target){
// if(lower_bound(nums,target) == nums.size() || nums[lower_bound(nums,target)] != target) return {-1,-1};
// else return {lower_bound(nums,target),upper_bound(nums,target)};
// }

// write BS for extremes TC = O(log n) SC = O(1)
vector <int>  occurence_range(vector<int> &nums,int target){
int n = nums.size();
// lower bound
int low = 0 ;
int high = n -1;
vector<int> result;
while(low <= high){
    int mid = low + (high-low)/2;
    if(nums[mid] < target) low = mid + 1;
    else high = mid - 1; 
}
if(low == n || nums[low] != target) result.push_back(-1);
else result.push_back(low);
//upper bound
low = 0;
high = n -1;
while(low <= high){
     int mid = low + (high - low)/2;
     if(nums[mid] > target) high = mid  -1;
     else low = mid + 1;
}
if(result[0] == -1) result.push_back(-1);
 else result.push_back(high);
return result;
}

//This is not the leetcode version here is assumed that the value of k is given 
// Assume a virtual array from index k to n-1+k and extract true value of index using %n TC = O(log n) SC = O(1)
// int search_left_rotated(vector<int> &nums,int target,int k){
//     int n = nums.size();
//     int low = k ; 
//     int high = n -1 + k;
//     while(low <= high){
// int mid = low + (high-low)/2;
// if(nums[mid%n] == target) return mid%n;
// else if(nums[mid%n] < target) low = mid + 1;
// else high = mid - 1;
// }
// return -1;
// }

//
int search_left_rotated(vector<int> &nums, int target){

}

int main(){
    vector <int> nums = {1,5,7,9,12,16,17,18,21,26,28,34};
    //cout << recursive_search(nums,0,10,21);
   // cout << lower_bound(nums,15) << " " << upper_bound(nums,15) << " "  << insert_element(nums,76);
    //cout << floor_ceiling(nums,16).first << " " << floor_ceiling(nums,16).second;
   // cout << occurence_range(nums,16)[0] << " " << occurence_range(nums,16)[1];

}