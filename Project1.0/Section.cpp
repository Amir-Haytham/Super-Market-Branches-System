#include <bits/stdc++.h>
#include "Section.h"


using namespace std ;

int getDigitsSection(int n){
        int nos = 0 ;
        while(n){
            n /= 10 ;
            nos++;
        }
        return nos ;
};
bool Section::SearchToCheckValidSection(string tmp){
      Section ob_section ;
      fstream f ;
      f.open( "SectionTable.txt" , ios::in ) ;
      while( !f.eof() ){
            f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
            if ( tmp == ob_section.sec_id ){
                return 1 ;
            }
    }
    f.close();
    return 0 ;
}
void Section::input(){
    fstream f;
	char choice;
    Section ob_section ;

	f.open( "SectionTable.txt" , ios::app ) ;
	bool flag = 1 ;
	if ( ob_section.file_length() == 0 ){
        while ( 1 ){
            cout << "Enter sec_id, SEC_NAME and MGR_SEC : " << "\n" ;
            cin >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
            if( Section::SearchToCheckValidSection(ob_section.sec_id) ){
                 cout << "\n\t<< Sorry , this id has the same name for the one we have >>\n\n";
                 cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
                 if ( choice == 'n' || choice == 'N' )break;
                 else continue;
            }
            f << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
            cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
            if ( choice == 'n' || choice == 'N' )break;
        }
	}
	else {
        cout << "Enter sec_id, SEC_NAME and MGR_SEC : " << "\n" ;
        cin >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        f << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
	}
	f.close();
}

void Section::print(){
    Section ob_section ;
    fstream f ;
    f.open( "SectionTable.txt" , ios::in ) ;
    cout << "\nsec_id"+string(2 ,' ')<<"SEC_NAME"<<string(23,' ')<< "MGR_SEC"<<"\n";
	cout << "------- "<<"------------------------------ " <<"----------\n";

	string id = "" ;
	while( !f.eof() ){
       f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
      //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
       if (id != ob_section.sec_id){
       cout << static_cast<string>(ob_section.sec_id)<<string(8-(int)ob_section.sec_id.size() ,' ')
            << static_cast<string>(ob_section.SEC_NAME)<<string(31-(int)ob_section.SEC_NAME.size() ,' ')
            << ob_section.MGR_SEC<<"\n";
       id = ob_section.sec_id ;
      }
 	}
 	f.close();
}

void Section::search_ (){
    Section ob_section ;
    if ( !Section::file_length () ){ ///if file is empty
        cout << "The file is empty no data so far\n\n";
        return ;
    }
    else{
      cout << "\nEnter sec_id to search on : " ; string tmp ; cin >> tmp ;
      cout << "The data of the required record is : \n\n" ;
      cout << "sec_id"+string(2 ,' ')<<"SEC_NAME"<<string(23,' ')<< "MGR_SEC"<<"\n";
	  cout << "------- "<<"------------------------------ " <<"----------\n";

      fstream f ;
      f.open( "SectionTable.txt" , ios::in ) ;
            while( !f.eof() ){
            f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
            if ( tmp ==  ob_section.sec_id ){
                cout << ob_section.sec_id<<string(8-(int)ob_section.sec_id.size() ,' ')
                << ob_section.SEC_NAME<<string(10-(int)ob_section.SEC_NAME.size() ,' ')
                << ob_section.MGR_SEC<<"\n";
                break;
            }
        }
        f.close();
    }
}

int Section::file_length (){
    Section ob_section ;
    fstream f ;
    f.open( "SectionTable.txt" , ios::in ) ;
	int cnt = 0 ;
	while( !f.eof() ){
        f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        cnt++;
	}
	return --cnt ;
	f.close();
}

void Section::update (){
    Section ob_section ;

    /// if the file is empty
    if ( Section::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to update its record : ";string s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Section::SearchToCheckValidSection(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }
    fstream f , tmp ;
	f.open( "SectionTable.txt" , ios::in ) ;
	tmp.open( "TmpSectionTable.txt" , ios::out ) ;
	while( !f.eof() ){
        f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        if ( s == ob_section.sec_id ){
          cout << "Enter the updated sec_id  :";cin>>ob_section .sec_id;
          cout << "Enter the updated SEC_NAME:";cin>>ob_section .SEC_NAME;
          cout << "Enter the updated MGR_SEC :";cin>>ob_section .MGR_SEC;
          tmp << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;

          continue;
        }
        tmp<< ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
	}
	f.close();tmp.close();
    f.open( "SectionTable.txt" , ios::out ) ;
	tmp.open( "TmpSectionTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        f << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Updated Done >>> ======\n\n\n";

}


void Section::Delete(){

      Section ob_section ;

    /// if the file is empty

    if ( Section::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to delete its record : ";string s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Section::SearchToCheckValidSection(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }

    fstream f , tmp ;
	f.open( "SectionTable.txt" , ios::in ) ;
	tmp.open( "TmpSectionTable.txt" , ios::out ) ;

	while( !f.eof() ){
       f >> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        if ( s == ob_section.sec_id ){
          continue;
        }
        tmp << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
	}
	f.close();tmp.close();
    f.open( "SectionTable.txt" , ios::out ) ;
	tmp.open( "TmpSectionTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp>> ob_section.sec_id >> ob_section.SEC_NAME >> ob_section.MGR_SEC;
        f << ob_section.sec_id << " " << ob_section.SEC_NAME << " " << ob_section.MGR_SEC << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Deleted Done >>> ======\n\n\n";

}

