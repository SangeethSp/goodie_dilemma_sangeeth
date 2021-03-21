#include <bits/stdc++.h>
using namespace std;

int main() {
 freopen("sample_input.txt", "r", stdin);
 string x, temp_key;				//key is goodie name
    int m, temp_value;				// value is goodie price
    vector <pair <int,string>> Goodies;
 while(cin>>x){
        if(x[x.length()-1] == ':'){
            temp_key += x.substr(0,x.length()-1);
            if(temp_key == "Goodies and Prices"){
                cout<<endl;
            }
            else if(temp_key == "Number of employees"){
                cin>>x;
                m = stoi(x);
                cout<<temp_key<<" "<<m<<endl;
            }
            else{
                cin>>x;
                temp_value = stoi(x);
                cout<<temp_key<<" "<<temp_value<<endl;
                Goodies.push_back(make_pair(temp_value,temp_key));
            }
            temp_key = "";
        }
        else {
            temp_key += x;
            temp_key += ' ';
        }
 }
 int temp1;
    
    for ( int i = 0 ; i<10 ; i++) {    
    for(int j = 0; j < 10; j++){ 
    if(i!=j){
        if(Goodies[i].first < Goodies[j].first){
              temp1=Goodies[i].first;
              Goodies[i].first=Goodies[j].first;
              Goodies[j].first=temp1;
          }
    	}
    }
}
    int ans = INT_MAX, ans_ind, temp;
    for(int i=0;(i<Goodies.size()) && (i+m-1 <= (Goodies.size()-1));i++){
        temp = Goodies[i+m-1].first - Goodies[i].first;
        if( ans > temp){
            ans = temp;
            ans_ind = i;
        }
    }
    cout<<"The goodies selected for distribution are:\n\n";
    for(int i=0;i<m;i++){
        cout<<Goodies[i+ans_ind].second<<": "<<Goodies[i+ans_ind].first<<endl;
    }
    cout<<endl;
    cout<<"And the difference between the chosen goodie with highest price and the lowest price is "<<ans<<"\n";
 return 0;
}
