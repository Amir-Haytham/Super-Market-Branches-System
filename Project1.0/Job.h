#ifndef Job_H_
#define Job_H_

#include <bits/stdc++.h>
using namespace std ;


class Job{

    string job_id ;
    string job_title ;
    int max_salary ;
    int min_salary ;
    string sec_id ;

    public :
    bool SearchToCheckValid(string);
    void input ();
    void print ();
    void search_ ();
    int file_length ();
    void update ();
    void Delete ();
};
#endif
