#include <iostream>
using namespace std;

class CMS
{
    int amt;
    string name, address;
    CMS *next;
public:
    void accept();
    void display();
    void search();
    void modify();
    void remove();
    void dispcount();
} *start = NULL;

void CMS::accept()
{
    CMS *nnode, *temp;
    nnode = new CMS;
    cout << "Enter donor details (name, address, amount): ";
    cin >> nnode->name >> nnode->address >> nnode->amt;
    nnode->next = NULL;

    if (start == NULL)
    {
        start = nnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nnode;
    }
}

void CMS::display()
{
    int cnt = 0;
    CMS *temp;
    temp = start;
    if (temp == NULL)
    {
        cout <<"\nList is empty" ;
    }
    else
    {
        while (temp != NULL)
        {
            cnt++;
            cout << "\n" << temp->name << "\t" << temp->address << "\t" << temp->amt;
            temp = temp->next;
        }
    }
    cout << "\nThe count is: " << cnt ;
}

void CMS::search()
{
    string nn;
    int f = 0;
    cout << "Enter donor name you want to search: ";
    cin >> nn;
    CMS *temp = start;
    while (temp != NULL)
    {
        if (temp->name == nn)
        {
            cout << "\n" << temp->name << "\t" << temp->address << "\t" << temp->amt ;
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Donor not found" ;
    }
}

void CMS::modify()
{
    CMS *temp;
    int f = 0;
    string nn;
    cout << "Enter donor name you want to modify: ";
    cin >> nn;
    temp = start;
    while (temp != NULL)
    {
        if (temp->name == nn)
        {
            f = 1;
            cout << "Enter new details (name, address, amount): ";
            cin >> temp->name >> temp->address >> temp->amt;
            cout << "Details updated." ;
            break;
        }
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Donor not found" ;
    }
}

void CMS::remove()
{
    CMS *p, *q;
    string nn;
    int f = 0;
    cout << "Enter donor name to remove: ";
    cin >> nn;
    CMS *temp = start;
    if (temp != NULL && temp->name == nn) 
    {
        p = temp;
        start = temp->next;
        delete p;
        cout << "Donor removed." ;
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
            cout << "Donor removed." ;
            break;
        }
        q = temp;
        temp = temp->next;
    }
    if (f == 0)
    {
        cout << "Donor not found" ;
    }
}

void CMS::dispcount()
{
    int count = 0;
    CMS *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    cout << "Total number of donors: " << count ;
}

int main()
{
    CMS s;
    int ch;

    do
    {
        cout<<"\nCharity Management System";
        cout << "\nMenu: ";
        cout << "\n1. Accept\n2. Display\n3. Search\n4. Modify\n5. Remove\n6. Display Count\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s.accept();
            break;
        case 2:
            cout << "\nName\tAddress\tAmount" ;
            s.display();
            break;
        case 3:
            s.search();
            break;
        case 4:
            s.modify();
            break;
        case 5:
            s.remove();
            break;
        case 6:
            s.dispcount();
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