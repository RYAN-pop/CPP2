#include "..\my.h"

class vec{
    int *data=nullptr;
    int size;
    using IL=initializer_list<int>;
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
    vec(const IL& other):size(other.size()),data(new int[other.size()]){
        //copy(other.begin(),other.end(),data);
        //int count=0;
         auto p=data;
        for(auto x=other.begin();x!=other.end();x++){
            //data[count]=*x;count++;
            *p++=*x;
        }
    }
    ~vec(){
        cout<<"size="<<size<<",";
        debug(*this);
        if(!data) delete [] data;
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
    /*vec& operator=(const vec& other){
        size=other.size;
        delete [] data;
        data=new int[size];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
        return *this;
    }*/
    vec& operator=(const vec& other){
        if(data==other.data){
            return *this;
        }
        size=other.size;
        delete [] data;
        data=new int[size];
        for(int i=0;i<size;i++){
            data[i]=other.data[i];
        }
        return *this;
    }
    friend ostream& operator<<(ostream& output,const vec& other){
        for(int i=0;i<other.size;i++){
            output<<other.data[i]<<" ";
        }
        return output;
    }
};
void testIterator(){
     vector<int> x{1,2,3};
    vector<double> y;
    for(int i=0;i<x.size();i++){x[i]++;}
    for(int& i : x){i++;}
    for(auto p=x.begin();p!=x.end();p++){
        (*p)++;
    }
    debug(x);
    for(int i=0;i<x.size();i++){
        y.push_back(x[i]);
    }
    debug(y);
}
int main(){
    testIterator();
    vec v{1,2,3}; //v1{v};
    debug(sizeof(v));
    vec v1(v.pushBack(99));
    v[2]=1;
    //vec v2(std::move(v+v1));
    //vec v2=std::move(v+v1);
    vec v2=v+v1;
    //v2.pushBack(2);
    //debug(v+v1);
    //vec v2;
    //v2=v+v1;
    //cout<<v<<endl<<v1<<endl<<v.pushBack(77)<<endl;
    debug(sizeof(v));
}
