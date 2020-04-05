#ifndef Section_H_
#define Section_H_

#include <bits/stdc++.h>
using namespace std;
struct Section{
    string sec_id ;
    string SEC_NAME ;
    int MGR_SEC ;
public:
    bool SearchToCheckValidSection(string);
    void input ();
    void print ();
    void search_ ();
    int  file_length ();
    void update ();
    void Delete ();
};

#endif
