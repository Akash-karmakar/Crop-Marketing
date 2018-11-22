#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#include<string>

using namespace std;
string name;
string name1[1000],name2[1000],address[1000],number[1000];
string user_name[1000];

string password[1000],temp_password[10];

int index_name1=0;
int index_name2=0;
int index_address=0;
int index_number=0;
int index_username=0;
int index_password=0;

int check_temp_hudai_password;


bool check_user(string user[], string s,int index)
{


    for(int i = 0; i<index; i++)
    {
        if(user[i]==s)
        {
            check_temp_hudai_password = i;
            return true;
        }
    }

    check_temp_hudai_password = 1000;
    return(false);
}





void password_log(string pass[],int n)
{
    int password_index = 0;
    char password_temp;
    pass[n] ="";
    char ch;
    ch = _getch();
    while(ch != 13) //character 13 is enter
    {
        pass[n].push_back(ch);
        cout << '*';
        ch = _getch();
    }
}

class login
{

public:

    void getinput()
    {

        cout<<"Login "<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<"Password: ";

        password_log(temp_password,0);
        if(check_user(user_name,name,index_username))
        {
            if(check_temp_hudai_password!=1000)
            {
                if(password[check_temp_hudai_password]==temp_password[0])
                {
                    cout<<endl<<"\nsuccessfully login."<<endl<<endl;
                }
                else
                {
                    cout<<endl<<"\nInvalid user name/password"<<endl;
                }

            }
        }
        cout<<endl;
        //puts(password);
//        cout<<"successfully login."<<endl<<endl;
    };



};

class registration
{

public:

    void getinput()
    {

        cout<<"Registration[Required] "<<endl;
        cout<<"First name*: ";
        cin>>name1[index_name1];
        index_name1++;
        cout<<"Last name*: ";
        cin>>name2[index_name2];
        index_name2++;
        cout<<"Username: ";
        cin>>user_name[index_username];
        index_username++;
        cout<<"Phone number*: ";
        cin>>number[index_number];
        index_number++;
        cout<<"Address*: ";
        cin>>address[index_address];
        index_address++;
        cout<<"Password: ";
        password_log(password,index_password);
        index_password++;
        cout<<endl;
        //puts(password);
        cout<<endl<<" Registration successful."<<endl<<endl;



    };



};

main()
{
    registration r;
    login l;
    do
    {


        cout<<"1.login"<<"\t\t"<<"2.Registration"<<"\t\t"<<"3.Buy"<<"\t\t"<<"4.Sell"<<"\t\t"<<"5.Exit"<<endl<<endl;

        int number, i;
        cin>>number;

        switch(number)

        {

        case 1:
            l.getinput();
            break;

        case 2:
            r.getinput();
            break;



        case 5:
            cout<<"Thank you for use me."<<endl<<endl;
            exit(0);


        default:
            cout<<"Wrong Input"<<endl;
            break;


        }


    }

    while(1);




}
