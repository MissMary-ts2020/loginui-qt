
#include <string.h>
#include <iostream>
#include "functions.h"

using namespace main_functions;
int login_if::if_is_true(const char* username,const char* password){
    char username_list[6][20]={
        "mary","jack","pony","marx","jobs","bill"
    };
    char password_list[6][20]={
        "abcdef","fedcba","123456","654321","135246","acebdf"
    };
    int i=0;
    for(;i<6;i++){
        if(!strcmp(*(username_list+i),username)){
            break;//finded the correct username, i is at the position of the true place
        }
    }
    if(i<6&& !strcmp(*(password_list+i),password)){
        //founded,correct pwd
        return 0;

    }else if(i<6){
        //founded,wrong pwd
        return 1;
    }else{
        //wrong username
        return 2;
    }
}
void login_if::demo(void)
{
    using namespace std;
    cout<<"hello\n";
}
