#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // better approach
    double findMedianSortedArraysBetter(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0, j = 0;
        int n = n1+n2;
        int ind2 = n/2;
        int ind1 = ind2 - 1;
        int ind1el = -1, ind2el = -1;
        int count = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) {
                if(count == ind1) ind1el = nums1[i];
                if(count == ind2) ind2el = nums1[i];
                count++;
                i++;
            }
            else {
                if(count == ind1) ind1el = nums2[j];
                if(count == ind2) ind2el = nums2[j];
                count++;
                j++;
            }
        }

        while(i < n1) {
            if(count == ind1) ind1el = nums1[i];
            if(count == ind2) ind2el = nums1[i];
            count++;
            i++;
        }
        while(j < n2) {
            if(count == ind1) ind1el = nums2[j];
            if(count == ind2) ind2el = nums2[j];
            count++;
            j++;
        }

        if(n%2 == 1) {
            return ind2el;
        }
        else {
            return (double)((double)(ind1el + ind2el)) / 2.0;
        }
    }

    // optimal approach
    double findMedianSortedArraysOptimal(vector<int>& arr1, vector<int>& arr2)
    {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        if(n1 > n2) return findMedianSortedArraysOptimal(arr2, arr1); // for getting the smaller array for binary search saving time
        
        int n = n1+n2;
        
        int s = 0;
        int e = n1;
        
        int left = (n1+n2+1)/2; // numbers required on left of the partition
        
        while(s <= e) {
            int mid1 = s+(e-s)/2;
            int mid2 = left-mid1;

            // initializing values incase no elements are taken from their side
            int l1 = INT_MIN, l2 = INT_MIN; 
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1 < n1) r1 = arr1[mid1]; // if mid1 is smaller than the size of its array, then assign r1 
            if(mid2 < n2) r2 = arr2[mid2]; // same as above
            if(mid1-1 >= 0) l1 = arr1[mid1-1]; // if mid1-1 is greater than 0th index then assign l1
            if(mid2-1 >= 0) l2 = arr2[mid2-1]; // same as above
            
            if(l1 <= r2 && l2 <= r1) { // if both the left index are smaller then rights its a optimal partition
                if(n % 2 == 1) return max(l1, l2); // for odd size array
                else return (double)(max(l1, l2) + min(r1, r2))/2.0; // for even size array
            }
            else if(l1 > r2) { // if l1 is greater than r2 then the number of arr1 elements on left should be reduced
                e = mid1 - 1;
            }
            else { 
                s = mid1 + 1;
            }
        }
        return 0;
    }
};