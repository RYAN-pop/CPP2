#include"../my.h"
enum Sex{male=0,female=1};
class Person{
public:
    string name;
    int age;
    Sex sex;

    //ostream& operator<<(ostream& output,const Sex& sex);    
    friend istream& operator>>(istream& input,Person& p);
    friend ostream& operator<<(ostream& output,const Person& p);

    Person operator=(const Person& p){
        name=p.name;
        age=p.age;
        sex=p.sex;
        return *this; 
    }
    explicit operator bool(){return age>0;}
};
ostream &operator<<(ostream &output, const Sex &sex)
{
    if (sex == male)        cout << "male\n";
    else if(sex == female)  cout << "female\n";
    else                    throw(2);
    return output;
}
istream &operator>>(istream &input, Sex &sex)
{
    string m;
    input>>m;
    if (m == "male")        sex=male;
    else if(m == "female")  sex=female;
    else                    throw(1);
    return input;
}
ostream& operator<<(ostream& output,const Person& p){
        cout<<"name: "<<p.name<<endl;
        cout<<"age: "<<p.age<<endl;
        cout<<"sex: "<<p.sex<<endl;
        return output;
    }

istream& operator>>(istream& input,Person& p){
        cout<<"enter Person name: ";input>>p.name;
        cout<<"enetr Person age: ";input>>p.age;
        cout<<"enetr Person sex: ";input>>p.sex;
        return input;
    }
class comment{
public:
    int rating;
    string comment;
    void set(){
        cout<<"your rating: ";cin>>rating;
        cout<<"your comment: \n";
        getline(cin,comment);
    }
    void print(){
        cout<<"rating: "<<rating<<endl;
        cout<<comment<<endl;
    }
};
class Trainer:protected Person{
public:
    double star;
    vector<comment> comments;
    Trainer():star(0){}
    void getdata(const comment& c){
        comments.push_back(c);
        star=double(star+c.rating)/comments.size();
    }
    
    Trainer operator=(const Trainer& t){
        star=t.star;
        comments=t.comments;
        return *this;
    }
    friend ostream& operator<<(ostream& output,const Trainer& t){
        cout<<"name: "<<t.name<<endl;
        cout<<"age: "<<t.age<<endl;
        cout<<"sex: "<<t.sex<<endl;
        output<<"star: "<<t.star<<endl;
        return output;
    }
};
class Player:protected Person{
public:
    string nic;
    Trainer trainer;
    vector<Player*> friends;
    void setNic(){
        cout<<"nic name: ";cin>>nic;
    }
    void setTrainer(const Trainer& t){
        trainer=t;
    }
    void setFriends(const Player& p){
        friends.push_back(&p);
    }
    friend ostream& operator<<(ostream& output,const Player& p){
        output<<"name: "<<p.name<<endl;
        output<<"age: "<<p.age<<endl;
        output<<"sex: "<<p.sex<<endl;
        output<<"nic name: "<<p.nic<<endl;
        return output;
    }
    void getTrainer(){
        cout<<"trainer information: \n"<<trainer;
    }
};


class team{
public:
    string name;
    string place;
    Person coach;
    vector<Player*> players;
    friend istream& operator>>(istream& input,team& t){
        cout<<"team name: ";input>>t.name;
        cout<<"place: ";input>>t.place;
        return input;
    }
    void getCoach(const Person& p){
        coach=p;
    }
    void getPlayer(const Player& p){
        players.push_back(&p);
    }
};
int main(){
    //int i=99;string s="qq";
    //cin>>i;debug(i);i=100;
    //cin>>i;debug(i);i=110;
    //cin>>s;debug(s);
    stringstream ss{"abc 12 male"};
    Player p1;
    Person p;
    //cin>>p;
    ss>>p;
    cout<<p;
    if(p){cout<<"p is true\n";}
    bool bb;
    //bb=p;
    Person p2{"bcd",11,female};
    cout<<p2;
    Person *x=&p2;
    cout<<"x="<<x<<endl;
    cout<<"*x="<<*x;
    using pointer=Person*;
    vector<pointer> friends={&p,&p2};
    for(auto& x:friends)
        x->age++;
    for(auto& x:friends)
        cout<<(*x);
}