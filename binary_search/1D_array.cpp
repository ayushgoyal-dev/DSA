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

// The elements are distinct
// This will work either if the array is left or right sorted
// either left or right part of any element is always sorted TC = O(log n) SC= O(1)
int search_sorted_rotated(vector<int> &nums,int target){
int n = nums.size();
int low = 0 ; 
int high = n-1;
while(low <= high){
// elememt under scrutiny
    int mid = low + (high-low)/2; 
    if(nums[mid] == target) return mid;
    // left part is sorted
    if(nums[low] <= nums[mid]){
        // target in sorted part
if(nums[low] <= target && target < nums[mid])high = mid - 1;
// discard the sorted part
else low = mid +1;
    }
    //  right part is sorted
    else{
        //target in sorted part
if(nums[mid] < target && target <= nums[high]) low = mid +1;
//discard the sorted part
else high = mid -1;
    }
}
return -1;
}

// This function finds the pivot for left rotated arrays
int find_left_pivot(vector<int> &nums){
int n = nums.size();
int low = 0; 
int high = n-1;
// finding the pivot
while(low < high){
    int mid = low + (high-low)/2;
    // the observation is that the pivot always lie in unsorted region
    if(nums[mid] > nums[high]) low = mid + 1;
    // mid could be the pivot
    else high = mid;
}
return low;
}

// Assume a virtual array from index k to n-1+k and extract true value of index using %n TC = O(log n) SC = O(1)
int search_left_rotated(vector<int> &nums,int target){
    int n = nums.size();
    int k = find_left_pivot(nums);
    int low = k ; 
    int high = n -1 + k;
    while(low <= high){
int mid = low + (high-low)/2;
int real = mid%n;
if(nums[real] == target) return real;
else if(nums[real] < target) low = mid + 1;
else high = mid - 1;
}
return -1;
}

// Duplicates are present
// It creates problem when all the three poniters point to same value 
// TC = O(log n) {average case} TC = O(n/2) == O(n) {worst case} -> All duplicates SC = O(1) 
bool find_sorted_rotated(vector<int> &nums,int target){
    int n = nums.size();
    int low = 0 ;
     int high = n-1;
     while(low <= high){
         int mid = low + (high-low)/2;
         // if target found
         if(nums[mid] == target) return true;
         // edge case where sorted part cannot be determined
         if(nums[low] == nums[mid] && nums[mid] == nums[high]){
             low++;
            high--;
            continue;
        }
// left half is sorted 
if(nums[low] <= nums[mid]){
    if(nums[low] <= target && nums[mid] > target) high = mid -1;
    else low = mid + 1;
}
//right half is sorted
else{
    if(nums[mid] < target && target <= nums[high]) low = mid + 1;
    else high = mid - 1;
}
     }
     return false;
}

// The elements are distinct 
// The pivot point is the index for minimum value TC = O(log n) SC = O(1)
int min_sorted_rotated(vector<int> &nums){
int k = find_left_pivot(nums);
return nums[k];
}

//The key observation is that before finding the unique element pair starts at even index and ends at odd index 
// handle the edge cases and then use binary search TC = O(log n) SC = O(1)
int single_element(vector <int> &nums){
    int n = nums.size();
    // cheking all the edge cases
    if(n == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    int low = 1 ;
    int high = n -2 ;
    while(low <=high){
int mid = low + (high-low)/2;
// checking if mid is the target
if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
// target in right half (pairing invalid)
if((mid%2 == 0 && nums[mid] == nums[mid +1]) || (mid%2 == 1 && nums[mid] == nums[mid - 1])) low = mid +1;
//target is in left half (pairing invaid)
else high = mid - 1;
    }
    return -1;
}


int main(){
    vector <int> nums = {12,16,17,18,21,26,28,34,1,5,7,9};

    //cout << recursive_search(nums,0,10,21);
   // cout << lower_bound(nums,15) << " " << upper_bound(nums,15) << " "  << insert_element(nums,76);
    //cout << floor_ceiling(nums,16).first << " " << floor_ceiling(nums,16).second;
   // cout << occurence_range(nums,16)[0] << " " << occurence_range(nums,16)[1];
//cout << search_sorted_rotated(nums,18) << " " << search_left_rotated(nums,18);
// cout << boolalpha << find_sorted_rotated(nums,17);
//cout << min_sorted_rotated(nums);
cout << single_element(nums);


}
