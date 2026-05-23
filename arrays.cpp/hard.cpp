#include <bits/stdc++.h>
using namespace std;

// first n rows
// using two nested loops TC = O(n^2) SC = O(n^2)
// vector<vector<int>> pascal_triangle(int numsRows){
// if(numsRows == 0) return {};
// vector<vector <int>> triangle;
// for(int i = 0 ; i < numsRows ; i++){
//     vector <int> row (i+1,1);
//     for(int j = 1; j < i ; j++){
//             row[j] = triangle[i-1][j-1] + triangle[i-1][j];
//     }
//         triangle.push_back(row);
// }
// return triangle;
// }

// arr[n] if defined locally contains garbage value
// arr[n] if defined globally have all values initialesed as zero
// vector defined either globally or locally is initially empty

// nth row
// using relation between c(n,r) and c(n,r+1) TC = O(n) SC = O(n)
vector<int> pascal_triangle(int numsRows)
{
    vector<int> row;
    int element = 1;
    row.push_back(element);
    for (int i = 1; i < numsRows; i++)
    {
        element = ((element) * (numsRows - i)) / i;
        row.push_back(element);
    }
    return row;
}

// usign hash_map TC = O(n) SC = O(n)
// vector <int> majority_elements(vector <int> &nums){
//     int n = nums.size();
//     vector<int> result;
//     unordered_map <int,int> hash_map;
//     for(int i = 0 ; i < n ; i++){
//         hash_map[nums[i]]++;
//     }
//     for (auto &it : hash_map){
//         if(it.second > n/3) result.push_back(it.first);
//     }
//     return result;
// }

// elminate unique elements and you will be left with supposedly majority elements
vector<int> majority_element(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;
    int candidate1 = 0;
    int candidate2 = 0;
    int count1 = 0;
    int count2 = 0;
    for (int num : nums)
    {
        if (count1 == 0 && num != candidate2)
        {
            candidate1 = num;
            count1 = 1;
        }
        else if (count2 == 0 && num != candidate1)
        {
            candidate2 = num;
            count2 = 1;
        }
        else if (num == candidate1)
            count1++;
        else if (num == candidate2)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (auto num : nums)
    {
        if (num == candidate1)
            count1++;
    }
    for (auto num : nums)
    {
        if (num == candidate2)
            count2++;
    }
    if (count1 > (int)n / 3)
        result.push_back(candidate1);
    if (count2 > (int)n / 3)
        result.push_back(candidate2);
    return result;
}

// use three nested loops to check each possible combination and use set to avoid duplicates TC= O(n^3 * log(No. of unique triplets)) SC = O(2 * (No. of unique triplets))
// vector <vector<int>> three_sum(vector <int> &nums){
// int n = nums.size();
// if(n < 3 ) return {};
// set <vector<int>> result = {};
// for(int i = 0; i < n -2 ; i++){
//    for(int j = i +1 ; j < n - 1 ; j++){
//       for(int k = j+1 ; k < n ; k++){
//          if(nums[i]+nums[j]+nums[k] == 0) {
//            vector<int> triplet = {nums[i] , nums[j], nums[k]};
//            sort(triplet.begin(),triplet.end());
//            result.insert(triplet);
//       }
//    }
//    }
// }
// vector<vector<int>> final_result (result.begin(),result.end());
// return final_result;
// }

// use unordered map to check if the third element already exists in the set TC = O(n^2 * log(No. of unique triplets)) SC = O(n)
// vector<vector<int>> three_sum(vector<int> &nums){
// int n = nums.size();
// if(n < 3 ) return {};
// set <vector<int>> result = {};
// unordered_map <int,int> temp;
// for(int num : nums) temp[num]++;
// for(int i = 0; i < n -1 ; i++){
//     for(int j = i+ 1; j < n; j++){
//         int count = 0;
//         if(nums[i] == 0-nums[i]-nums[j]) count++;
//         if(nums[j] == 0-nums[i]-nums[j]) count++;
//         auto it = temp.find(0 - nums[i] - nums[j]);
//         if(it != temp.end() && it->second > count){
//             vector <int> triplet = {nums[i],nums[j], it-> first};
//              sort(triplet.begin(),triplet.end());
//              result.insert(triplet);
//         }
//     }
// }
// vector<vector<int>> final_result (result.begin(),result.end());
// return final_result;
// }
// using sorting and two pointers TC = O(nlogn) + O(n^2) SC = O(1)
vector<vector<int>> three_sum(vector<int> &nums)
{
    int n = nums.size();
    if (n < 3)
        return {};
    vector<vector<int>> result = {};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if (nums[i] + nums[j] + nums[k] < 0)
                j++;
            else if (nums[i] + nums[j] + nums[k] > 0)
                k--;
            else
            {
                vector<int> triplet = {nums[i], nums[j], nums[k]};
                result.push_back(triplet);
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }

                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }

    return result;
}

// use two loops and a hash_set which is updated while iterating through the array TC = O(n^3 *logM) SC = O(n+m)
// vector <vector<int>> four_sum(vector<int>&nums,long long target){
// int n = nums.size();
// if(n < 4) return{};
// set <vector<long long>> result;
// for(int i = 0 ; i < n ; i ++){
//     for(int j = i + 1; j < n ; j++){
//       unordered_set <long long> seen;
//       for(int k = j + 1; k < n; k++){
//         long long number = target - nums[i] - nums[j] -nums[k];
//         if(seen.find(number) != seen.end()){
//             vector <long long> quadraplet = {nums[i],nums[j],nums[k],number};
//             sort(quadraplet.begin(),quadraplet.end());
//         result.insert(quadraplet);
//         }
//             seen.insert(nums[k]);
//       }
//     }
// }
// return vector<vector<int>>(result.begin(),result.end());
// }

// sort the array and use two loops and then use two pointers TC = O(n^3) SC = O(1)
vector<vector<int>> four_sum(vector<int> &nums, long long target)
{
    int n = nums.size();
    if (n < 4)
        return {};
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j - 1] == nums[j])
                continue;
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
    return result;
}

//use prefix sum and hash_map TC = O(n) SC = O(n)
int longest_subarray(vector<int> &nums){
    int n = nums.size();
    int max_length = 0;
    int sum = 0;
    unordered_map <int,int> hash_map;
    hash_map[0] = -1;
    for(int i = 0 ;  i < n; i++){
        sum += nums[i];
        if(hash_map.find(sum) != hash_map.end()){
            max_length = max(max_length, i - hash_map[sum]);
        }
        else hash_map[sum] = i;

    }
    return max_length;
}

// use every subarray TC = O(n^2) SC = O(1)
// int XOR_Count(vector<int> &nums, int k){
//     int n = nums.size();
//     int count = 0;
//     for(int i = 0 ; i < n; i++){
//         int XOR = 0;
//         for(int j = i; j< n ; j++){
//          XOR ^= nums[j];
//          if(XOR == k) count ++;  
//         }
//     }
//     return count;
// }

// using prefix xor and hash_map Tc = O(N) SC = O(N)
int XOR_Count(vector<int> &nums, int k){
    int n = nums.size();
    int prefix_XOR = 0;
    int count = 0;
    unordered_map<int,int> hash_map = {{0,1}};
    for(int i = 0 ; i < n ; i++){
        prefix_XOR ^= nums[i];
        if(hash_map.find(prefix_XOR^k) != hash_map.end()){
            count += hash_map[prefix_XOR^k];
        } 
            hash_map[prefix_XOR]++;
        
    }
    return count;
}

//sorting + greedy TC = O(nlogn) SC = O(n)
vector<pair<int,int>> merge_intervals(vector<pair<int,int>> &nums){
    int n = nums.size();
    if(n < 1) return {};
sort(nums.begin(),nums.end());
vector <pair<int,int>> result;
int UL = nums[0].second;
int LL = nums[0].first;
for(int i = 1 ; i < n ; i++){
    if(nums[i].first <= UL ) UL = max(UL,nums[i].second);
    else{
        result.push_back({LL,UL});
        LL = nums[i].first;
        UL = nums[i].second;
    }
}
result.push_back({LL,UL});
return result;
}

// start from back TC = O(m+n) SC = O(1)
void merge_sorted(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();
nums1.resize(m+n);
    int left = m-1;
    int right = n-1;
    int i = m+n-1;
    while(left >= 0 && right >= 0){
        if(nums2[right] > nums1[left]){
            nums1[i] = nums2[right];
            right--;
        }
        else{
            nums1[i] = nums1[left];
            left--;
        }
i--;
    }
while( right >= 0){
     nums1[i] = nums2[right];
     right--;
     i--;
    } 

}

// solve when you can have no extra space
// swap + insertion sort TC = O(m*n) SC = O(1)
// void merge_harder(vector<int>& nums1, vector<int>& nums2) {
//     int m = nums1.size();
//     int n = nums2.size();
//     for (int i = 0; i < m; i++) {
//         if (nums1[i] > nums2[0]) {
//             swap(nums1[i], nums2[0]);
//             int first = nums2[0];
//             int j = 1;
//             while (j < n && nums2[j] < first) {
//                 nums2[j - 1] = nums2[j];
//                 j++;
//             }
//             nums2[j - 1] = first;
//         }
//     }
// }

// inspired by shell sort : fix large scale disorder first then fine tune local disorders
// every iteration ensures that elements n distance apart are ordered TC = O(m+nlog(m+n)) SC = O(1)
int next_gap(int gap){
    if(gap < 2) return 0 ;
    return (gap/2) + (gap%2);
}
void merge_harder(vector<int> &nums1, vector<int> &nums2){
int m = nums1.size();
int n = nums2.size();
int length =m+n;
for(int gap = next_gap(length); gap > 0; gap = next_gap(gap)){
    int left = 0;
    int right = left + gap;
    while (right < length){
        // when both in nums1
        if(left < m && right < m){
        if(nums1[right] < nums1[left]) swap(nums1[right],nums1[left]);
        }
        // when one in nums1  and  other in nums2
        if(left < m && right >= m){
        if(nums1[left] > nums2[right-m]) swap(nums1[left],nums2[right-m]);
        }
        //when both in nums2
        else{
            if(nums2[left-m] > nums2[right-m]) swap(nums2[left-m],nums2[right-m]);
        }
        left++;
        right++;
    }
}
}

//

int main()
{
//    vector<int> nums = {3, -5, 3, 4, -4, 3, -2, 3, 8, -4, 9, 5, 7, -2, 5, -8, -2, 7, 4, 3, -7, 4, 4};
//    vector<vector<int>> result = four_sum(nums, 15);
//     for (auto it : result)
//     {
//         for (auto i : it)
//         {
//             cout << i << " ";
//         }
//         cout << "\n";
//     }

  // cout << longest_subarray(nums) << endl;

// vector<pair<int,int>> num = {{2,3},{10,6},{3,5},{2,4},{15,17}};
// vector <pair<int,int>> result = merge_intervals(num); 
// for(auto it : result){
//         cout << it.first <<" " << it.second;
//         cout << "\n";
    //}

vector<int> nums1 = {2,4,7,9,12,15,18,21,25,30};
vector<int> nums2 = {1,3,5,8,10,11,16,20,22,28};
//vector <int> num = merge_sorted(nums1,nums2);
merge_harder(nums1,nums2);
for(auto it : nums1) cout << it << " ";
for(auto it : nums2) cout << it << " ";
}
