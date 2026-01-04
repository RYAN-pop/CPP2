#include "..\my.h"

class vec{
    int *data=nullptr;
    int size;
public:
    vec(int size=0):size(size){
        data=new int[size];
        for(int i=0;i<size;i++){data[i]=9;}
    }
    vec(const vec& v){
        size=v.size;
        data=new int[size];
        for(int i=0;i<size;i++){
            data[i]=v.data[i];
        }
        cout<<"copy ";debug(size);

    }
    vec(vec && v):data(v.data),size(v.size){
        v.data=nullptr;
        cout<<"move\n";
    }

    ~vec(){
        debug(*this);delete [] data;
    }
    vec& pushBack(int add){
        int newSize=size+1;
        int *newdata;
        newdata=new int[newSize];
        for(int i=0;i<size;i++){
            newdata[i]=data[i];
        }
        newdata[size]=add;
        delete [] data;
        data=newdata;
        size=newSize;
        return *this;
    }
    int& operator[](const int index){
        return data[index];
    }
    vec operator+(const vec& other){
        vec v(size+other.size);
        for(int i=0;i<size;i++){
            v.data[i]=data[i];
        }
        for(int i=0;i<other.size;i++){
            v.data[i+size]=other.data[i];
        }
        return v;
    }
    friend ostream& operator<<(ostream& output,const vec& other){
        for(int i=0;i<other.size;i++){
            output<<other.data[i]<<" ";
        }
        return output;
    }
};

int main(){
    vec v(3); //v1{v};
    vec v3(v.pushBack(99));
    v[2]=1;
    vec v4(v+v3);
    v4.pushBack(2);
    debug(v4);
    //v4=v+v3;
    //cout<<v<<endl<<v1<<endl<<v.pushBack(77)<<endl;
    
}
