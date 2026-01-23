#include"../my.h"
using Vec=vector<int>;

void permutation1(Vec v,Vec prefix){
    for(int i=0;i<v.size();i++){
        Vec t=v;
        prefix.push_back(t[i]);
        t.erase(t.begin()+i);
        if(t.size()==0){ 
            cout<<prefix<<endl;
            return;
        } 
        permutation1(t,prefix);
        prefix.pop_back();
    }
}

void permutation(Vec v,int a){
    //cout<<a<<",";debug(v);
    static Vec prefix;
    for(int i=0;i<v.size();i++){
        Vec t=v;
        prefix.push_back(*(t.begin()+i));
        t.erase(t.begin()+i); 
        if(t.size()==0){ cout<<prefix<<endl;prefix.pop_back();return;} 

        permutation(t,a+1);
    }
}
int main(){
    Vec v={1,2,3,4,5};
    permutation1(v,{});
}