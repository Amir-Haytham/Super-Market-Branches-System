#include <bits/stdc++.h>
#include "Job.h"

using namespace std ;

int getDigitsJob(int n){
        int nos = 0 ;
        while(n){
            n /= 10 ;
            nos++;
        }
        return nos ;
};
bool Job::SearchToCheckValid(string tmp){
      Job ob_Job ;

      fstream f ;
      f.open( "jobTable.txt" , ios::in ) ;
      while( !f.eof() ){
            f >> ob_Job.job_id >> ob_Job.job_title >> ob_Job.max_salary
            >> ob_Job.min_salary >> ob_Job.sec_id ;
            if ( tmp == ob_Job.job_id ){
                return 0;
            }
    }
    f.close();
    return 1 ;
}
void Job::input(){
    fstream f;
	char choice;
    Job ob_Job ;

	f.open( "jobTable.txt" , ios::app ) ;
	bool flag = 1 ;
    while ( 1 ){
		cout << "Enter job_id , title , max salary , min salary and section id  : " << "\n" ;
		cin >> ob_Job.job_id >> ob_Job.job_title
		>> ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
        if( !Job::SearchToCheckValid(ob_Job.job_id) ){
             cout << "\n\t<< Sorry , this id is has the same name for the one we have >>\n\n";
             cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
             if ( choice == 'n' || choice == 'N' )break;
             else continue;
        }
        // else st.insert(ob_Job.job_id);
        //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
		f << ob_Job.job_id << " " <<
		ob_Job.job_title << " " << ob_Job.max_salary << " " << ob_Job.min_salary
		<< " " << ob_Job.sec_id << "\n" ;

		cout << "\nEnter N or n if you want to Exit : " ; cin >> choice ;
		if ( choice == 'n' || choice == 'N' )break;
    }
	f.close();
}

void Job::print(){
    Job ob_Job ;
    fstream f ;
	f.open( "jobTable.txt" , ios::in ) ;
	cout << "JOB_ID"+string(9 ,' ')<<"JOB_TITLE"<<string(26,' ')<< "MIN_SALARY"<<"    "<<"MAX_SALARY"<<"   "<<"SEC\n";
	cout << "------------   "<<"------------------------------     " <<"----------"<<"    "<<"----------"<<"   "<<"---\n";

	string id = "" ;
	while( !f.eof() ){
      f >> ob_Job.job_id >> ob_Job.job_title >> ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
      //f.write( (char*) &ob_Job, sizeof ( ob_Job ) );
      if (id != ob_Job.job_id){
       cout << ob_Job.job_id+string(15-(int)ob_Job.job_id.size() ,' ')
       <<ob_Job.job_title+string(35-(int)ob_Job.job_title.size() ,' ')
       << ob_Job.max_salary  << string(14-getDigitsJob(ob_Job.max_salary),' ')
       << ob_Job.min_salary  << string(13-getDigitsJob(ob_Job.min_salary),' ')
       << ob_Job.sec_id << "\n" ;
       id = ob_Job.job_id ;
      }
 	}
 	f.close();
 	//cout << "\n\n" ;
 	//for(auto it : st)
    //    cout << it << "\n" ;
}

void Job::search_ (){
    Job ob_Job ;

    if ( !Job::file_length () ){
        cout << "The file is empty no data so far\n\n";
        return ;
    }
    else{
      cout << "\nEnter JOB_ID to search on : " ; string tmp ; cin >> tmp ;
      cout << "The data of the required record is : \n\n" ;
      cout << "JOB_ID"+string(9 ,' ')<<"JOB_TITLE"
      <<string(26,' ')<< "MIN_SALARY"<<"    "<<"MAX_SALARY"<<"   "<<"SEC\n";
	  cout << "------------   "<<"------------------------------     "
	  <<"----------"<<"    "<<"----------"<<"   "<<"---\n";

      fstream f ;
      f.open( "jobTable.txt" , ios::in ) ;
            while( !f.eof() ){
            f >> ob_Job.job_id >> ob_Job.job_title >> ob_Job.max_salary
            >> ob_Job.min_salary >> ob_Job.sec_id ;
            if ( tmp == ob_Job.job_id ){
                cout << ob_Job.job_id+string(15-(int)ob_Job.job_id.size() ,' ')
                <<ob_Job.job_title+string(35-(int)ob_Job.job_title.size() ,' ')
                << ob_Job.max_salary  << string(14-getDigitsJob(ob_Job.max_salary),' ')
                << ob_Job.min_salary  << string(13-getDigitsJob(ob_Job.min_salary),' ')
                << ob_Job.sec_id << "\n" ;
                break;
            }
        }
        f.close();
    }
}

int Job::file_length (){
    Job ob_Job ;

    fstream f ;
	f.open( "jobTable.txt" , ios::in ) ;
	int cnt = 0 ;
	while( !f.eof() ){
       f >> ob_Job.job_id >> ob_Job.job_title >>
       ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
       cnt++;
	}
	return --cnt ;
	f.close();
}

void Job::update (){
    Job ob_Job ;

    /// if the file is empty
    if ( Job::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to update its record : ";string s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( Job::SearchToCheckValid(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }


    fstream f , tmp ;
	f.open( "jobTable.txt" , ios::in ) ;
	tmp.open( "TmpjobTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> ob_Job.job_id >> ob_Job.job_title >>
       ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
        if ( s == ob_Job.job_id ){
          cout << "Enter the updated JOB_ID     :";cin>>ob_Job.job_id;
          cout << "Enter the updated JOB_TITLE  :";cin>>ob_Job.job_title;
          cout << "Enter the updated MAX_SALARY :";cin>>ob_Job.max_salary;
          cout << "Enter the updated MIN_SALARY :";cin>>ob_Job.min_salary;
          cout << "Enter the updated Section    :";cin>>ob_Job.sec_id;
          tmp << ob_Job.job_id << " " << ob_Job.job_title << " "
          << ob_Job.max_salary << " " << ob_Job.min_salary << " " << ob_Job.sec_id << "\n" ;
          continue;
        }
        tmp << ob_Job.job_id << " " <<
        ob_Job.job_title << " " <<
        ob_Job.max_salary << " " <<
        ob_Job.min_salary<< " " <<
        ob_Job.sec_id << "\n" ;
	}
	f.close();tmp.close();
    f.open( "jobTable.txt" , ios::out ) ;
	tmp.open( "TmpjobTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp >> ob_Job.job_id >> ob_Job.job_title >>
        ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
        f << ob_Job.job_id << " " <<
        ob_Job.job_title << " " <<
        ob_Job.max_salary << " " <<
        ob_Job.min_salary<< " " <<
        ob_Job.sec_id << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Updated Done >>> ======\n\n\n";

}


void Job::Delete(){

    Job ob_Job ;

    /// if the file is empty

    if ( Job::file_length() == 0 ){
        cout << "\n<< The file is empty there's no record >>\n\n";
        return ;
    }

    /// ok, Read and Check
    cout << "\nEnter the JOB_ID you want to delete its record : ";string s;cin>>s;

    /// if there's no matching with any id record. so, there's no use to update
    if( Job::SearchToCheckValid(s) ){
        cout << "\n\n\t==========<< There's no matching record check it again >>==========\n\n\n";
        return ;
    }

    fstream f , tmp ;
	f.open( "jobTable.txt" , ios::in ) ;
	tmp.open( "TmpjobTable.txt" , ios::out ) ;
	while( !f.eof() ){
       f >> ob_Job.job_id >> ob_Job.job_title >>
       ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
        if ( s == ob_Job.job_id ){
          continue;
        }
        tmp << ob_Job.job_id << " " <<
        ob_Job.job_title << " " <<
        ob_Job.max_salary << " " <<
        ob_Job.min_salary<< " " <<
        ob_Job.sec_id << "\n" ;
	}
	f.close();tmp.close();
    f.open( "jobTable.txt" , ios::out ) ;
	tmp.open( "TmpjobTable.txt" , ios::in ) ;
	while ( !tmp.eof() ){
        tmp >> ob_Job.job_id >> ob_Job.job_title >>
        ob_Job.max_salary >> ob_Job.min_salary >> ob_Job.sec_id;
        f << ob_Job.job_id << " " <<
        ob_Job.job_title << " " <<
        ob_Job.max_salary << " " <<
        ob_Job.min_salary<< " " <<
        ob_Job.sec_id << "\n" ;
	}
    f.close();tmp.close();

	cout << "\n\n\t\t\t====== <<< Deleted Done >>> ======\n\n\n";

}
