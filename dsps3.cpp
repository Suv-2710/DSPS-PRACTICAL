#include<iostream>
#include<string.h>
using namespace std;
int n,i,j,flag=0;
class student
{
    int roll_no;
    string name,add;
    public:
    void accept();
    void display();
    void Lsearch();
    void Bsearch();
}s[100];

void student::accept()
{   
  
    cout<<"enter how many student record you want to accept";
    cin>>n;
    cout<<"Enter your roll no,name and address";
    for(i=0;i<n;i++)
    {
    cin>>s[i].roll_no>>s[i].name>>s[i].add;
    }

}


void student::display()
{   
    
    cout<<"\n"<<"roll no"<<"\t"<<"name "<<"\t"<<"address";
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<s[i].roll_no<<"\t"<<s[i].name<<"\t"<<s[i].add;
        
    }

}

void student::Lsearch()
{   
    int rno;
    cout<<"enter roll no you want to search:";
    cin>>rno;

    for(i=0;i<n;i++)
    {
        if(s[i].roll_no==rno)
        {
            flag=1;
            cout<<rno<< "roll no attended training program";
        }
    }
    if(flag=0)
    {
        cout<< "roll no not  attended training program";
    }
}

void student::Bsearch()
{
    int rno;
    student temp;
   
    for(i=0;i<n;i++)
    {
    for(j=i+1;j<n;j++)
    {
    if(s[i].roll_no>s[j].roll_no)
    {
    temp=s[i];
    s[i]=s[j];
    s[j]=temp;
    }
    }
    }
    cout<<"enter roll no you want to search:";
    cin>>rno;
    int low=0,high=n-1,mid;

    while(low<=high)
    {
        mid=(high+low)/2;

        if(s[mid].roll_no==rno)
        {
            cout<<rno<< "roll no attended training program";
            break;
        }

        else if(s[mid].roll_no<rno)
        {
            low=mid+1;
        }

        else
        {
            high-mid-1;
        }

    }

        if(low>high)
        {
             cout<< "roll no not  attended training program";
        }

}

int main()
{
int choice,ch;
do{
cout<<"1.accept 2.display 3.Lsearch 4.Bsearch ";
cout<<"\nEnter operation to be performed:";
cin>>choice;

switch(choice)
{
case 1:s[i].accept();
       break;
case 2:s[i].display();
       break;
case 3:s[i].Lsearch();
       break;
case 4:s[i].Bsearch();
       break;
}
cout<<"\nDo you want to continue(0/1)";
cin>>ch;
}
while(ch==1);
return 0;
}