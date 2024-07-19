#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long double maxDistance(vector<int>& nums) {
        int dist = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            dist = max(dist, nums[i]-nums[i-1]);
        }
        return dist;
    }
  
    int countGasStations(vector<int>& stations, long double dist) {
        int n = stations.size();
        
        int gasStationsCount = 0;
        for(int i = 1; i < n; i++) {
            int stationsPlaced = ((stations[i]-stations[i-1])/dist);
            if((stations[i] - stations[i-1]) == (stationsPlaced * dist)) { // checking if distance of new stations is exactly equal to the distance between present stations
                stationsPlaced--; // then we have to remove one station since at the end the new station will overlap the old station
            }
            gasStationsCount += stationsPlaced;    
        }
        return gasStationsCount;
    }
  
    double findSmallestMaxDist(vector<int> &stations, int k) {
        long double s = 0;
        long double e = maxDistance(stations);
        long double ans = 0;
        
        long double diff = 1e-6;
        while(e - s > diff) { // since the max distance should be always greater than the threshold of decimals set
            long double mid = s+(e-s)/2;
            int gasStations = countGasStations(stations, mid);
            if(gasStations > k) {
                s = mid; // keeping as mid because in smaller distances we'll miss out on alot unused of distance
            }
            else {
                ans = mid;
                e = mid;
            }
        }
        return ans;
    }
};