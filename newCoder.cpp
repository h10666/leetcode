#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> charac(26,0);
    string s;
    for(int i = 0; i<4; i++){
        getline(cin,s);
        for(int j = 0; j<s.length(); j++){
            if(s[j]>='A'&&s[j]<='Z')
            charac[s[j]-'A']++;
        }
    }
    int mx = *max_element(charac.begin(),charac.end());
    while(mx){
        for(int j = 0; j<26; j++){
            if(charac[j]==mx)
            {    cout<<"*";charac[j]--;}
            else{
                cout<<" ";
            }
            if(j<25)cout<<" ";
        }
        cout<<endl;
        mx--;
    }
    for(int i = 0; i<25; i++)
    {
        char c = 'A';
        cout<<char(c+i)<<" ";
    }cout<<"Z";
    return 0;
}