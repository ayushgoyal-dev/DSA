#include <bits/stdc++.h>
using namespace std;

// //trim the candidate by halfing O(log n) and then use increase linearly to find the answer O(√n/2)
// //TC = O(√n) SC = O(1)
// int square_root(int n){
//     if(n == 0 || n == 1) return n;
// // candidate
//     int ans = n;
//     // halfing the candidate
//     while(n/ans < ans){
//         ans /= 2;
//     }
//     // lineraly increasing to find the answer
//     while(n/ans >= ans){
//         ans++;
//     }
//     return ans - 1;
// }

// use BS from 1 to n and high will point to the answwer TC = O(log n) SC = O(1)
int square_root(int n){
    if(n == 1 || n == 0) return n;
    int low = 1;
    int high = n;
    int ans =0;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(n/mid >= mid){
        ans = mid;
         low = mid +1;
       }
        else high = mid - 1;
    }
    return ans;
}

// function to check if the nth_power exceeds m while avoiding overflow
int power_check(int mid ,int m , int n){
    long long product = 1;
    for(int i = 0 ; i< n ; i++){
        // would exceed m
        if(product > m/mid) return 1;
        product *= mid;
    }
    if(product == m) return 0;
    // less than m
    return -1;
}

// use standard BS while checking nth_power of mid TC = O(log m) SC = O(1)
int nth_root(int m , int n){
    if(m == 0 || m == 1) return m;
    int low = 1;
    int high = m;
    while(low <= high){
  int mid = low + (high-low)/2;
  int state = power_check(mid,m,n);
  if(state == 0) return mid;
  else if(state < 0) low = mid +1;
  else high = mid -1;
    }
    return -1;
}

// We iterate the whole array to calculate time required for each pile TC = O(n) SC = O(1)
long long time_needed(vector<int> &piles, int mid){
int n = piles.size();
long long time = 0;
for(int i = 0 ; i < n ; i++){
    // this calculates ceil(piles[i]/mid)
    time += (piles[i] + mid - 1) / mid;
}
return time;
}

// Perform BS on speed of eating banana(k) TC = O(n *log m) + O(n) SC = O(1)
int koko_bananas(vector <int> &piles , int h){
    int n = piles.size();
    int low = 1;
    // requires O(n) time 
    int high = *max_element(piles.begin(), piles.end());
    while(low < high){
int mid = low + (high-low)/2;
long long time = time_needed(piles,mid);
if(time <= h) high = mid;
else low = mid + 1;
    }
    return high;
}

int boquets_made(vector<int> bloomDay , int days , int k){
    int n = bloomDay.size();
    int boquets = 0;
    int flowers = 0;
   for(int i =0 ; i<n ; i++ ){
    if(bloomDay[i] <= days) {
        flowers++;
    if(flowers == k){ boquets ++; flowers =0;}
}
   else flowers = 0;
   }
   return boquets;
}

int min_days(vector<int> &bloomDay, int m, int k){
    int n = bloomDay.size();
    if(m > n/k) return -1;
    int low = *min_element(bloomDay.begin(),bloomDay.end());
    int high = *max_element(bloomDay.begin(),bloomDay.end());
    while(low < high){
        int mid = low + (high-low)/2;
        int boquets = boquets_made(bloomDay,mid,k);
         if(boquets < m) low = mid +1;
         else high = mid;
    }
    return high;
}

int summation(vector<int> &nums,int divisor){
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i< n ;i++){
sum += (nums[i]+divisor-1)/divisor;
    }
    return sum;
}

int smallestDivisor(vector<int>& nums, int threshold) {
     int n = nums.size();
     int low = 1;
     int high = *max_element(nums.begin(),nums.end());
     while(low < high){
        int mid = low + (high-low)/2;
        int sum = summation(nums,mid);
        if(sum > threshold) low = mid +1;
        else high= mid;
     }  
     return high;
 }

int days_needed(vector<int> &weights,int mid){
    int n = weights.size();
    int day = 1;
    int current = 0;
    for(int i = 0 ; i< n; i++){
if(current + weights[i] > mid){
    day++;
    current = weights[i];
}
else current += weights[i];
    }
    return day;
}

int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    while(low < high){
        int mid = low + (high-low)/2;
        int din = days_needed(weights,mid);
        if(din > days ) low = mid +1;
        else high = mid;
    } 
    return high;   
    }

int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
        int missing = arr[mid] - mid - 1;
        if(missing < k) low = mid + 1;
        else high = mid - 1; 
        }
        return low + k;
    }

int cows_required(vector<int> &stalls , int distance){
    int n = stalls.size();
int cows = 1;
int last = stalls[0];
for(int i = 1; i < n ;i++){
    if(stalls[i] - last >= distance) {cows++; last = stalls[i];}
}
return cows;
}

int aggressiveCows(vector<int> &stalls, int k)
{
 int n = stalls.size();
 sort(stalls.begin(),stalls.end());
 int low = 1;
 int high = stalls[n-1] - stalls[0];
 while(low <= high){
    int mid = low + (high-low)/2;
    int cows = cows_required(stalls,mid);
    if(cows >= k) low = mid + 1;
    else high = mid -1;
 }
 return high;
}

// Calculate the number of student required to get mid as mamimum marks TC = O(n) SC = O(1)
int student_needed(vector<int> &arr,int mid){
      int count = 1; // number of student
      int sum = 0; // number of pages
      for(int i = 0;i< arr.size(); i++){
        // number of pages > maximum
          if(sum + arr[i] > mid){
              count++;
              sum = 0;
          }
          sum += arr[i];
      }
      return count;
  }

// Perform BS on number of pages and use funcion to calculate number of students TC = O(n log M) SC = O(1)
int find_pages(vector<int> &arr, int k) {
        if(k > arr.size()) return -1;
        int low = *max_element(arr.begin(),arr.end()); // sabsse moti kitaab 
        int high = accumulate(arr.begin(),arr.end(),0); // all books to one student
        while(low < high){
            int mid = low + (high - low)/2;
            int students = student_needed(arr,mid);
            if(students > k) low = mid +1;
            else high = mid;
        }
        return high;
    }

int max_distance(vector <int> &stations){
     int n = stations.size();
      int maximum = INT_MIN;
      for(int i = 1; i < n; i++){
          maximum = max(maximum,stations[i] - stations[i-1]);
      }
      return maximum;
  }
  
int stations_required(vector<int> &stations,long double d){
      int n =stations.size();
      int station = 0;
      for(int i = 1 ;i <n ; i++){
          int distance =stations[i] - stations[i-1];
              int needed = (distance / d);
           if(distance == needed *d) needed--;
           station += needed;
      }
      return station;
  }
  
long double Gas_stations(vector<int> &stations, int K) {
        int n = stations.size();
      long double low = 0;
        long double high = max_distance(stations);
        // d should be correct upto 6 decimal places
        while(high - low >= 1e-6){
           long double mid = low + (high-low)/2.0;
          int  station = stations_required(stations,mid);
            if(station > K) low = mid; // non feasiable
            else high = mid; // feasiable
        }
        return high;
    }

float sorted_array(vector<int> &nums1, vector<int> &nums2){
    int m = nums1.size(); // BS is performed on this array 
    int n = nums2.size(); // This array is automatically partitioned
    int low = 0 ;
    int high = m;
    int left_max, right_min;
while(low <= high){
     int maxleftA = INT_MIN;
    int maxleftB = INT_MIN;
    int minrightA = INT_MAX;
    int minrightB = INT_MAX;
    int partitionA = low +(high-low)/2;
    int partitionB = (m+n+1)/2 - partitionA;
    // assigning values to max of left part and min of right part
    if(partitionA > 0) maxleftA = nums1[partitionA-1];
    if(partitionA < m) minrightA = nums1[partitionA];
   if(partitionB > 0) maxleftB = nums2[partitionB-1];
    if(partitionB <n)minrightB = nums2[partitionB];
    // checking if the partition is valid
    if(maxleftA <= minrightB && maxleftB <= minrightA){ // this condition checks if every left element is smaller than every right element
        left_max = max(maxleftA,maxleftB);
        right_min = min(minrightA,minrightB);
        break;
    }
    // partition is too right 
    if(maxleftA > minrightB) high = partitionA - 1;
    else low = partitionA +1;
}
if((m+n)%2 != 0) return left_max;
else return (left_max+right_min)/2.0;
}

float median_sorted(vector<int> &nums1,vector<int> &nums2){
    int m = nums1.size();
    int n = nums2.size();
    if(n < m) swap(nums1,nums2);
    return sorted_array(nums1,nums2);
}

int kth_element(vector<int> &arr1, vector<int>& arr2,int k){
int n =arr1.size();
int m = arr2.size();
// partitionB = k - partitionA
// 0 <= partitionB <= m
int low = max(0,k-m);
int high = min(n,k);
int left_max,right_min;
while(low <= high){
    int maxleftA = INT_MIN;
    int maxleftB = INT_MIN;
    int minrightA = INT_MAX;
    int minrightB = INT_MAX;
    int partitionA = low +(high-low)/2;
    int partitionB = k - partitionA;
    if(partitionA > 0) maxleftA = arr1[partitionA-1];
    if(partitionA < n) minrightA = arr1[partitionA];
    if(partitionB > 0) maxleftB = arr2[partitionB-1];
    if(partitionB < m) minrightB = arr2[partitionB];
    // check if partition is valid
    if(maxleftA <= minrightB && maxleftB <= minrightA){
        left_max = max(maxleftA,maxleftB);
      right_min = min(minrightA,minrightB);
        break;
    }
    else if(maxleftA > minrightB) high = partitionA -1;
    else low = partitionA +1;
}
return left_max;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
if(n > m) swap(arr1,arr2);
return kth_element(arr1,arr2,k);
}

int main(){
   // vector <int> piles = {1,1,1,999999999}; 
//cout << square_root(122) << " " <<  nth_root(1024,10);
//cout << koko_bananas(piles,10);

}