#include <bits/stdc++.h>
using namespace std;

// using for loop TC = O(n) SC = O(1)
void max_element(int n, int arr[])
{
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    cout << maximum;
}

void penultimate_element(int n, int arr[])
{
    if (n < 2)
    {
        cout << "-1";
        return;
    }
    int small = INT_MAX;
    int second_small = INT_MAX;
    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < small)
        {
            second_small = small;
            small = arr[i];
        }

        else if (arr[i] > small && arr[i] < second_small)
            second_small = arr[i];

        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > second_largest)
            second_largest = arr[i];
    }
    if (second_small == INT_MAX || second_largest == INT_MIN)
        cout << "-1";
    else
        cout << second_small << " " << second_largest;
}

// using for loop TC = O(n) SC = O(1)
// bool check_sorted(int n, int arr[])
// {
//     for (int i = 1; i < n; i++)
//     {
//         if (arr[i - 1] > arr[i])
//             return false;
//     }
//     return true;
// }

// rotated the arr n times and checked if sorted TC =O(n^2) SC = O(n)
// bool check_sorted_rotated(vector <int> & nums){
//     int n = nums.size();
//     bool sorted = false;
//     int j =0;
//     while ( j < n && sorted == false){
//     int k =j;
//     vector <int> temp(k);
//     vector <int> duplicate = nums;
//     for(int i = 0 ; i < k ; i++) temp[i] = duplicate[i];
//     for(int i = 0; i < n-k ; i++) duplicate[i] = duplicate[i + k];
//     for(int i = 0; i < k ; i++ ) duplicate[i + n - k] = temp[i];
//     int count = 0;
//     for(int i =1 ; i < n; i++) if(duplicate[i-1] > duplicate[i]) count++ ;
//     if ( count == 0 ) sorted = true;
//     j++;
//       }
//     return sorted;
// }

// order breaks at just one point TC =O(n) SC =O(1)
bool check_sorted_rotated(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    bool sorted = true;
    for( int i =1 ; i < n ; i++){
   if(nums[i-1] > nums[i]) {
    count++;
    if(count > 1){
    sorted = false;
    break;
    }
   }
    }
    if ( count == 1 && nums[n-1] > nums[0]) sorted = false;
    return sorted;
}
  
// using two pointer TC = O(n) SC = O(1)
int remove_duplicates(vector <int> &nums){
   int n = nums.size();
   int i =0 ;
   for(int j = 1; j < n ; j++){
    if(nums[i] != nums[j]){
        i++;
        nums[i] == nums[j];
    }
   }
   return i+1;
}

// using swaps TC = O(n) SC = O(1)
// void rotate(vector<int> &nums){
// int n = nums.size();
// swap(nums[0] , nums[n-1]);
// for(int i = 0 ; i < n-2 ; i++){
// swap(nums[i] , nums[i+1]);
// }
// }

//using temp TC = O(n) SC = O(1)
void rotate_once(vector <int> & nums){
    int n = nums.size();
    int first= nums[0];
    for(int i = 0; i < n-1 ; i++) nums[i] = nums[i+1];
    nums[n-1] = first;
}

/* This code only works when gcd(n,k) == 1 
in other cases this code fails so when i revisit make it work for all inputs*/
// cycle placement method TC = O(n) SC = O(1) 
// void rotate(vector<int> &nums , int k){
//       int n = nums.size();
//       if ( n == 0) return;
//     k = k %n;
//     int j = n - k;
//     int count = 0; 
//     int temp = nums[j];
//     while( count < n){
//         int index = (j+k)%n;
//       swap(temp,nums[index]);
//       count++;
//       j = index;
//     }
// }


// using reverse function TC = O(n) SC = O(1)
void rotate(vector<int> &nums, int k ,char ch ){
    int n = nums.size();
    k %= n;
    if (ch == 'r'){
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.begin() + k);
    reverse(nums.begin() + k,nums.end());
    }

    if(ch == 'l'){
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
        reverse(nums.begin() , nums.end());
    }
}

// using temp and for loop TC = O(n) SC = O(k)
void left_rotate_array(int n, int k, int arr[])

{
    k = k % n;
    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = arr[i];
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }
}

// TC = O(n) SC = O(1)

// using erase and insert TC = O(n^2) SC = O(1)
// void move_zeroes(vector <int> &arr,int n){
//        int k =0;
// for(int i = 0 ; i < n -k; i++){
//    if( arr[i] == 0){
//     arr.erase(arr.begin() + i);
//     arr.push_back(0);
//     i--;
//     k++;
//    }
// }
// }

// using two pinters TC = O(n) SC = O(1)
void move_zeroes(vector<int> &arr, int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

// using for loop TC = O(n) SC = O(1)
int linear_search(vector<int> &arr, int num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

// using map TC = (m+n)O(log(m+n)) SC = O(m+n)
//  void union_arrays(vector <int> &arr1 , vector <int> &arr2 , int n, int m)
//  {
//      map <int,int> mpp;
//      vector <int> merged_arr;
//     for(int i = 0 ; i < n ; i++){
//      mpp.insert({arr1[i],0});
//     }
//     for(int i = 0; i < m ; i++){
//      mpp.insert({arr2[i],0});
//     }
//        for(auto it : mpp){
//     merged_arr.push_back(it.first);
//     }
//  }

// using set TC = O((m+n)log(m+n)) SC = O(m+n)
//  void union_arr(vector <int> arr1 , vector<int> arr2 , int n , int m){
//      set <int> st;
//      vector <int> merged_arr;
//      for(int i = 0 ; i < n ; i++){
//          st.insert(arr1[i]);
//      }
//      for(int i =0 ; i < m ; i++){
//          st.insert(arr2[i]);
//      }
//      for(auto it : st){
//     merged_arr.push_back(it);
//      }
//  }

// using two pointers TC = O(n + m) SC = O(n+m)
void union_arr(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = 0 , j =0;
    vector<int> merged_arr;
    while(i < n && j < m){
        
        if (arr1[i] <= arr2[j])
        {
            if ( merged_arr.empty() || merged_arr.back() != arr1[i])   merged_arr.push_back(arr1[i]);
            i++;
        }
           else 
            {
                if(merged_arr.empty() || merged_arr.back() != arr2[j])  merged_arr.push_back(arr2[j]);
                j++;
            }
        
    }
    while( i < n){
        if(merged_arr.empty() || arr1[i] != merged_arr.back() ) merged_arr.push_back(arr1[i]);
        i++;
    }
      while( j < m){
        if(merged_arr.empty() ||arr2[j] != merged_arr.back()  ) merged_arr.push_back(arr2[j]);
        j++;
    }
}

// using sort TC = O(n log n) SC = O(n)
// int missing_element(vector<int> &arr){
// int n = arr.size() + 1;
// sort(arr.begin(),arr.end());
// for(int i = 0; i < n -1; i++ ){
//     if(arr[i] != i+1 ) return i+1;
// }
// return n;
// }

//using hashing TC = O(n) SC = O(n)
// int missing_element(vector <int> &arr){
//     int n = arr.size() +1;
//     vector <int> hash_arr(n,0);
//     for(int i = 0 ; i < n-1 ; i++){
//      hash_arr[arr[i] - 1]++;
//     }
//     for(int i = 0 ; i < n ; i++){
//         if(hash_arr[i] == 0) return i+1;
//     }
//     return -1;
// }

// Using sum formula TC = 0(n) SC = O(1)
// int missing_element(vector <int> &arr){
//     int n = arr.size();
//     int sum = 0;
// for(int i = 0 ; i < n ; i++){
//  sum += arr[i]; 
// }
// return (n+1)*(n+2)/2 - sum;
// }

//using XOR TC = O(n) SC = O(1)
int missing_element(vector <int> &arr){
    int n = arr.size() + 1;
    int XOR1 = 0 , XOR2 = 0;
    
    for(int i = 0 ; i < n-1 ; i++){
        XOR2 ^= arr[i];
    }
     for(int i = 1 ; i <= n ; i++){
        XOR1 ^= i;
    }
 return XOR1 ^ XOR2;
}

//using for loop TC = O(n) SC = O(1) 
int consecutive_ones(vector <int> &nums ){
    int n = nums.size();
    int count  = 0 ;
    int maximum = 0;
    for(int i = 0 ; i <  n ; i++){
       if(nums[i] == 1 ) {
        count++;
       if(count > maximum) maximum = count;
    }
       else {count = 0;}
    }
    return maximum;
}

// using XOR TC = O(N) SC = O(1)
int appear_once(vector <int> &nums){
int n = nums.size();
int XOR = 0;
for(int i = 0 ; i < n ; i++){
    XOR ^= nums[i];
}
return XOR;
}


// TC = O(n^2) SC = O(1) 
// using single while does not guarnatee TC = O(n)
// vector<int> two_sum(vector<int> &nums , int target){
//     int n = nums.size();
//     int j = 0 ;
//     int i = 1;
// while(j < n-1){
// if(nums[j] + nums[i] == target){
//   return {i,j};
// }
//     i++;
//     if(i == n){
//         j++;
//         i = j+1;
//     }
// }
// return {-1,-1};
// }
 
// using map TC = O(n log n) SC = O(n)
// bool two_sum(vector<int> &nums, int target){
// map <int,int> hash_map;
// int n = nums.size();
// for(int i = 0 ; i < n ; i++){
// hash_map[nums [i]]++;
// }
// for(int i = 0 ; i < n ; i++){
//     int required = target - nums[i];
//     if(required == nums[i]){
//         if(hash_map[nums[i] > 1]) return true;
//     }
//     else if(hash_map[required] > 0) return true;
// }
// return false;
// }

// using three for loops TC = O(n^3) SC = O(1)
// int longest_subarray_positive(vector<int> &nums, int k){
// int n = nums.size();
// int max_length = 0;
// for(int i = 0; i < n ; i++){
//     for(int j = i; j < n; j++ ){
//         int sum = 0;
//         for(int t = i; t <= j ; t++){
//         sum += nums[t];
//         }
//         if(sum == k) max_length = max(max_length,j-i+1);
//     }
// }
// return max_length;
// }

// using two for loops TC = O(n^2) SC = O(1)
// int longest_subarray_positive(vector<int> &nums, int k){
//     int n = nums.size();
//     int max_length = 0;
//     for(int i = 0; i < n ; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//          sum += nums[j];
//          if(sum == k) max_length = max(max_length,j-i+1);
//         }
//     }
//     return max_length;
// }
  
// using two pointer TC = O(n) SC = O(1)
// this uses the concept that on moving right sum increases and
// on moving left sum decreases
int longest_subarray_positive(vector<int>  &nums, int k){
    int n = nums.size();
    int max_length = 0;
    int left = 0;
    int sum = 0;
    for(int right = 0; right < n ; right++){
        sum += nums[right];

       while( sum > k){
        sum = sum - nums[left];
        left++;
       }

        if(sum == k) max_length = max(max_length,right - left +1);
       
    }
    
    return max_length;
}
/* here i misread the question and tried to write a code where the elements need not be contigious
but that creates 2^n possibilities which cannot be handeled by sliding window techique as i was trying
it needs the use of dynamic programming.*/

// using two for loops TC = O(n^2) SC = O(1)
//int longest_subarray_zero(vector<int> &nums){
//     int n = nums.size();
//    int max_length = 0;
//    for(int i = 0 ; i < n ; i++){
//     int sum = 0;
//     for(int j = i ; j < n ; j++){
//  sum += nums[j];
//     if(sum == 0) max_length = max(max_length,j-i+1);
//     }
//    }
//    return max_length;
// }

/* brute force kar liya h gpt vala sheet ke dono dekhne h */
int longest_subarray_zero(vector<int> &nums){
int n = nums.size();


}

int main()
{

//     int n;
//     cin >> n;
//    vector<int> arr(n);
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];

    // move_zeroes(arr,n);
  //for (int i = 0; i < n; i++)
        //cout << arr[i] << " ";

    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i]; 
    //     remove_duplicates(n,arr);
    //     for(int i =0 ; i < n ; i++) cout << arr[i];

    // max_element(n,arr);
    // cout << check_sorted(n,arr);
    // int k;
    // cin >> k;
    // left_rotate_array(n,k,arr);

}