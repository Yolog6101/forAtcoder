#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;

    //nの2進数文字化
    string n_2="";
    while(n>1){
        //int->charは+'0'
        //char->intは-'0'
        n_2.push_back(n%2+'0');
        n/=2;
    }
    n_2.push_back(n+'0');
    reverse(n_2.begin(),n_2.end());//逆順になっているため


    //上の桁(左)から見て、n_2とsが違う文字になる桁を探す
    //この時、文字数の多い方に合わせるため、まず左0埋めをする
    if(n_2.size()>s.size()){
        reverse(s.begin(),s.end());
        for(int z=0;z<n_2.size()-s.size();z++){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
    }
    else if(n_2.size()<s.size()){
        reverse(n_2.begin(),n_2.end());
        for(int z=0;z<s.size()-n_2.size();z++){
            n_2.push_back('0');
        }
        reverse(n_2.begin(),n_2.end());
    }
    else{
    }

    cout << s <<endl <<n_2<<endl;



}