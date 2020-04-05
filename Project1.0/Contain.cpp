#include <bits/stdc++.h>
#include "Contain.h"

using namespace std ;

void Contain::input(){
    fstream f;
	char choice;
    Contain ob_Contain ;
	f.open( "ContainTable.txt" , ios::app ) ;
    while ( 1 ){
            cout << "Enter branch_id and sec_id : " << "\n" ;
            cin >> ob_Contain.branch_id >> ob_Contain.sec_id ;
            f << ob_Contain.branch_id << " " << ob_Contain.sec_id << "\n" ;
            cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
            if ( choice == 'n' || choice == 'N' )break;
    }

	f.close();
}

void Contain::print(){
    Contain ob_Contain ;
    fstream f ;
    int len = ob_Contain.file_length();
    f.open( "ContainTable.txt" , ios::in ) ;
    cout << "\nbranch_id"+string(2 ,' ')<<"SEC"<<"\n";
	cout << "---------- "<<"---\n";
	string id = "" ;
	while( !f.eof() && len-- ){
       f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
       cout << static_cast<string>(ob_Contain.branch_id)<<string(11-(int)ob_Contain.branch_id.size() ,' ')
            << static_cast<string>(ob_Contain.sec_id)<<"\n";
 	}
 	f.close();
}
void Contain::search_ (){
    if ( !Contain::file_length () ){ ///if file is empty
        cout << "The file is empty no data so far\n\n";
        return ;
    }
    else{
      cout << "\nEnter branch_id to search on : " ; string tmp ; cin >> tmp ;
      cout << "The data of the required record is : \n\n" ;
      cout << "\nbranch_id"+string(2 ,' ')<<"SEC_ID"<<"\n";
      cout << "---------- "<<"---\n";
      Contain ob_Contain ;
      fstream f ;
      f.open( "ContainTable.txt" , ios::in ) ;
      while( !f.eof() ){
        f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
        if ( tmp ==  ob_Contain.branch_id ){
        cout << static_cast<string>(ob_Contain.branch_id)<<string(11-(int)ob_Contain.branch_id.size() ,' ')
            << static_cast<string>(ob_Contain.sec_id)<<"\n";
                break;
           }
        }
         f.close();
     }
}

int Contain::file_length (){
    Contain ob_Contain;
    fstream f ;
    f.open( "ContainTable.txt" , ios::in ) ;
	int cnt = 0 ;
	while( !f.eof() ){
        f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
        cnt++;
	}
	return --cnt ;
	f.close();
}

bool Contain::SearchToCheckValidContain(string tmp1 , string tmp2){
      Contain ob_Contain ;
      fstream f ;
      bool ok1 = 0 ;
      f.open( "ContainTable.txt" , ios::in ) ;
      while( !f.eof() ){
            f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
            if ( tmp1 == ob_Contain.branch_id && tmp2 == ob_Contain.sec_id ){
                return 1 ;
            }
      }
      f.close();
      return 0 ;
}


void Contain::update (){
    Contain ob_Contain ;

    /// if the file is empty
    if ( Contain::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the branch_id and sec_id you want to delete its record : ";
    string s1 , s2 ;cin>>s1>>s2;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Contain::SearchToCheckValidContain(s1,s2) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }
    fstream f , tmp ;
	f.open( "ContainTable.txt" , ios::in ) ;
	tmp.open( "TmpContainTable.txt" , ios::out ) ;
	while( !f.eof() ){
        f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
        if ( s1 == ob_Contain.branch_id && s2 == ob_Contain.sec_id ){
          cout << "Enter the updated branch_id :";cin>>ob_Contain.branch_id;
          cout << "Enter the updated sec_id    :";cin>>ob_Contain.sec_id;
          tmp << ob_Contain.branch_id << " " << ob_Contain.sec_id << "\n" ;
          continue;
        }
        tmp<< ob_Contain.branch_id << " " << ob_Contain.sec_id<<"\n" ;
	}
	f.close();tmp.close();
    f.open( "ContainTable.txt" , ios::out ) ;
	tmp.open( "TmpContainTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp >> ob_Contain.branch_id >> ob_Contain.sec_id ;
        f << ob_Contain.branch_id << " " << ob_Contain.sec_id << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Updated Done >>> ======\n\n\n";

}


void Contain::Delete(){

       Contain ob_Contain;

    /// if the file is empty

    if ( Contain::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the branch_id and sec_id you want to delete its record : ";
    string s1 , s2 ;cin>>s1>>s2;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Contain::SearchToCheckValidContain(s1,s2) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }

    fstream f , tmp ;
	f.open( "ContainTable.txt" , ios::in ) ;
	tmp.open( "TmpContainTable.txt" , ios::out ) ;

	while( !f.eof() ){
       f >> ob_Contain.branch_id >> ob_Contain.sec_id ;
        if ( s1 == ob_Contain.branch_id && s2 == ob_Contain.sec_id ){
          continue;
        }
        tmp << ob_Contain.branch_id << " " << ob_Contain.sec_id << "\n" ;
	}
	f.close();tmp.close();
    f.open( "ContainTable.txt" , ios::out ) ;
	tmp.open( "TmpContainTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp>> ob_Contain.branch_id >> ob_Contain.sec_id ;
        f << ob_Contain.branch_id << " " << ob_Contain.sec_id << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Deleted Done >>> ======\n\n\n";
}
