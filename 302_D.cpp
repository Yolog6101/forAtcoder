#include<bits/stdc++.h>
using namespace std;
/*計算量的に全探索は無理なので、
最大のものから取り出す贈り物を変えて差をDに近づけていく(和が最大ならいいので)*/


int main(){
    int n,m;
    long long d;
    cin >> n >> m >> d;
    vector<long long> a(n);
    vector<long long> b(m);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    for(int j=0;j<m;j++){
        cin >> b.at(j);
    }
    
    //まず低い順にソートしておく
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long a_choice=0;
    long long b_choice=0;
    bool checker=false;

    while(checker==false){
        //aの最大・bの最大を取り出す
        a_choice=a.at(a.size()-1);
        b_choice=b.at(b.size()-1);

        //差がd以下の場合は出力して終わり
        if(a_choice>b_choice){
            if(a_choice-b_choice<=d){
                cout << a_choice+b_choice <<endl;
                checker=true;
            }
            else{
            //aの最大>bの最大の時、bをそれ以下のものにしても総和は増えるだけなのでaの最大は考慮しなくてよくなる
                a.pop_back();    
            }
        }
        else{
            if(b_choice-a_choice<=d){
            cout << a_choice+b_choice <<endl;
            checker=true;
            }
            else{
            //bの最大>aの最大の時、aをそれ以下のものにしても総和は増えるだけなのでbの最大は考慮しなくてよくなる
                b.pop_back();     
            }
        }


        //どちらかの要素候補がなくなったら-1出力して終了
        if(a.size()==0||b.size()==0){
            cout << -1 << endl;
            checker=true;
        }
        
    }


}