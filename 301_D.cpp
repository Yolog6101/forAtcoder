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


    //上の桁(左)から見て、n_2が1かつsが0か?になる桁を探す
    //この時、文字数の多い方に合わせるため、まず左0埋めをする
    if(n_2.size()>s.size()){
        reverse(s.begin(),s.end());
        for(int z=0;z<n_2.size()-s.size()+1;z++){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
    }
    else if(n_2.size()<s.size()){
        reverse(n_2.begin(),n_2.end());
        for(int z=0;z<s.size()-n_2.size()+1;z++){
            n_2.push_back('0');
        }
        reverse(n_2.begin(),n_2.end());
    }
    else{
    }
    cout << s <<endl <<n_2<<endl;

    int check=-1;
    for(int i=0;i<s.size();i++){
        //異なる桁になる場合がまず存在するか?
        if(n_2.at(i)!=s.at(i)){
            //この時、s.at(i)が1でn_2.at(i)が0なら即座に-1を出力
            if(n_2.at(i)=='0'&&s.at(i=='1')){
                cout << "-1" << endl;
                return 0;//強制終了
            }
            //それ以外ならiでは('?'なら)0、iより小さい位で'?'をすべて'1'に
            if(s.at(i)=='?'){
                s.at(i)='0';
            }
            for(int j=i;j<s.size();j++){
                if(s.at(j)=='?'){
                    s.at(j)='1';
                }
            }
            //最後に、sを10進数にして終わり
            
            

     
        }
    }
    cout << n << endl;




}