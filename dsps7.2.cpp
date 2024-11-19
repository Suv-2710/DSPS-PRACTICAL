#include<iostream>
using namespace std;
int n,i,r=-1,f=-1,price;
class pizza{
    int q,cost;
    string name,add;
    public:
    void accept_order();
    void serve_order();
    void display_order();
    void current_order();
    
}p[100];

void pizza::accept_order()
{
    if((f==0 && r==n-1)||f==r+1)
    {
        cout<<"\nAll orders are booked:";
    }
    else if(f==-1 && r==-1)
    {
        f=0,r=0;
        cout<<"\nCongratulation!!!";
        cout<<"\nThis is our todays first order";
        cout<<"\n-you win Rs.20 discount-";
        cout<<"\nEnter name,address and quantity:";
        cin>>p[r].name>>p[r].add>>p[r].q;
        cost=(p[r].q*price)-20;
        cout<<"\n!..Bill..!";
        cout<<"\n"<<p[r].q<<"*"<<price<<"-"<<"20"<<"="<<"Rs."<<cost;
    }
    else{
        r=(r+1)%n;
        cout<<"\nEnter name,address and quantity:";
        cin>>p[r].name>>p[r].add>>p[r].q;
        cost=(p[r].q*price);
        cout<<"\n!..Bill..!";
        cout<<"\n"<<p[r].q<<"*"<<price<<"="<<"Rs."<<cost;
    }
}

void pizza::serve_order()
{
   if(f==-1 && r==-1)
   {
       cout<<"\n...Any order is not recived yet...";
   }
   else if(f==r)
   {   cout<<"\n--last order--";
       cout<<"\n--order to be serve is--";
       cout<<"\n"<<"name-"<<p[f].name<<"\t"<<"address-"<<p[f].add<<"\t"<<"quantity-"<<p[f].q;
       cost=(p[f].q*price);
       cout<<"\n!..Bill..!";
       cout<<"\n"<<p[f].q<<"*"<<price<<"="<<"Rs."<<cost;
       f=-1,r=-1;
   }
   else{
       cout<<"\n--order to be serve is--";
       cout<<"\n"<<"name-"<<p[f].name<<"\t"<<"address-"<<p[f].add<<"\t"<<"quantity-"<<p[f].q;
       cost=(p[f].q*price);
       cout<<"\n!..Bill..!";
       cout<<"\n"<<p[f].q<<"*"<<price<<"="<<"Rs."<<cost;
       f=(f+1)%n;
   }
}


void pizza::display_order()
{
    cout<<"\n--remaining orders--";
    if(f==r)
    {
        cout<<"\n"<<"name-"<<p[f].name<<"\t"<<"address-"<<p[f].add<<"\t"<<"quantity-"<<p[f].q;
    }
    else{
        i=f;
        while(i!=r)
        {
          cout<<"\n"<<"name-"<<p[f].name<<"\t"<<"address-"<<p[f].add<<"\t"<<"quantity-"<<p[f].q;
           i=(i+1)%n;
        }
    }
}


void pizza::current_order()
{
    if(f==-1 && r==-1)
    {
        cout<<"\n--Order is not recived yet--";
    }
    else{
        cout<<"\n"<<"name-"<<p[f].name<<"\t"<<"address-"<<p[f].add<<"\t"<<"quantity-"<<p[f].q;
        cost=(p[f].q*price);
        cout<<"\n!..Bill..!";
        cout<<"\n"<<p[f].q<<"*"<<price<<"="<<"Rs."<<cost;
    }
}



int main()
{   int ch;
    cout<<"enter total no. of orders:";
    cin>>n;
    cout<<"\nEnter price of each pizza==";
    cin>>price;
    do{
    cout<<"\n1.Accept Order\n2.Serve Order\n3.Display Order\n4.Current Order\n";
    cout<<"\nEnter Ur Choice:\n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        p[i].accept_order();
        break;
        
        case 2:
        p[i].serve_order();
        break;
        
        case 3:
        p[i].display_order();
        break;
        
        case 4:
        p[i].current_order();
        break;
    }
    }while(ch!=0);
    return 0;
}