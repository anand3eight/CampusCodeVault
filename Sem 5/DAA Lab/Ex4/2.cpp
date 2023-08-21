//String Matching Algorithm

#include<iostream>
using namespace std;

bool stringMatch(string p, string s){
    int m = p.size(), n = s.size();
    int i, j, flag = 0;
    while(m <= n){
        for(i = 0, j = 0; i < n and j < m; i++, j++){
            if(s[i] != p[j])
                break;
        }
        if(j == m)  
            return true;
        else{
            s = s.substr(i+1, n);
            n = s.size();
        }
    }
    return false;
}

int main(){
    string p, s;
    cin >> p >> s;
    int ans = stringMatch(p, s);
    if(ans)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}