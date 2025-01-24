#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class bank
{
private:
   int money;
   string username, password;

public:
   void makeaccount();
   void balance();
   void withdraw();
   void deposit();
   void changepassword();
};
void bank::makeaccount()
{
   int money;
   string username, password;
   ofstream input;
   input.open("user.txt");
   cout << "\n Enter your name(without space) :";
   cin >> username;
   input << username;
   cout << " Username created : " << username;
   cout << "\n \n Enter password : ";
   cin >> password;
   cout << " Password created : " << password;
   input << "\n"
         << password;
   cout << "\n \n Enter ammount of money : $";
   cin >> money;

   cout << "\nPlease enter a real number";

   cout << " Money added : $" << money;
   input << "\n"
         << money;
   input.close();
   cout << "\n Your Account created successfully";
}
void bank::balance()
{
   string str, chk_password;
   int money;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   money = stoi(str);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "The balance in your account is : $" << money << "\n";
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::withdraw()
{
   string str, chk_password;
   int money;
   int with;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   money = stoi(str);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "\n Enter ammount to be withdrawn :$";
      cin >> with;
      if (with > money)
      {
         cout << "\nCan't withdraw ammount more than ammount in your balance \nYour current balance is :$" << money;
      }
      else
      {
         int newwm = money - with; // newwm=new with money
         cout << " The balance in your account is : $" << newwm << endl;
         ofstream input;
         input.open("user.txt", ios::out);
         input << username;
         input << "\n"
               << password;
         input << "\n"
               << newwm;
         input.close();
         cout << "\n Ammount withdrawn successfully";
      }
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::deposit()
{
   int money, deposit;
   string str, chk_password;
   ifstream output;
   output.open("user.txt");
   getline(output, username);
   getline(output, password);
   getline(output, str);
   money = stoi(str);
   output.close();
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      cout << "\n Your current balance is : $" << money;
      cout << "\n Enter the ammount you want to deposit in your account : $";
      cin >> deposit;
      int newdpm = deposit + money; // newdpm= new deposit money
      cout << "\n Money deposited in your account : $" << deposit;
      cout << "\n Your updated bank balance is : $" << newdpm;
      ofstream input;
      input.open("user.txt", ios::out);
      input << username;
      input << "\n"
            << password;
      input << "\n"
            << newdpm;
      input.close();
      cout << "\n Ammount deposited successfully";
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
void bank::changepassword()
{
   // to modify the username and password
   int money;
   string new_password, str, chk_password;
   cout << "\nVerify your password first : ";
   cin >> chk_password;
   if (chk_password == password)
   {
      ifstream output;
      output.open("user.txt");
      getline(output, username);
      getline(output, password);
      getline(output, str);
      money = stoi(str);
      output.close();
      ofstream input;
      input.open("user.txt", ios::out);
      input << username;
      cout << "\nEnter new password : ";
      cin >> new_password;
      input << "\n"
            << new_password;
      input << "\n"
            << money;
      password = new_password;
      cout << "updated details : " << password;
      input.close();
      cout << "\n Password changed successfully";
   }
   else
   {
      cout << "\nPassword entered is incorrect\n";
   }
}
int main()
{
   int bnk;
   bank user;
   char value;
top:
   cout << "\t\t\t\t\t\tWELCOME TO THE BANK";
   cout << "\n******************************************************************************************************************************";
   cout << "\n|Enter your choice from below                                                                                                |";
   cout << "\n|(1)-Make an Account                                                                                                         |";
   cout << "\n|(2)-Check Account Balance                                                                                                   |";
   cout << "\n|(3)-Withdraw Money                                                                                                          |";
   cout << "\n|(4)-Deposit Money                                                                                                           |";
   cout << "\n|(5)-Change password of your account                                                                                         |";
   cout << "\n|(6)-Exit                                                                                                                    |";
   cout << "\n******************************************************************************************************************************";
   cout<<"\n-->";
   cin >> bnk;
   switch (bnk)
   {
   case 1:
      cout << "You have choosen to (Make an account)";
      user.makeaccount();
      break;
   case 2:
      cout << "You have choosen to (Check your balance)\n";
      user.balance();
      break;
   case 3:
      cout << "You have choosen to (Withdraw ammount from your account)";
      user.withdraw();
      break;
   case 4:
      cout << "You have choosen to (Deposit an ammount to your account)";
      user.deposit();
      break;
   case 5:
      cout << "You have choosen to (Change password of your account)";
      user.changepassword();
      break;
   case 6:
      cout << "\nYou have choosen to (exit)";
      goto bottom;
      break;
   default:
      cout << "Enter a valid value ";
      break;
   }
   cout << "\nDo you want to reuse our service? (enter y or n ):";
   cout<<"\n-->";
   cin >> value;
   if (value == 'y' || value == 'Y')
   {
      goto top;
   }
   else
   {
      cout << "\nProgram ended successfully";
   }
bottom:
   cout << "\nThanks for using our service";
}