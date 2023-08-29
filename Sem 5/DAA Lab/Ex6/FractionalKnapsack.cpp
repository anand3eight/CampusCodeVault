/* Fractional Knapsack Problem
Find the max Profit from Given set of Weights */

#include<iostream>
using namespace std;
typedef struct Item Item;
struct Item{
    int p, w;
    Item(int p, int w){
        this->p = p;
        this->w = w;
    }
};

static bool cmp(Item a, Item b){
    double r1 = (double)a.p/(double)a.w;
    double r2 = (double)b.p/(double)b.w;
    return r1 > r2;
}

double f1(Item *arr, int W, int n){
    //Greedy Approach - Based on Profit Ratio
    sort(arr, arr+n, cmp);
    double ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i].w <= W){
            ans += arr[i].p;
            W -= arr[i].w;
        }
        else
            ans += (double)W/(double) arr[i].w * (double)arr[i].p;
    }
    cout << endl;
    return ans;
}

int FractionalKnapsack(Item *arr, int W, int n){
    return f1(arr, W, n);
}

int main(){
    Item arr[] = {{100, 20}, {60, 10}, {120, 30}};
    int W = 50;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << FractionalKnapsack(arr, W, n);    
    return 0;
}
