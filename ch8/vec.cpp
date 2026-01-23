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
    const int& operator[](const int index)const{
        return data[index];
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
    
    operator bool(){return size;}

    friend ostream& operator<<(ostream& output,const vec& other){
        for(int i=0;i<other.size;i++){
            output<<other.data[i]<<" ";
        }
        return output;
    }
};
class student{
    vector<vec> record;
    vec best;
    int totalScore;
    using IL=initializer_list<vec>;
public:
    student(const IL& il):record(il){
        best=record[0];
        int score=0;
        for(int i=0;i<3;i++)
            score+=record[0][i];
        for(int i=1;i<record.size();i++){
            int total=0;
            for(int j=0;j<3;j++){
                total+=record[i][j];
            }
            if(total>score){
                score=total;
                best=record[i];
            } 
        }
        totalScore=score;
    }
    void add(const vec& v){
        record.push_back(v);
        best=record[0];
        int score=0;
        for(int i=0;i<3;i++)
            score+=record[0][i];
        for(int i=1;i<record.size();i++){
            int total=0;
            for(int j=0;j<3;j++){
                total+=record[i][j];
            }
            if(total>score){
                score=total;
                best=record[i];
            } 
        }
        totalScore=score;
    }
    void output(){
        cout<<"best: ";
        for(int i=0;i<3;i++)cout<<best[i]<<" ";
        cout<<"\ntotal: "<<totalScore<<endl;
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
void testBool(){
     vec v{1,2,3};
    int x=-3;
    while(cin>>x){
        //cin>>x;
        v.pushBack(x);
    }
    debug(v);
    cin.clear();
    string y;cin>>y;
    debug(y);
    if(v){cout<<"abc";}
}
void testConst(){
    const vec v{5,6,7,8};
    cout<<v[0];
    cout<<v[0];
    //v.pushBack(v,-9);
}
void f1(vec a){debug(a);}
void testStudent(){
    vec v{1,2,3};
    vec v1{2,3,4};
    vec v2{3,4,5};
    student s{{0,1,1}};
    s.output();
    s.add(v);
    s.add(v1);
    s.output();
    s.add(v2);
    s.output();
}
int main(){
    //testIterator();
    vec v{1,2,3}; //v1{v};
    vec v1(v.pushBack(93));
    v[2]=1;
    vec &r=v;
    //vec v2(std::move(v+v1));
    //vec v2=std::move(v+v1);
    vec v2=v+v1; debug(v2);
    //f1(3);
    //v2.pushBack(2);
    //debug((v+v1)[2]);
    //vec v2;
    //v2=v+v1;
    //cout<<v<<endl<<v1<<endl<<v.pushBack(77)<<endl;
    //testBool();
    testStudent();
}
