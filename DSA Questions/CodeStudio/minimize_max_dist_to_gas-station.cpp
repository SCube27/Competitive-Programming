#include<bits/stdc++.h>
using namespace std;

int no_of_gas_stations(vector<int>& arr, long double mid) {
    int count = 0; // to keep the count of the gas stations

    for(int i = 1; i < arr.size(); i++) {

        int stations_in_between = ((arr[i]-arr[i-1]) / mid); // calculating possbile new stations in between two existing stations for given mid 
        if((arr[i] - arr[i-1]) / mid == stations_in_between * mid) { // If division gives absolute value 
            stations_in_between--; // then reduce the possible new stations in between by one
        }

        count += stations_in_between; // Else directly add up the number of new gas stations to count
    }
    return count;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long double s = 0;
    long double e = 0;
    for(int i = 0; i < n-1; i++) {
        e = max(e, (long double)(arr[i+1]-arr[i])); // keeping end as longest gap between two existing gas stations
    }

    long double diff = 1e-6;
    while(e-s > diff) { // we do this for such type of diff
        long double mid = s+(e-s)/(2.0);
        int gas_stations = no_of_gas_stations(arr, mid); // count the possible new gas stations for calculated mid

        if(gas_stations > k) { // If count is greater then its not possible and hence move start
            s = mid;
        }
        else { // Else if count is smaller or equal, its possible and hence move end
            e = mid;
        }
    }
    cout << e; // Return e since principle of inversion wont work
}

int main() {
    solve();
}
