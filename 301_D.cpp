//ABC301-D Bitmask ビット演算を一切使わないアルゴリズム
//https://atcoder.jp/contests/abc301/tasks/abc301_d
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;

    //nの2進数文字化
    int cal=n;
    string n_2="";
    while(cal>1){
        //int->charは+'0'
        //char->intは-'0'
        n_2.push_back((cal%2)+'0');
        cal/=2;
    }
    n_2.push_back(cal+'0');
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

    for(int i=0;i<s.size();i++){
        //異なる桁になり、かつs.at(i)!='?'の場合がまず存在するか?
        if(n_2.at(i)!=s.at(i)&&s.at(i)!='?'){
            //この時、s.at(i)が1でn_2.at(i)が0なら即座に-1を出力
            if(n_2.at(i)=='0'&&s.at(i)=='1'){
                cout << "-1" << endl;
                return 0;//強制終了
            }
            //それ以外ならiより小さい位で'?'をすべて'1'に、iより大きい位で'?'をnにそろえる
            for(int j=i;j<s.size();j++){
                if(s.at(j)=='?'){
                    s.at(j)='1';
                }
            }
            for(int k=0;k<i;k++){
                if(s.at(k)=='?'){
                    s.at(k)=n_2.at(k);
                }
            }

            
            //最後に、sを10進数にして終わり
            reverse(s.begin(),s.end());
            int ans=0;
            int c=1;//計算用
            for(int l=0;l<s.size();l++){
                ans+=(s.at(l)-'0')*c;
                c*=2;
            }
            cout << ans << endl;

            return 0;

     
        }
    }
    cout << n << endl;




}