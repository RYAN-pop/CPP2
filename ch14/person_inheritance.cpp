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
    if (sex == male)        cout << "male";
    else if(sex == female)  cout << "female";
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
    using PlayerPtr=const Player* ;    
    string nic;
    Trainer trainer;
    vector<const Player*> friends;
    set<PlayerPtr> all={};
    
    void allFriends(PlayerPtr p);
    void print();
    void setNic(){
        cout<<"nic name: ";cin>>nic;
    }
    void setTrainer(const Trainer& t){
        trainer=t;
    }
    Player& addFriend(const Player& p){
        friends.push_back(&p);
        return *this;
    }
    friend istream& operator>>(istream& input,Player& p);
    friend ostream& operator<<(ostream& output,const Player& p);
    void getTrainer(){
        cout<<"trainer information: \n"<<trainer;
    }
};
istream &operator>>(istream &input, Player &p)
{
    /*cout << "enter Person name: ";
    input >> p.name;
    cout << "enetr Person age: ";
    input >> p.age;
    cout << "enetr Person sex: ";
    input >> p.sex;*/
    Person &person=p;
    input>>person;
    cout << "nic name: ";
    input >> p.nic;
    return input;
}
ostream &operator<<(ostream &output, const Player &p)
{
    const Person &person=p;
    output<<person;
    output << "nic name: " << p.nic << endl;
    for(const auto &x : p.friends)
        output<<"Friends:"<<(*x).name<<" \n";
    output<<endl;
    return output;
}
void Player::allFriends(PlayerPtr p){
    int x=0; 
    for(int j=0;j < p->friends.size();j++){
        for(const auto &k : all){
            if(p->friends[j]==k) x++;
        }
    } 
    if(x==p->friends.size()) return;    
    for(int i=0;i<p->friends.size();i++){ 
            all.insert(p->friends[i]);
            allFriends(p->friends[i]);
        }
          
    }
void Player::print(){
    cout<<"--------\n";
    for(const auto &i : all)
        cout<<*i<<" ";
    cout<<endl;
}
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
    void getPlayer(Player& p){
        players.push_back(&p);
    }
};
void testFriend(){
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
int main(){
    //testFriend();
    Player p1,p2,p3,p4;
    stringstream ss{"curry 38 male chef lebron 40 male king lrving 33 male unc p4 33 female f"};
    ss>>p1>>p2>>p3>>p4;
    p1.addFriend(p2).addFriend(p3);
    p3.addFriend(p2).addFriend(p4);
    cout<<p1<<p2<<p3;
    p1.allFriends(&p1);
    p1.print();
    p3.allFriends(&p3);p3.print();
}