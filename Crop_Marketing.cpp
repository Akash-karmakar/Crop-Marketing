#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

map<string,int>password;
map<string,int>::iterator it;



int temp_choice;


int password_log()
{
    int password_index = 0;
    char password_temp;
    string pass;
    pass ="";
    char ch;
    ch = _getch();
    while(ch != 13) //character 13 is enter
    {
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }

    stringstream geek(pass);
    int x = 0;
    geek >> x;

    return x;
}


bool name_verify(string s)
{
    if(password.empty())
    {
        return false;
    }
    it = password.find(s);
    if(it!=password.end())
    {
        return true;

    }
    else
    {
        return false;
    }
}

int password_verify(string s,int n)
{
    if(password.empty())
    {
        return 2000;
    }
    it = password.find(s);
    if(it!=password.end())
    {
        if(password[s]==n)
        {
            int index = distance(password.begin(),password.find(s));
            return index;
        }
        else
            return 1000;


    }
    else
    {
        return 1000;
    }
}

class login
{
    string name;
    int temp_password;
    int user_index;

public:

    void getinput()
    {

        cout<<"Login "<<endl;
        cout<<"Name: ";
        cin>>name;
        cout<<"Password: ";
        temp_password= password_log();

        user_index =  password_verify(name,temp_password);

        if(user_index==2000)
        {
            cout<<endl<<"\n Please registration first"<<endl;
        }

        else if(user_index!=1000)
        {
            cout<<endl<<"\n successfully login."<<endl;
        }
        else
        {
            cout<<endl<<"\n Invalid user name/password"<<endl;
        }

        cout<<endl;

    }

};

class registration
{
    string name1,name2,user_name,address,number;
    int temp_password;

public:

    void getinput()
    {

        cout<<"Registration[Required] "<<endl;
        cout<<"First name*: ";
        cin>>name1;
        cout<<"Last name*: ";
        cin>>name2;
        cout<<"Username*: ";
        cin>>user_name;
        cout<<"Phone number*: ";
        cin>>number;
        cout<<"Address*: ";
        cin>>address;
        cout<<"Password: ";
        temp_password= password_log();

        password.insert(pair<string,int>(user_name,temp_password));

        cout<<endl;

        cout<<endl<<" Registration successful."<<endl<<endl;



    }



};



class Sell
{
    map<string,int>product_quantity;
    map<string,int>product_price;
    map<string,int>:: iterator it;
    map<string,int>:: iterator st;
    string temp_name;

public:
    int choice,x,y,price;;
    void fast_choice()
    {
        cout<<"  \nWelcome to the sell Section.  "<<endl<<endl;
        cout<<"Enter user name: ";
        cin>>temp_name;
        cout<<endl;
        if(name_verify(temp_name))
        {
            cout<<"Apni ki bikroy korte chan?"<<endl<<endl;
            cout<<"1. Chal."<<"\n"<<"2. Dal."<<"\n"<<"3. Ata."<<endl;
            cout<<"4. Tel."<<"\n"<<"5. Alu."<<"\n"<<"6. Peyaj."<<endl<<endl;

            cout<<"Choice: ";
            cin >> choice;
            cout << endl;
        }
        else
        {
            cout<<" Please register first."<<endl<<endl;
            choice=7;
            return;
        }
    }

    void Description(int name)
    {
        cout<<"Apnar kache ki poriman Ponno mojud ache?"<<endl;
        cin>>x;
        cout<<"Proti KG koto taka kore bickroy korte chan?"<<endl;
        cin>>y;
        switch(name)
        {
        case 1:
            product_quantity.insert(pair<string,int>("Chal", x));
            product_price.insert(pair<string,int>("Chal",y));
            break;

        case 2:
            product_quantity.insert(pair<string,int>("Dal", x));
            product_price.insert(pair<string,int>("Dal",y));
            break;

        case 3:
            product_quantity.insert(pair<string,int>("Ata", x));
            product_price.insert(pair<string,int>("Ata",y));
            break;

        case 4:
            product_quantity.insert(pair<string,int>("Tel", x));
            product_price.insert(pair<string,int>("Tel",y));
            break;

        case 5:
            product_quantity.insert(pair<string,int>("Alu", x));
            product_price.insert(pair<string,int>("Alu",y));
            break;

        case 6:
            product_quantity.insert(pair<string,int>("Peyaj", x));
            product_price.insert(pair<string,int>("Peyaj",y));
            break;

        }
    }
    int bikroy_biboron()
    {
        cout<<endl<<endl;
        cout<<"Apni ki aro kisu bikroy korte chan?  "<<endl<<endl;
        cout<<"1.Yes\n2.NO\n"<<endl;
        cin>>temp_choice;
        if(temp_choice==2)
        {
            cout<<"\nProduct\tQuantity  Price\n";
            for(it=product_quantity.begin(),st=product_price.begin() ; it!=product_quantity.end(),st!=product_price.end(); it++,st++)
            {
                cout<<it->first<<"\t"<<it->second<<"\t  "<<st->second<<endl;
            }
            return(0);
            cout<<endl;
        }
        else
        {
            cout<<"\nInvalid number."<<endl;
            cout<<"Choice 1 / 2 "<<endl;
            cin>>temp_choice;
            if(temp_choice==2)
            {
                cout<<"\nProduct\tQuantity  Price\n";
                for(it=product_quantity.begin(),st=product_price.begin() ; it!=product_quantity.end(),st!=product_price.end(); it++,st++)
                {
                    cout<<it->first<<"\t"<<it->second<<"\t  "<<st->second<<endl;
                }
                return(0);
                cout<<endl;
            }
        }
    }

    void ponno()
    {
        while(1)
        {

            if(temp_choice==2)
            {
                break;
            }
            fast_choice();
            switch(choice)
            {
            case 1:
                cout<<"Ok, Apni chal bikroy korte chan."<<endl<<endl;
                Description(1);
                bikroy_biboron();
                break;

            case 2:
                cout<<"Ok, Apni Dal bikroy korte chan."<<endl<<endl;
                Description(2);
                bikroy_biboron();
                break;
            case 3:
                cout<<"Ok, Apni Ata bikroy korte chan."<<endl<<endl;
                Description(3);
                bikroy_biboron();
                break;
            case 4:
                cout<<"Ok, Apni Tel bikroy korte chan."<<endl<<endl;
                Description(4);
                bikroy_biboron();
                break;
            case 5:
                cout<<"Ok, Apni Alu bikroy korte chan."<<endl<<endl;
                Description(5);
                bikroy_biboron();
                break;
            case 6:
                cout<<"Ok, Apni Peyaj bikroy korte chan."<<endl<<endl;
                Description(6);
                bikroy_biboron();
                break;
            case 7:
                return;
                break;

            default:
                cout<< "Sorry you enter invalid number.\n";
                cout<<"Choice 1 - 6 "<<endl;
                cin >> choice;
                cout<<endl;
                {
                    if(choice==1)
                    {
                        cout<<"Ok, Apni chal bikroy korte chan."<<endl<<endl;
                        Description(1);
                        bikroy_biboron();
                        break;
                    }
                    else if(choice==2)
                    {
                        cout<<"Ok, Apni Dal bikroy korte chan."<<endl<<endl;
                        Description(2);
                        bikroy_biboron();
                        break;
                    }
                    else if(choice==3)
                    {
                        cout<<"Ok, Apni Ata bikroy korte chan."<<endl<<endl;
                        Description(3);
                        bikroy_biboron();
                        break;
                    }
                    else if(choice==4)
                    {
                        cout<<"Ok, Apni Tel bikroy korte chan."<<endl<<endl;
                        Description(4);
                        bikroy_biboron();
                        break;
                    }
                    else if(choice==5)
                    {
                        cout<<"Ok, Apni Alu bikroy korte chan."<<endl<<endl;
                        Description(5);
                        bikroy_biboron();
                        break;
                    }
                    else if(choice==6)
                    {
                        cout<<"Ok, Apni Peyaj bikroy korte chan."<<endl<<endl;
                        Description(6);
                        bikroy_biboron();
                        break;
                    }

                }

                cout << endl;
                break;
            }
        }

    }
};

main()
{
    registration Reg[1000];
    int reg_index=0;
    login Log[1000];
    int log_index = 0;
    Sell sell_obj[1000];
    int sell_index=0;

    while(1)
    {
        cout<<"\n1.login"<<"\t\t"<<"2.Registration"<<"\t\t"<<"3.Sell"<<"\t\t"<<"4.Buy"<<"\t\t"<<"5.Exit"<<endl<<endl;

        int number;
        cin>>number;

        switch(number)

        {

        case 1:
            Log[log_index].getinput();
            log_index++;
            break;

        case 2:
            Reg[reg_index].getinput();
            reg_index++;
            break;

        case 3:
            sell_obj[sell_index].ponno();
            sell_index++;
            temp_choice=0;
            break;

        case 5:
            cout<<"Thank you for use me."<<endl<<endl;
            exit(0);


        default:
            cout<<"\nWrong Input"<<endl;
            break;


        }


    }
}
