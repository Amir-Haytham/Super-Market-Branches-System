#include <bits/stdc++.h>
#include <iostream>
#include "Branch.h"
#include "Employee.h"
#include "Job.h"
#include "Section.h"
#include "Contain.h"

using namespace std ;

void display(){
   	cout<<"==========================--> Semester Project <--============================\n";
    cout<<"\t    | The program so far , discuss the following : |\n\t    |  \t ====================================\t   |\n"
    << "\t    | 1) Insert\t\t\t\t\t   | \n\t    | 2) Search\t\t\t\t\t   |  \n\t    | 3) Display\t\t\t\t   |  \n\t    | 4) Update\t\t\t\t\t   |  \n\t    | 5) Delete\t\t\t\t\t   |  \n\t    | 6) Size of file \t\t\t\t   |  \n "<<endl;
    cout << "For any object inserted , its data will be saved and for any retrieval command it will be got"
    " . Also, if you want to update or delete , it will be found ."<<"\n\n" ;
    cout<<"********************************************************************************"<<endl;
}

void PlayInsert(){
    cout << "Choose one of the tables you want insert in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";
    int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        _emp .input();
    }
    else if ( _ == 2){
         Job _job ;
        _job.input();
    }
    else if ( _ == 3){
        Branch _brch;
        _brch.input();
    }
    else if ( _ == 4){
        Section _Sec;
        _Sec.input();
    }
    else{
        Contain _con ;
        _con .input();
    }

}

void PlaySearch(){
    cout << "Choose one of the tables you want search in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        _emp.search_();
    }
    else if ( _ == 2){
         Job _job ;
        _job.search_();
    }
    else if ( _ == 3){
        Branch b;
        b.search__();
    }
    else if ( _ == 4){
        Section _Sec;
        _Sec.search_();
    }
    else{
        Contain _con ;
        _con.search_();
    }
}

void PlayDisplay(){
    cout << "Choose one of the tables you want display in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        _emp .print();
    }
    else if ( _ == 2){
         Job _job ;
        _job.print();
    }
    else if ( _ == 3){
        Branch _brch;
        _brch.print();
    }
    else if ( _ == 4){
        Section _Sec;
        _Sec.print();
    }
    else{
        Contain _con ;
        _con .print();
    }
}
void PlayUpdate(){
    cout << "Choose one of the tables you want update in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        _emp.update();
    }
    else if ( _ == 2){
         Job _job ;
        _job.update();
    }
    else if ( _ == 3){
        Branch _brch;
        _brch.update();
    }
    else if ( _ == 4){
        Section _Sec;
        _Sec.update();
    }
    else{
        Contain _con ;
        _con.update();
    }
}
void PlayDelete(){
    cout << "Choose one of the tables you want delete in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        _emp.Delete();
    }
    else if ( _ == 2){
         Job _job ;
        _job.Delete();
    }
    else if ( _ == 3){
        Branch _brch;
        _brch.Delete();
    }
    else if ( _ == 4){
        Section _Sec;
        _Sec.Delete();
    }
    else{
        Contain _con ;
        _con.Delete();
    }
}
void PlaySize(){
    cout << "Choose one of the tables you want to get length of the file in : \n\n";
    cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
    << "1) Emloyee\n2) Job\n3) Branch\n4) Section\n5) Contain\n  "<<endl;
    cout<<"Select your choice from [1 .. 5] : ";int _ ;cin >> _ ;
    if ( _ == 1 ){
         Employee _emp ;
        cout << "The length of the Employee Table is : " << _emp.file_length() << "\n";
    }
    else if ( _ == 2){
        Job _job ;
       cout << "The length of the Job Table is : " << _job.file_length() << "\n";
    }
    else if ( _ == 3){
        Branch _brch;
       cout << "The length of the Branch Table is : " << _brch.file_length() << "\n" ;
    }
    else if ( _ == 4){
       Section _Sec;
       cout << "The length of the Section Table is : " << _Sec.file_length() << "\n" ;
    }
    else{
        Contain _con ;
       cout << "The length of the Contain Table is : " << _con.file_length() << "\n" ;
    }
}

int main(){
    display();
    bool flag1=true;
    display() ;
    while (flag1){
		bool flag2=true;
        cout<<"\t    | \t     Choose any command to start : \t   |\n\t    |  \t ====================================\t   |\n"
		<< "\t    | 1) Insert\t\t\t\t\t   | \n\t    | 2) Search\t\t\t\t\t   |  \n\t    | 3) Display\t\t\t\t   |  \n\t    | 4) Update\t\t\t\t\t   |  \n\t    | 5) Delete\t\t\t\t\t   |  \n\t    | 6) Size of file \t\t\t\t   |  \n  "<<endl;
		cout<<"Select your choice from [1 .. 6] : ";
        int c;
        cin>>c;
        switch (c)
        {
        case 1 :
		cout<<"********************************************************************************"<<endl;
            PlayInsert();
            break;
        case 2:
		cout<<"********************************************************************************"<<endl;
            PlaySearch();
            break;
        case 3:
		cout<<"********************************************************************************"<<endl;
            PlayDisplay();
            break;
        case 4 :
		cout<<"********************************************************************************"<<endl;
            PlayUpdate();
            break;
        case 5 :
		cout<<"********************************************************************************"<<endl;
            PlayDelete();
            break;
        case 6 :
        cout<<"********************************************************************************"<<endl;
            PlaySize();
            break ;
        default :
            cout << " \n\n================================--> Warning <--=================================\n"  ;
            cout << "  \t\t\t   Select The Right choice \n";
        }
        while(flag2){
            cout<<"********************************************************************************" <<endl;
        	cout<<"\nDo you want to Continue [Y/N] : \n";
	        char ch ; cin >> ch ;
	        if( ch == 'n' || ch == 'N' )flag1 = false , flag2 = false;
	        else if( ch == 'y' || ch =='Y' )flag2 = false ;
	        else{
            cout<<"********************************************************************************" <<endl;
			}
	    }
        cout<<"********************************************************************************" << endl ;
    }
}
