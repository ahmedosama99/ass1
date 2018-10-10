#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0 , z = 0 , c = 0;
    vector <int> grade ;
    while(true){
        cout << "enter your grade : " ;
        cin >> x;
        if(x==-1){
            break;
        }
        grade.push_back(x);
    }
    sort(grade.begin(),grade.end());
    for(int i = 0 ; i < grade.size() ; i++ ){
        cout << endl<<"your grade is : " << grade[i];
    }
    z=grade[0];
    for(int i = 0 ; i <= grade.size() ; i++ ){
        if(z==grade[i]){
            c+=1;
        }
        if(z!=grade[i]){
            cout<< endl<<"number of "<<z<<"'s:\t"<<c;
            z=grade[i];
            c=1;
        }
    }
    return 0;
}
