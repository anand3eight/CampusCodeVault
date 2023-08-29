/*Max. No. of Platforms Required for given set of trains
Note : Time format -> 10:00 - 1000, 9:50 - 950 */

#include<iostream>
using namespace std;

int f1(int *st, int *end, int n){
    //Naive Approach
    int ans = 1;
    for(int i = 0; i < n; i++){
        int cur = 1;
        for(int j = 0; j < n; j++){
            if(i != j and st[i] >= st[j] and st[i] <= end[j])
                cur++;
        }
        ans = max(ans, cur);
    }
    return ans;
}

int f2(int *st, int *end, int n){
    //Using Sorting
    sort(st, st+n);
    sort(end, end+n);
    int i = 1, j = 0, ans = 1, cur = 1;
    while(i < n and j < n){
        if(st[i] <= end[j]){
            cur++;
            i++;
        }
        else{
            cur--;
            j++;
        }
        ans = max(ans, cur);
    }
    return ans;
}

int f3(int *st, int *end, int n){
    //Sweep Line Algorithm
    int maxEnd = *max_element(end, end+n);
    vector<int> v(maxEnd+2, 0);
    for(int i = 0; i < n; i++)
        v[st[i]]++, v[end[i]+1]--;
    int ans = 0, count = 0;
    for(auto i : v){
        count += i;
        ans = max(ans, count);
    }
    cout << endl;
    return ans;
}

int PlatformCount(int *st, int *end, int n){
    // return f1(st, end, n);
    // return f2(st, end, n);
    return f3(st, end, n);
}

int main(){
    int st[] = {900, 940, 950, 1100, 1500, 1800};
    int end[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = sizeof(st)/sizeof(st[0]);
    cout << PlatformCount(st, end, n);
    return 0;
}
