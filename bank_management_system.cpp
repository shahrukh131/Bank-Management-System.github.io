#include<iostream>
#include <iomanip>
#include<stdlib.h>
using namespace std;
class Account
{
 public:
        string name;
        int account_no;
        string account_type;
public:
        Account():name(" "),account_no(),account_type(" "){}
        void get_information()
        {
        	cout<<endl;
            cout<<"ACCOUNT HOLDER'S NAME:";
            cin>>name;
            cout<<"ACCOUNT NUMBER:";
            cin>>account_no;
            cout<<"ACCOUNT TYPE:";
            cin>>account_type;

        }
        void display_information()
        {
            cout<<"ACCOUNT HOLDER'S NAME:"<<name<<endl;
            cout<<"ACCOUNT NUMBER       :"<<account_no<<endl;
            cout<<"ACCOUNT TYPE         :"<<account_type<<endl;
        }


};
class Saving_account:public Account
{
  private:double balance;
          double deposit;
          double withdraw;
          double rate;
          int term;
  public:
        Saving_account():balance(0),deposit(0),withdraw(0),rate(0),term(0){}
        void getdata()
        {
            cout<<"DETAILS FOR THE SAVINGS ACCOUNT"<<endl;
            Account::get_information();
          
            while(1)
            {
            	cout<<"ENTER THE BALANCE         :";
            	cin>>balance;
                if(balance<500)
                {
                	
                    cout<<"BALANCE MUST BE AT LEAST RS 500"<<endl;
                    continue;
                }
                else break;
            }



            cout<<"ENTER THE INTEREST RATE   :";
            cin>>rate;
            while(1)
            {
                if(rate<=0)
                {
                    cout<<"RATE MUST BE GREATER THAN ZERO";
                    continue;
                }
                else break;
            }




            cout<<"ENTER THE TERM            :";
            cin>>term;
            while(1)
            {
                if(term<=0)
                {
                    cout<<"\nTERM MUST BE GREATER THAN ZERO"<<endl;
                    continue;
                }
                else break;

            }
            
            cout<<"\n\n\n ACCOUNT CREATED SUCCESSFULLY................"<<endl;
        }

        void Deposit()
        {
            cout<<"MONEY DEPOSIT SCREEN"<<endl;
            if(balance<=0)
            {
                cout<<"PLEASE CREATE AN ACCOUNT FOR DEPOSIT:"<<endl;
            }
            else{
                cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT        :"<<endl;
                cin>>deposit;
                while(1)
                {

                    if(deposit<=0)
                    {
                    cout<<"DEPOSIT MUST BE OVER TK 0"<<endl;
                    continue;
                    }
                    else
                    {
                    balance=balance+deposit;
                    cout<<"THE BALANCE AFTER MAKING DEPOSIT IS        :"<<balance<<endl;
                    break;
                    }
                }
             }
            }

        void Withdraw()
        {
            cout<<"MONEY WITHDRAWAL SCREEN"<<endl;
            cout<<"ENTER THE WITHDRAWAL AMOUNT            :"<<endl;
            cin>>withdraw;
            float temp;
            temp=balance-withdraw;
            if(temp<0)
            {
                cout<<"ILLEGAL WITHDRAWAL BALANCE COMES TO LESS THAN ZERO"<<endl;
                cout<<"CANNOT ALLOW TO WITHDRAW"<<endl;
            }
            else
            {
                balance=balance-withdraw;
                cout<<"THE BALANCE AFTER WITHDRAWAL IS    :"<<balance;
            }
        }
        void Interest()
        {
            if(balance>500&&term>1)
            {
            	double interest_balance;
                 cout<<"INTEREST CALCULATION SCREEN"<<endl;
                cout<<"INTEREST CALCULATED AT "<<rate<<"% FOR "<<term<<" YEARS"<<endl;
                for(int i=0;i<term;i++)
                {
				
                 interest_balance=(balance*rate*term)/100;
                 balance=balance+interest_balance;
                }
                cout<<"BALANCE AFTER ADDING INTEREST IS        :"<<balance<<endl;

            }
            else{
                cout<<"WITHOUT CREATING AN ACCOUNT YOU CAN'T GET ANY INTEREST"<<endl;
            }

        }

        void display_balance()
        {
            if(balance<=0)
            {
               cout<<"YOU HAVE NO BALANCE IN YOUR ACCOUNT.PLEASE DEPOSIT OR CREATE AN ACCOUNT"<<endl;
            }
            else
            {
                cout<<"LATEST BALANCE IS        : Rs. "<<balance<<endl;
            }
        }
        void display_details()
        {
            Account::display_information();
            display_balance();

        }
       
};
class current_account:public Account
{
private:
    double balance;
    double wit;
    double dep;

public:
    current_account()
    {
        balance=0;
        wit=0;
        dep=0;
    }
    ~current_account(){}

    void getdata()
    {
        Account::get_information();
        
        while(1)
        {
        	cout<<"ENTER THE BALANCE:"<<endl;
        	cin>>balance;

            if(balance<=0)
            {
                cout<<"BALANCE MUST BE GREATER THAN 0"<<endl;
                continue;

            }

            else
                {
                break;
            }
        }
        cout<<"\n\n\n ACCOUNT CREATED SUCCESSFULLY................"<<endl;
        
    }

    void deposit()
    {
    	cout<<"MONEY DEPOSIT SCREEN"<<endl;
            if(balance<=0)
            {
                cout<<"PLEASE CREATE AN ACCOUNT FOR DEPOSIT:"<<endl;
            }
            else
			{
				cout<<"ENTER THE AMOUNT YOU WANT TO DEPOSIT        :"<<endl;
                cin>>dep;

        		while(1)
                {

                    if(dep<=0)
                    {
                    cout<<"DEPOSIT MUST BE OVER TK 0"<<endl;
                    continue;
                    }
                    else
                    {
                    balance=balance+dep;
                    cout<<"THE BALANCE AFTER MAKING DEPOSIT IS        :"<<balance<<endl;
                    break;
                    }
                }

            }
    }


    void withdraw()
    {
        	cout<<"MONEY WITHDRAWAL SCREEN"<<endl;
            cout<<"ENTER THE WITHDRAWAL AMOUNT            :"<<endl;
            cin>>wit;
            float temp;
            temp=balance-wit;
            if(temp<0)
            {
                cout<<"ILLEGAL WITHDRAWAL BALANCE COMES TO LESS THAN ZERO"<<endl;
                cout<<"CANNOT ALLOW TO WITHDRAW"<<endl;
            }
            else
            {
                balance=balance-wit;
                cout<<"THE BALANCE AFTER WITHDRAWAL IS    :"<<balance;
            }

    }

    void display_balance()
        {
            if(balance<=0)
            {
               cout<<"PLEASE  CREATE AN ACCOUNT"<<endl;
            }
            else
            {
                cout<<"LATEST BALANCE IS        : Rs. "<<balance<<endl;
            }
        }
    void display_details()
        {
            Account::display_information();
            display_balance();

        }



};
int main()
{
    Saving_account s[10];
    current_account c[10];
    int i,cho,no,j;
    int flag=0;
    
    cout<<setw(55)<<"WELCOME TO OUR BANK MANGMENT SYSTEM"<<setw(45)<<endl<<endl<<endl<<endl;

    for(i=0;i<10;i++)
    {
	
    
        cout<<"ENTER S FOR SAVING ACCOUNT AND C FOR CURRENT ACCOUNT"<<endl;
        char type;
        cin>>type;
        if(type =='s' || type =='S')
        {
            int choice=0;
            while(choice!=7){
            	

            cout<<"     \n\n\n\t\tCHOOSE YOUR CHOICE:-"<<endl;
            cout<<"\t\t1)   CREATE AN ACCOUNT"<<endl;
            cout<<"\t\t2)   DISPLAY BALANCE" <<endl;
            cout<<"\t\t3)   DISPLAY BALANCE WITH INTEREST"<<endl;
            cout<<"\t\t4)   DISPLAY WITH FULL DETAILS"<<endl;
    		cout<<"\t\t5)   DEPOSIT"<<endl;
            cout<<"\t\t6)   WITHDRAW"<<endl;
            cout<<"\t\t7)   EXIT"<<endl;
            cout<<"PRESS KEY:";


            cin>>choice;
           
            switch(choice)
            {
                case 1 :
                        s[i].getdata();
                        break;
                case 2 :
                        s[i].display_balance();
                        break;
                case 3:
                        s[i].Interest();
                        break;
                case 4 :
                        while(1)
                        {
                        	cout<<"---ACCOUNT TRANSACTION FORM---"<<endl;
                                cout<<"\n\nENTER YOUR ACCOUNT NUMBER:";
                                cin>>no;
                                int v;
                                int flag=0;
                                for(j=0;j<=i;j++)
                                    {
                                        if(s[j].account_no==no)
                                        {
                                            v=j;
                                            flag=1;
                                            break;
                                        }
                                        else
                                        {}
                                    }
                                    if(flag==1)
                                    {
                                    	cout<<"\n\n---ACCOUNT STATUS---"<<endl;
                                        s[v].display_details();
                                    }
                                    else{
                                        cout<<"PLEASE CREATE AN ACCOUNT FIRST"<<endl;
                                    }



                                   break;
                        }
                        break;
                        
               


                case 5:

                        s[i].Deposit();
                        break;
                case 6 :
                        s[i].Withdraw();
                        break;

                case 7 :
                        break;
                default:

                cout<<"ENTERED CHOICE IS INVALID,TRY AGAIN"<<endl;

            }
        }


    }
    
    else if (type=='c'||type=='C')
    {
    	int choice=0;
    	while(choice!=6)
    	{
    		cout<<"\n\n\n\t\tCHOOSE YOUR CHOICE"<<endl;
    		
    		cout<<"\t\t1)	CREAT AN ACCOUNT  "  <<endl;
    		cout<<"\t\t2)	DISPLAY BALANCE   "<<endl;
    		cout<<"\t\t3)	DISPLAY WITH FULL DETAILS"<<endl;
    		cout<<"\t\t4)	DEPOSIT BALANCE   "<<endl;
    		cout<<"\t\t5)      WITHDRAW BALANCE  "  <<endl;
    	
    		cout<<"\t\t6)	EXIT"<<endl;
    		cout<<"PRESS KEY:";
    		
    		cin>>choice;
    	
    		switch(choice)
    		{
    			case 1:
    				c[i].getdata();
    				break;
    				
    			case 2:
    				c[i].display_balance();
    				break;
    				
    			case 3:
    				while(1)
    				{
    					cout<<"\n\n\n---ACCOUNT TRANSACTION FORM---"<<endl;
    					cout<<"ENTER YOUR ACCOUNT NO:";
    					cin>>no;
    					int v;
    					for(int k=0;k<=i;k++)
    					{
    						if(c[k].account_no==no)
    						{
    							v=k;
    							flag=1;
    							break;
							}
							else
							{
								
							}
						}
						if(flag==1)
						{
							cout<<"\n\n---ACCOUNT STATUS---"<<endl;
							c[v].display_details();
						}
						else
						{
							cout<<"PLEASE CREATE AN ACCOUNT FIRST"<<endl;
						}
						break;
							
							
					}
					break;
					
					
				case 4:
					c[i].deposit();
					break;
					
					
				case 5:
					c[i].withdraw();
					break;
					
				
                    
                case 6:
                	break;
					
				default:
					  cout<<"ENTERED CHOICE IS INVALID,TRY AGAIN"<<endl;
					  break;
					
					
			}
    				
			}
    		
	}
    	
	
    	
	
     cout<<"TO CONTINUE THIS MANAGEMENT SYSTEM FOR ANOTHER PERSON PRESS Y AND TO EXIT PRESS N"<<endl;
        char ch;
        cin>>ch;
        if(ch=='y'||ch=='Y')
          {
            continue;
          }
        else
          {
            break;
          }
      }


return 0;
}
