#include <bits/stdc++.h>
using namespace std;

// Time complexity = O(n^2) (always)
void selection_sort(int n, int arr[])
{

    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void bubble_sort(int n, int arr[])
{
    for (int j = 0; j < n - 1; j++)
    {
        bool did_swap = false;
        for (int i = 0; i < n - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                did_swap = true;
            }
        }
        if (!did_swap)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void insertion_sort(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int k = i;
        while (k > 0 && arr[k - 1] > arr[k])
        {
            swap(arr[k], arr[k - 1]);
            k--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void merge(int low, int mid, int high, vector<int> &arr)
{

    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void merge_sort(int low, int high, vector<int> &arr)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    merge_sort(low, mid, arr);
    merge_sort(mid + 1, high, arr);
    merge(low, mid, high, arr);
}

void bubble_sort_recursive(int arr[], int n)
{
    if (n == 1)
        return;
    bool swapped = false;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }
    if (!swapped)
        return;
    bubble_sort_recursive(arr, n - 1);
}

void insertion_sort_recursive(int arr[], int n){
    if( n <= 1 ) return;
     insertion_sort_recursive(arr, n-1);
     int k = n-1;
   while( k > 0 && arr[k-1] > arr[k]){
    swap(arr[k],arr[k-1]);
    k--;
   }
}

// void quick_sort(list <int> temp , int n,int pivot,int arr[]){
// for(int i = 0; i < n; i++){
//     if(arr[i] >= arr[pivot]) temp.push_back(arr[i]);
//     else temp.push_front(arr[i]);
// }
// }

int partition(int arr[], int low , int high){
int pivot = arr[low];
int i = low;
int j = high;
while(i<j){
    while (arr[i] <= pivot && i <= high -1) i++;
    while(arr[j] > pivot && j >= low + 1 ) j--;
    if(i<j) swap(arr[i] , arr[j]);
}
swap(arr[low] , arr[j]);
return j;
}

void quick_sort(int arr[],int low , int high){
if(low >= high) return;
 int pindex = partition(arr,low,high);
quick_sort(arr,low,pindex -1);
quick_sort(arr,pindex+1,high);

}

int main()
{
    int n;
    cin >> n;

    //      vector<int> arr(n);
    //    for(int i = 0 ; i < n ; i++){
    //     cin >> arr[i];
    //    }
    // merge_sort(0,n-1,arr);
    // for(int x : arr)  cout << x << " ";
    // cout << endl;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    selection_sort(n, arr);
    cout << endl;
    bubble_sort(n, arr);
    cout << endl;
    insertion_sort(n, arr);
    cout << endl;
}