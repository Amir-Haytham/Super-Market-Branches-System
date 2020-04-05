#ifndef Branch_H_
#define Branch_H_

#include <bits/stdc++.h>
using namespace std ;

class Branch{
    public:
    int branch_id ;
    string branch_address ;
    string phone_no ;
    string city_name ;
    int mgr_branch ;
    bool SearchToCheckValidBranch(int);
    void input ();
    void print ();
    void search__();
    int  file_length ();
    void update ();
    void Delete ();
};
int Branch::file_length(){
    Branch ob_Branch ;
    fstream f ;
	f.open( "BranchTable.txt" , ios::in ) ;
	int cnt = 0 ;
	while( !f.eof() ){
       f >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
         >> ob_Branch.mgr_branch;
         cnt++;
	}
    f.close();
	return --cnt ;
}
int getDigitsbranch (int n){
        int cnt = 0 ;
        while(n){
            n /= 10 ;
            cnt++;
        }
        return cnt ;
}
bool Branch::SearchToCheckValidBranch(int tmp){
      //cout << tmp << "\n" ;
      fstream f ;
      f.open( "BranchTable.txt" , ios::in ) ;
      Branch ob_Branch ;
      while( !f.eof() ){
        f >> ob_Branch.branch_id >> ob_Branch.branch_address
		  >> ob_Branch.phone_no >> ob_Branch.city_name >> ob_Branch.mgr_branch;
            if ( tmp == ob_Branch.branch_id ){
                //cout << tmp << " " << e1.emp_no << endl;
                return true ;
            }
    }
    f.close();
    return false ;
}
void  Branch::input(){
    fstream f;
	char choice;
    Branch ob_Branch ;
	f.open( "BranchTable.txt" , ios::app ) ;
	bool flag = 1 ;
        while ( 1 ){
		cout << "Enter branch_id, branch_address, phone_no, city_name and mgr_branch : " << "\n" ;
		cin >> ob_Branch.branch_id >> ob_Branch.branch_address
		>> ob_Branch.phone_no >> ob_Branch.city_name >> ob_Branch.mgr_branch;
        if( ob_Branch.file_length() == 0 )flag=0;else flag = 1;
        if( ob_Branch.SearchToCheckValidBranch(ob_Branch.branch_id) && flag ){
             cout << "\n\t<< Sorry , this id has the same name for the one we have >>\n\n";
             cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
             if ( choice == 'n' || choice == 'N' )break;
             else continue;
        }
        //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
		f <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
		<<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";

		cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
        if ( choice == 'n' || choice == 'N' )break;
      }
      f.close();
}
void Branch::print(){
    fstream f ;
    Branch ob_Branch ;
	f.open( "BranchTable.txt" , ios::in ) ;
	cout << "\nBranch_id"+string(4 ,' ')<<"Address"<<string(48,' ')<< "Phone_no"<<string(7,' ')<<"City"<<string(11,' ')<<"mgr_branch\n";
	cout << "------------ "<<"----------------------------------------------------   " <<"------------   "
	<<"-------------  "<<"----------\n";

	int id = 0 ;
	while( !f.eof() ){
      f >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
        >> ob_Branch.mgr_branch ;
      //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
      if (id != ob_Branch.branch_id){
       cout << ob_Branch.branch_id<<string(13-getDigitsbranch(ob_Branch.branch_id) ,' ')
            << ob_Branch.branch_address<<string(55-(int)ob_Branch.branch_address.size() ,' ')
            << ob_Branch.phone_no<< string(15-(int)ob_Branch.phone_no.size(),' ')
            << ob_Branch.city_name<< string(15-(int)ob_Branch.city_name.size(),' ')
            << ob_Branch.mgr_branch<<"\n";
             id = ob_Branch.branch_id ;
      }
 	}
 	f.close();
}


void Branch::search__(){
    Branch ob_Branch ;
    fstream f ;
    if ( !ob_Branch.file_length() ){
        cout << "The file is empty no data so far\n\n";
        return ;
    }
    else{
      cout << "\nEnter branch_id to search on : " ; int tmp ; cin >> tmp;
      cout << "The data of the required record is : \n\n" ;
      cout << "Branch_id"+string(4 ,' ')<<"Address"<<string(48,' ')<< "Phone_no"
       <<string(7,' ')<<"City"<<string(11,' ')<<"mgr_branch\n";
       cout << "------------ "
       <<"----------------------------------------------------   " <<"------------   "
	   <<"-------------  "<<"----------\n";
       f.open( "BranchTable.txt" , ios::in ) ;
            while( !f.eof() ){
            f >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
              >> ob_Branch.mgr_branch;
             if ( tmp == ob_Branch.branch_id ){
            cout << ob_Branch.branch_id<<string(13-getDigitsbranch(ob_Branch.branch_id) ,' ')
            << ob_Branch.branch_address<<string(55-(int)ob_Branch.branch_address.size() ,' ')
            << ob_Branch.phone_no<< string(15-(int)ob_Branch.phone_no.size(),' ')
            << ob_Branch.city_name<< string(15-(int)ob_Branch.city_name.size(),' ')
            << ob_Branch.mgr_branch<<"\n";
               break;
            }
        }
        f.close();
    }
}

void Branch::update (){
    Branch ob_Branch ;
    fstream f , tmp ;
    /// if the file is empty
    if ( ob_Branch.file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to update its record : ";int s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !ob_Branch.SearchToCheckValidBranch(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }


	f.open( "BranchTable.txt" , ios::in ) ;
	tmp.open( "TmpBranchTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
         >>ob_Branch.mgr_branch;
        if ( s == ob_Branch.branch_id ){
          cout << "Enter the updated branch_id      :";cin>>ob_Branch.branch_id;
          cout << "Enter the updated branch_address :";cin>>ob_Branch.branch_address;
          cout << "Enter the updated phone_no       :";cin>>ob_Branch.phone_no;
          cout << "Enter the updated city_name      :";cin>>ob_Branch.city_name;
          cout << "Enter the updated mgr_branch     :";cin>>ob_Branch.mgr_branch;

          tmp <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
              <<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";
          continue;
        }
        tmp <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
            <<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";
	}
	f.close();tmp.close();

    f.open( "BranchTable.txt" , ios::out ) ;
	tmp.open( "TmpBranchTable.txt" , ios::in ) ;
    while( !tmp.eof() ){
          tmp>> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
             >>ob_Branch.mgr_branch;
		  f <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
            <<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";

    }

    f.close();tmp.close();
	cout << "\n\n\t\t\t====== <<< Updated Done >>> ======\n\n\n";

}


void Branch::Delete(){
    /// if the file is empty
    Branch ob_Branch ;
    if ( ob_Branch.file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to delete its record : ";int s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !ob_Branch.SearchToCheckValidBranch(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }
    fstream f , tmp ;
	f.open( "BranchTable.txt" , ios::in ) ;
	tmp.open( "TmpBranchTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
         >> ob_Branch.mgr_branch;
        if ( s == ob_Branch.branch_id ){
          continue;
        }
        tmp <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
		<<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";
	}
	f.close();tmp.close();
    f.open( "BranchTable.txt" , ios::out ) ;
	tmp.open( "TmpBranchTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
      tmp >> ob_Branch.branch_id>>ob_Branch.branch_address>>ob_Branch.phone_no>>ob_Branch.city_name
          >>ob_Branch.mgr_branch;

      f  <<ob_Branch.branch_id<<" "<<ob_Branch.branch_address
         <<" "<<ob_Branch.phone_no<<" "<<ob_Branch.city_name<<" "<<ob_Branch.mgr_branch<<"\n";
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Deleted Done >>> ======\n\n\n";
}

#endif
