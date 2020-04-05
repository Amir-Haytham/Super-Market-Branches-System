#ifndef Employee_H_
#define Employee_H_

#include <bits/stdc++.h>
using namespace std;

class Employee{
    int emp_no ;
    string job_id ;
    string phone_no ;
    string first_name ;
    string last_name ;
    string email ;
    int salary ;
    string sec_id ;
    string hire_date ;
    string gender ;
    int branch_id ;
public :
    bool SearchToCheckValidEmp(int);
    void input ();
    void print ();
    void search_ ();
    int file_length ();
    void update ();
    void Delete ();
};

#endif
