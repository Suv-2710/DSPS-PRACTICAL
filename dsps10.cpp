#include<iostream>
using namespace std;

class MLS
{
int TN;
string name, artist ;
MLS *next, *prev;

public:
      void create();
      void display();
      void dispcount();
      void search();
      void modify();
      void remove();
}*start=NULL, *END=NULL;

void MLS::create()
{
MLS *nnode, *temp;
nnode=new MLS;
cout<<"Enter the track number , name and artist of song:";
cin >> nnode->TN >> nnode->name >> nnode->artist;
nnode->prev = nnode->next= NULL;
if(start==NULL)
{
start=nnode;
END=nnode;
}
else
{
temp=start;
while(temp->next!=NULL)
{
temp=temp->next;
}
}
temp->next=nnode;
nnode->prev=temp;
END=nnode;
}


void MLS::display() //displaying forward
{
int cnt=0;
MLS *temp;

temp=start;
while(temp!=NULL)
{
cnt++;
cout<<"\n"<< temp->TN <<"\t"<< temp->name <<"\t"<< temp->artist;
temp=temp->next;
}
 cout << "\nThe count is: " << cnt ;
} 

/*
void MLS::display() //displaying backward
{
int cnt=0;
MLS *temp;

temp=end;
while(temp!=NULL)
{
cnt++;
cout<<"\n"<< temp->TN <<"\t"<< temp->name <<"\t"<< temp->artist;
temp=temp->prev;
}
} */

void MLS::search()
{
    string nn;
    int f = 0;
    cout << "Enter music name you want to search: ";
    cin >> nn;
    MLS *temp = start;
    while (temp != NULL)
    {
        if (temp->name == nn)
        {
            cout << "\n" << temp->TN << "\t" << temp->name << "\t" << temp->artist ;
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Music not found" ;
    }
}

void MLS::modify()
{
    MLS *temp;
    int f = 0;
    string nn;
    cout << "Enter music name you want to modify: ";
    cin >> nn;
    temp = start;
    while (temp != NULL)
    {
        if (temp->name == nn)
        {
            f = 1;
            cout << "Enter new details (TN, name, artist): ";
            cin >> temp->TN >> temp->name >> temp->artist;
            cout << "Details updated." ;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Music not found" ;
    }
}

void MLS::remove()
{
    MLS *p, *q;
    string nn;
    int f = 0;
    cout << "Enter music name to remove: ";
    cin >> nn;
    MLS *temp = start;
    if (temp != NULL && temp->name == nn) 
    {
        p = temp;
        start = temp->next;
        delete p;
        cout << "Music removed." ;
        return;
    }
    while (temp != NULL)
    {
        if (temp->name == nn)
        {
            f = 1;
            p = temp;
            q->next = temp->next;
            delete p;
            cout << "Music removed." ;
            break;
        }
        q = temp;
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Music not found" ;
    }
}

void MLS::dispcount()
{
    int count = 0;
    MLS *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Total number of Music: " << count ;
}

int main()
{
    MLS m;
    int ch;

    do
    {
        cout<<"\nMusic Library System";
        cout << "\nMenu: ";
        cout << "\n1.Create\n2. Display\n3. Search\n4. Modify\n5. Remove\n6. Display Count\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            m.create();
            break;
        case 2:
            cout << "\nTN\tNamer\tArtist" ;
            m.display();
            break;
        case 3:
            m.search();
            break;
        case 4:
            m.modify();
            break;
        case 5:
            m.remove();
            break;
        case 6:
            m.dispcount();
            break;
        case 0:
            cout << "Exiting program." ;
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    } while (ch != 0);

    return 0;
}