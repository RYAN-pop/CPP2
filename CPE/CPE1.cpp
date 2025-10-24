#include<iostream>
#include<cmath>
using namespace std;

void inputArray(int array[],int size)
{
    for(int i=0;i<size;i++)
        cin>>array[i];
}
int minDis(int array[],int size)
{
    int sum=0,n=0,ans=array[0],number=0;
    for(int j=0;j<size;j++)
        number=number+abs(array[0]-array[j]);
    for(int i=array[0];i<=array[size-1];i++){
        for(int j=0;j<size;j++)
            sum=sum+abs(i-array[j]);
        if(sum<number){
             number=sum;sum=0;ans=i;
        }
        else
            sum=0; 
    }
    return ans;
}
int main()

{
    int r,num;
    cout<<"the number of test cases:";
    cin>>r;
     
    
        for(int i=0;i<r;i++){
            //cout<<"\r"<<" ";
            cout<<"how many people:\n";
            cin>>num;
            cout<<"and their distances\n";
            int arr[500-1];
            inputArray(arr,num);
            int ans=minDis(arr,num);
            cout<<ans<<endl;
        }
    


return 0;
}