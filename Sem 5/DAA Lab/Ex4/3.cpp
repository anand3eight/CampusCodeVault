//LPS String Matching

#include<iostream>
#include<cstdlib>
using namespace std;

int* LPSBuilder(string p){
    int m = p.size();
    int *lps = (int*)calloc(sizeof(int), m);
    int i = 1, l = 0;
    while(i <= m){
        if(p[i] == p[l])
            lps[i++] = ++l;
        else{
            if(l > 0)
                l = lps[l-1];
            else
                lps[i++] = 0;
        }
    }
    return lps; 
}

bool KMP(string p, string s){
    int *lps = LPSBuilder(p);
    int m = p.size(), n = s.size();
    for(int i = 0, j = 0; i <= n-m+j;){
        if(s[i] == p[j]){
            i++, j++;
            if(j == m)
                return true;
        }
        else{
            if(j > 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    return false;
}

int main(){
    string p, s;
    cin >> p >> s;
    int ans = KMP(p, s);
    if(ans)
        cout << "YES";
    else    
        cout << "NO";
    return 0;
}