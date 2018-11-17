#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>
#include<string>

using namespace std;

char password[1000];

void password_log(char psasword_star[])
{
    int password_index = 0;
    char password_temp;
Start:
    while(1)
    {
        password_temp = getch();
        // if(password_temp<= 'a' && password_temp>='z' || password_temp<= 'A' && password_temp>='Z' || password_temp<= '0' && password_temp>='9' )
        if(isalpha(password_temp)|| isdigit(password_temp))
        {
            password[password_index] = password_temp;
            password_index++;
            cout<<"*";
        }

        if(password_temp == '\b')
        {
            password[password_index] = '\b';
            password_index--;
        }

        if(password_temp == '\r')
        {
            password[password_index] = '\0';
            break;
        }
    }

    if(password_index<=5)
    {
        cout<<"\nPassword should be at least 6 character long. Press enter to try again-\n ";
        getch();
        password_index=0;
        goto Start;
    }
}

class login
{

public:

    string name;

    void getinput()
    {

        cout<<"Login "<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<"Password: ";
        password_log(password);
        cout<<endl;
        //puts(password);
        cout<<"successfully login."<<endl<<endl;



    };



};

class registration
{

public:

    string name1,name2,address;
    int number;

    void getinput()
    {

        cout<<"Registration[Required] "<<endl;
        cout<<"First name*: ";
        cin>>name1;
        cout<<"Last name*: ";
        cin>>name2;
        cout<<"Phone number*: ";
        cin>>number;
        cout<<"Address*: ";
        cin>>address;
        cout<<"Password: ";
        password_log(password);
        cout<<endl;
        //puts(password);
        cout<<endl<<" Registration successful."<<endl<<endl;



    };



};

main()
{
    registration r;
    login l;
    do{


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
