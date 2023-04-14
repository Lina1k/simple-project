
/******************************************************************************
Write a program in C++ that allows clients to exchange one currency for another.
#input:
1.The user enters the abbreviation for the currency they own.
2.The user enters the currency abbreviation to be converted to.
3.The user enters the amount of money that he wants to convert into the other currency. 
4.Read the data from the file “ExchangeRate.txt”.
#output:
1. List of currencies that the program can convert between.
2. Ask the user to enter the currency he owns and the currency he wants to convert to.
3. The result of the conversion process between the two currencies.
 *******************************************************************************/
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std ;
void Read_currency();
string userCin1 (string );
string userCin2 (string );
void ExchangeCurrency (string , string );

int main() {
    Read_currency();
    string uCurr1 , uCurr2 ;
    cout << "what is the currency you have ? "<<endl;
    cin >> uCurr1 ;
    uCurr1= userCin1(uCurr1);
    cout << "What is the currency you want to exchange it for?"<<endl;
    cin >>uCurr2;
    uCurr2=userCin1(uCurr2);
    ExchangeCurrency (uCurr1 , uCurr2);
    return 0;
  }

// fun 1 : void function prints a list of available currencies.

void Read_currency(){
cout<<"The currencies we have exchange for are:\n\n"
   <<"SAR--> Saudi Arabia Riyal\n"
   <<"KWD--> Kuwaiti Dinar\n"
   <<"QAR--> Qatar Riyal\n"
   <<"AED--> United Arab Emirates Dirha\n"
   <<"BHD--> Bahraini Dinar\n"
   <<"OMR--> Omani Riyal\n"
   <<"\n-------------------------\n\n";
}

// fun 2 : formale parameter : one varible in string type represents the first currency that user enter.
// purpose of this function : it will transmit the input to the main if it is valid ; if not it will print
// a massage requesting the user to enter it again and so on until the user enters a valid input.
// return value : ( uCurr1 ) after checking it.

string userCin1 (string uCurr1 )
{
   int length = uCurr1.length();
   bool flag = false ;
   while (!flag) {
      for (int i =0 ; i < length ; i++)
         uCurr1[i]=static_cast<char>(toupper(uCurr1[i]));
      if (uCurr1=="SAR"||uCurr1=="KWD"||uCurr1==
         "QAR"||uCurr1=="AED"||uCurr1=="BHD"||uCurr1=="OMR" ){
          flag = true ;
          return uCurr1 ;}

      else
         cout << " Incorrect abbreviation please provide it again "<<endl;
      cin >> uCurr1 ;
   }
   return " ";
   }

// fun 3 : the same as the previous function, but this function represents the second variable
// which is the currency that the user wants to convert to.


// fun 4 : formal parameter : it's take two variable's in string type.
// uCuur1 : it represents the currency that the user owns.
// ucurr2 : it represents the currency to which he wants to convert.
// the purpose of this function : reads information from the file,
// stors numbers in variables and currencies in variables, and performs the required conversion.
// it's void function so it will print massage and result of the conversion process.

void ExchangeCurrency (string uCurr1 , string uCurr2 ) {
    double fvalue1 , fvalue2 , valuesEnter ;
    string fcurr1 , fcurr2 ;
    cout << "How much money you want to exchange? "<<endl;
    cin >> valuesEnter ;
    ifstream file ;
    file.open("ExchangeRate.txt");
    while ( file >> fvalue1 >> fcurr1 >> fvalue2 >> fcurr2 ) {
       if ( uCurr1 == fcurr1 && uCurr2==fcurr2 )
          cout << valuesEnter << " " << fcurr1 << " is "<<(valuesEnter*fvalue2)<<" "<<fcurr2<<endl;

       else if (uCurr1==fcurr2 && uCurr2 == fcurr1)
          cout << valuesEnter<< " "<< fcurr2 <<" is "<<(valuesEnter/fvalue2)<<" "<<fcurr1<<endl;
   }
   }