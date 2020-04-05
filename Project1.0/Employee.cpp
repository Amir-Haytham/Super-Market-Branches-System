#include <bits/stdc++.h>
#include "Employee.h"

using namespace std;

int getDigitsEmp(int n){
        int nos = 0 ;
        while(n){
            n /= 10 ;
            nos++;
        }
        return nos ;
};
bool Employee::SearchToCheckValidEmp(int tmp){
      fstream f ;
      f.open( "empTable.txt" , ios::in ) ;
      Employee e1 ;
      while( !f.eof() ){
        f >> e1.emp_no >> e1.job_id >> e1.phone_no >> e1.first_name >> e1.last_name
          >> e1.email >> e1.salary >> e1.sec_id >> e1.hire_date >> e1.gender >> e1.branch_id ;
            if ( tmp == e1.emp_no ){
                return true ;
            }
    }
    f.close();
    return false ;
}
void Employee::input(){
    fstream f;
	char choice;
    Employee emp ;
	f.open( "empTable.txt" , ios::app ) ;
	bool flag = 1 ;
    while ( 1 ){
      cout << "Enter EMP_NO, JOB_ID, PHONE_NUMBER, F_NAME, L_NAME, EMAIL, SALARY, SEC, HIRE_DAT, GENDER and BRANCH_ID : " << "\n" ;
      cin >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
          >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
        if( Employee::SearchToCheckValidEmp(emp.emp_no) ){
             cout << "\n\t<< Sorry , this id has the same name for the one we have >>\n\n";
             cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
             if ( choice == 'n' || choice == 'N' )break;
             else continue;
        }
        f << emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
		  <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
		  <<" "<<emp.branch_id << " " <<"\n" ;
		  cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
		  if ( choice == 'n' || choice == 'N' )break;
        }

	f.close();
}

void Employee::print(){
    fstream f ;
	f.open( "empTable.txt" , ios::in ) ;
	cout << "\nEMP_NO "<<"JOB_ID       "
	<< "PHONE_NUMBER   "<<"F_NAME"+string(5,' ')<<"L_NAME"+string(5,' ')
	<<"EMAIL"+string(21,' ')<<"SALARY"+string(5,' ')<<"SEC "<<"HIRE_DAT "<<"GENDER  "<<"BRANCH_ID "<<"\n";
	cout <<"------ "<<"------------ " <<"-------------- "<<"---------- "<<"---------- "
	<<"------------------------- "<<"---------- "<<"--- "<<"-------- "<<"------- "<<"----------"<<"\n";
    Employee emp ;
	int id = 0 ;
	while( !f.eof() ){
      f >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
      >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
      //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
      if (id != emp.emp_no){
       cout << emp.emp_no<<string(7-getDigitsEmp(emp.emp_no) ,' ')
       << emp.job_id+string(13-(int)emp.job_id.size() ,' ')
       << emp.phone_no+string(15-(int)emp.phone_no.size(),' ')
       << emp.first_name+string(11-(int)emp.first_name.size(),' ')
       << emp.last_name+string(11-(int)emp.last_name.size(),' ')
       << emp.email+string(26-(int)emp.email.size(),' ')
       << emp.salary<<string(11-(int)getDigitsEmp(emp.salary),' ')
       << emp.sec_id+string(4-(int)emp.sec_id.size(),' ')
       << emp.hire_date+string(9-(int)emp.hire_date.size(),' ')
       << emp.gender+string(10-(int)emp.gender.size(),' ')
       << emp.branch_id<<"\n" ;
       id = emp.emp_no;
      }
 	}
 	f.close();
 	//cout << "\n\n" ;
 	//for(auto it : st)
    //    cout << it << "\n" ;
}
void Employee::search_ (){
    if ( !Employee::file_length () ){
        cout << "The file is empty no data so far\n\n";
        return ;
    }
    else{
      cout << "\nEnter empno to search on : " ; int tmp ; cin >> tmp ;
      cout << "The data of the required record is : \n\n" ;
      cout << "\nEMP_NO "<<"JOB_ID       "
	  << "PHONE_NUMBER   "<<"F_NAME"+string(5,' ')<<"L_NAME"+string(5,' ')
	  <<"EMAIL"+string(21,' ')<<"SALARY"+string(5,' ')<<"SEC "<<"HIRE_DAT "<<"GENDER  "<<"BRANCH_ID "<<"\n";
	  cout <<"------ "<<"------------ " <<"-------------- "<<"---------- "<<"---------- "
	  <<"------------------------- "<<"---------- "<<"--- "<<"-------- "<<"------- "<<"----------"<<"\n";
        Employee emp ;
      fstream f ;
      f.open( "empTable.txt" , ios::in ) ;
            while( !f.eof() ){
            f >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
              >> emp.email  >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
             if ( tmp == emp.emp_no ){
              cout << emp.emp_no<<string(7-getDigitsEmp(emp.emp_no) ,' ')
               << emp.job_id+string(13-(int)emp.job_id.size() ,' ')
               << emp.phone_no+string(15-(int)emp.phone_no.size(),' ')
               << emp.first_name+string(11-(int)emp.first_name.size(),' ')
               << emp.last_name+string(11-(int)emp.last_name.size(),' ')
               << emp.email+string(26-(int)emp.email.size(),' ')
               << emp.salary<<string(11-(int)getDigitsEmp(emp.salary),' ')
               << emp.sec_id+string(4-(int)emp.sec_id.size(),' ')
               << emp.hire_date+string(9-(int)emp.hire_date.size(),' ')
               << emp.gender+string(10-(int)emp.gender.size(),' ')
               << emp.branch_id<<"\n" ;
               break;
            }
        }
        f.close();
    }
}

int Employee::file_length (){
    Employee emp ;
    fstream f ;
	f.open( "empTable.txt" , ios::in ) ;
	int cnt = 0 ;
	while( !f.eof() ){
       f >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
      >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
       cnt++;
	}
	return --cnt ;
	f.close();
}

void Employee::update (){
    /// if the file is empty
    if ( Employee::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to update its record : ";int s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Employee::SearchToCheckValidEmp(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }

    Employee emp ;
    fstream f , tmp ;
	f.open( "empTable.txt" , ios::in ) ;
	tmp.open( "TmpempTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
      >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
        if ( s == emp.emp_no ){
          cout << "Enter the updated EMP_NO       :";cin>>emp.emp_no;
          cout << "Enter the updated JOB_ID       :";cin>>emp.job_id;
          cout << "Enter the updated PHONE_NUMBER :";cin>>emp.phone_no;
          cout << "Enter the updated F_NAME       :";cin>>emp.first_name;
          cout << "Enter the updated L_NAME       :";cin>>emp.last_name;
          cout << "Enter the updated EMAIL        :";cin>>emp.email;
          cout << "Enter the updated salary       :";cin>>emp.salary;
          cout << "Enter the updated SEC_id       :";cin>>emp.sec_id;
          cout << "Enter the updated hire date    :";cin>>emp.hire_date;
          cout << "Enter the updated gender       :";cin>>emp.gender;
          cout << "Enter the updated branch_id    :";cin>>emp.branch_id;


          tmp <<emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
		  <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
		  <<" "<<emp.branch_id<<"\n" ;
          continue;
        }
        tmp <<emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
		  <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
		  <<" "<<emp.branch_id<<"\n" ;
	}
	f.close();tmp.close();

    f.open( "empTable.txt" , ios::out ) ;
	tmp.open( "TmpempTable.txt" , ios::in ) ;
    while( !tmp.eof() ){
          tmp>> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
           >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
		  f <<emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
		  <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
		  <<" "<<emp.branch_id<<"\n" ;

    }

    f.close();tmp.close();
	cout << "\n\n\t\t\t====== <<< Updated Done >>> ======\n\n\n";

}


void Employee::Delete(){
    /// if the file is empty
    if ( Employee::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to delete its record : ";int s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( !Employee::SearchToCheckValidEmp(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }
    Employee emp ;
    fstream f , tmp ;
	f.open( "empTable.txt" , ios::in ) ;
	tmp.open( "TmpempTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
         >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;
        if ( s == emp.emp_no ){
          continue;
        }
        tmp <<emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
        <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
        <<" "<<emp.branch_id<<"\n" ;
	}
	f.close();tmp.close();
    f.open( "empTable.txt" , ios::out ) ;
	tmp.open( "TmpempTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
      tmp >> emp.emp_no >> emp.job_id >> emp.phone_no >> emp.first_name >> emp.last_name
          >> emp.email >> emp.salary >> emp.sec_id >> emp.hire_date >> emp.gender >> emp.branch_id ;

		  f <<emp.emp_no<<" "<<emp.job_id<<" "<<emp.phone_no<<" "<<emp.first_name<<" "<<emp.last_name
		  <<" "<<emp.email<<" "<<emp.salary<<" "<<emp.sec_id<<" "<<emp.hire_date<<" "<<emp.gender
		  <<" "<<emp.branch_id<<"\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Deleted Done >>> ======\n\n\n";

}


