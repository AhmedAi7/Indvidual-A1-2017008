#include <iostream>
#include <cstdlib>
#include <cstddef>
using namespace std;
void addEntry(string *&dynamicArray, int SIZE, string newEntry);
void deleteEntry(string *&dynamicArray, int SIZE, string entryToDelete);
int main()
{
    cout << "Enter Array Size: ";
    int SIZE ;
    cin>> SIZE;
    string *dynamicArray;
    dynamicArray= new string [SIZE] ;
    cout<<"Enter the array: ";
    for (int i=0 ; i<SIZE ; i++)
    {
        cin>> dynamicArray[i] ;
    }
    cout << endl << "1) increase size" <<endl << "2) decrease size"<<endl;
    int choice;
    cin>> choice ;
    if (choice ==1)
    {
        cout <<"Enter the new string: ";
        string newEntry ;
        cin >> newEntry ;
        addEntry(dynamicArray,SIZE,newEntry);
    }
    else if (choice==2)
    {
        cout <<"Enter string to delete: ";
        string entryToDelete;
        cin>> entryToDelete ;
        deleteEntry(dynamicArray,SIZE, entryToDelete);
    }
    for (int i=0 ; i<SIZE+1 ; i++)
    {
        cout<< dynamicArray[i]<<" " ;
    }
    return 0;
}
//____________________________________________________________________
void addEntry(string *&dynamicArray, int SIZE, string newEntry)
{
    string *n;
    n= new string [SIZE+1];
    for (int i=0 ; i<SIZE ; i++)
    {
        n[i]=dynamicArray[i];
    }
    n[SIZE] = newEntry;
    delete[] dynamicArray;
    dynamicArray = n;
}
//____________________________________________________________________
void deleteEntry(string *&dynamicArray, int SIZE, string entryToDelete)
{
    int p=-1 ; //place of entrytoDelete
    for (int i =0; i<SIZE; i++)
    {
        if (dynamicArray[i] == entryToDelete)
        {
            p=i;    //if p still negative value then the request should be ignored
            break;
        }
    }
    if (p==-1)
        cout <<"Not found.." << endl;
    else
    {
        int counter = 0;
        string *n;
        n= new string [SIZE-1];
        for (int i=0 ; i<SIZE-1 ; i++)
        {   for (int j =counter ; j<SIZE ; j++ )
                {if (j!=p)
                    {
                        n[i]=dynamicArray[j];
                        counter = counter+1;
                        break;
                    }
        }
        }
        delete[] dynamicArray;
        dynamicArray = n;
    }
}
//_____________________________________________________________________

