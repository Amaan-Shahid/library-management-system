#include<iostream>
#include<string>

using namespace std;

struct books{
int id;
char name[100];
char author[100];
};

books library[100];
int bookcount=0;

int findBookIndexById(int id){
    for(int i=0;i<bookcount;i++){
        if(library[i].id==id){
            return i;
        }
    }
    return -1;
}


void addBooks(){

    if(bookcount>100){
        cout<<"Space Overflow!"<<endl;
        return;
    }

    cout << "Enter book ID: ";
    cin >> library[bookcount].id;
    cin.ignore(); // Ignore newline
    cout << "Enter book name: ";
    cin.getline(library[bookcount].name, 100);
    cout << "Enter author name: ";
    cin.getline(library[bookcount].author, 100);
    bookcount++;
    cout<<"Book added Successfully!"<<endl;
}

void deleteBooks(){
    cout<<"Enter Book ID to delete"<<endl;
    int id;
    cin>>id;
    int index=findBookIndexById(id);
    if(index!=-1){
        for(int i=index;i<bookcount-1;i++){
            library[i]=library[i+1];
        }
        --bookcount;
        cout<<"Book Deleted Successfully!"<<endl;
    }
    else{
        cout<<"Book not Found!"<<endl;
    }
}

void searchBooks(){
int id;
cout<<"Enter Book ID"<<endl;
cin>>id;
int index=findBookIndexById(id);
if(index!=-1){
    cout<<"Book Found!"<<endl;
    cout<<"Book ID : "<<library[index].id<<endl;
    cout<<"Book Name : "<<library[index].name<<endl;
    cout<<"Author Name : "<<library[index].author<<endl;
}
}

void displayBooks(){
 if (bookcount == 0) {
        cout << "No books in the library."<<endl;;
        return;
    }

    for (int i = 0; i < bookcount; i++) {
        cout << "ID: " << library[i].id 
             << "\nName: " << library[i].name
             << "\nAuthor: " << library[i].author << endl;
    }
}



                    
int main(){
while(true){
int option;
cout<<"1. Add Books"<<endl;   
cout<<"2. Search Books"<<endl; 
cout<<"3. Delete Books"<<endl;  
cout<<"4. Display all Books"<<endl;   
cout<<"5. Exit the Program"<<endl;
cout<<"Enter 1-5"<<endl;
cin>>option;
switch(option){
    case 1:
    addBooks();
    break;
    case 2:
    searchBooks();
    break;
    case 3:
    deleteBooks();
    break;
    case 4:
    displayBooks();
    break;
    case 5:
    cout<<"Exiting..."<<endl;
    return 0;
    break;
    default:
    cout<<"Invalid Input!"<<endl;
}
}      
return 0;
}