/*
 * boot.cpp
 * Food Market Software 4.0
 * company : ifoodsoft computers
 * filename : boot.cpp
 * header files : boot.h , graph_console.h
 *
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <conio2.h>
#include "system/library/document.h"
#include "system/boot.h"
#include "system/graph_console.h"

#define UIMMS 41989569
#define adds 5
#define currency "$" // currency for market apps

using namespace std;

// constants and variables
// system
char sys_input[MVALN];
const string COMPANY = "ifoodsoft computers"; // company name
const string SYSTYPE = "Library"; // system type
const string commandY = "y";
const string commandYUpper = "Y";
// BOOT
const string BOOTNAME = "Food Market"; // program name
const string BOOTVER = "4.0"; // program version
const string BOOTTYPE = "Software"; // program type
const string BOOTWELCOME = "Welcome to "+BOOTNAME+" "+BOOTTYPE; // welcome text
// Library
const string backTo = "Press any key to return to library . . .";
// if you add/remove something from this array, don't forget to change MAPPM in boot.h
const string apps[MAPPM] = {
    "Market","Cashier",
    "Price","Clock",
    "Calculator",
    "Document","Data",
    "Note","Task",
    "FMN","Char",
    "Reader","Files",
    "Personalize","About",
    "Close"
};
// app command
const string marketAppCommand = "1";
const string cashierAppCommand = "2";
const string priceAppCommand = "3";
const string clockAppCommand = "4";
const string calcAppCommand = "5";
const string documentAppCommand = "6";
const string commandExit = "15";

// app Event 
class AppEvent{
	public:
		// market program
		void marketStartProgram(){
			// variables
			const string appName = "Food Market";
			const string welcomeTitle = "Welcome to "+appName;
			char product[MVALN];
			int amount,total;
			unsigned long int price;
			// starting program
			bootcls();
			create_start_press(appName);
			bootcls();
			// starting market
			create_title(welcomeTitle,"=",adds); // creating title for program using create_title(title_text,title_line,adds) function from graph_console.h header file
			//getting user input
			// prompting user to ..
			cout<<"Product Name      : ";
			fflush(stdin);cin.getline(product,255); // enter product name
			cout<<"Product Price ("<<currency<<") : ";
			cin>>price; // enter product price
			cout<<"Amount            : ";
			cin>>amount; // enter amount of product
			cout<<endl<<endl;
			// proccessing
			price = checkzero(price);
			amount = checkzero(amount);
			total = price * amount;
			// output
			cout<<"Thank you for buying "<<product<<" at "<<appName<<" for "<<currency<<total<<endl<<endl;
			bootps(backTo);
		}
		// Cashier program
		void cashierStartProgram(){
			// variables
			const string appName = "Market Cashier";
			const string welcomeTitle = "Welcome to "+appName;
			char product[MVALN];
			const string line = "========================================";
			unsigned long int price,cash,total,change;
			int amount;
			const string filename = "cashier.txt";
			ofstream cwrite;
			// starting program
			bootcls();
			create_start_press(appName);
			bootcls();
			// starting cashier
			create_title(welcomeTitle,"=",adds);
			// getting user input
			cout<<"Product   : ";
			fflush(stdin);cin.getline(product,255); // enter product name
			cout<<"Price ("<<currency<<") : ";
			cin>>price; // enter product price
			cout<<"Amount    : ";
			cin>>amount; // enter amount of product
			cout<<line<<endl;
			// proccessing
			price = checkzero(price);
			amount = checkzero(amount);
			total = price * amount;
			cout<<"Buyer Cash ("<<currency<<") : ";
			cin>>cash;
			change = cash - total;
			cash = checkzero(cash);
			change = checkzero(change);
			//output
			cout<<line<<endl;
			cout<<"Product     : "<<product<<endl;
			cout<<"Price       : "<<currency<<price<<endl;
			cout<<"Amount      : "<<amount<<endl;
			cout<<"Total Price : "<<currency<<total<<endl;
			cout<<"Cash        : "<<currency<<cash<<endl;
			cout<<"Change 	   : "<<currency<<change<<endl;
			cout<<line<<endl<<endl;
			// writing file
			cwrite.open("cashier.txt",ios::app);
			if(!cwrite){
				file_not_found(filename);
			}
			else{
				// writing file to cashier.txt
				cwrite<<">> "<<product<<" <<"<<endl;
				cwrite<<"Product     : "<<product<<endl;
				cwrite<<"Price       : "<<currency<<price<<endl;
				cwrite<<"Amount      : "<<amount<<endl;
				cwrite<<"Total Price : "<<currency<<total<<endl;
				cwrite<<"Cash		 : "<<currency<<cash<<endl;
				cwrite<<"Change		 : "<<currency<<change<<endl<<endl;
				// closing file
				cwrite.close();
			}
			bootps(backTo);
		}
		// price program
		void priceStartProgram(){
			// variables
			const string appName = "Market Price";
			char product[MVALN];
			unsigned long int price;
			const string filename = "price.txt";
			ofstream pricewrite;
			// starting program
			bootcls();
			create_start_press(appName);
			bootcls();
			create_title(appName,"=",adds);
			// user input
			cout<<"Price ("<<currency<<") : ";
			cin>>price; // enter price
			cout<<"Price for product : ";
			fflush(stdin);cin.getline(product,255);
			// output
			cout<<currency<<price<<" for "<<product<<endl;
			pricewrite.open("price.txt",ios::app);
			// writing prices
			if(!pricewrite){
				file_not_found(filename);
			}
			else{
				pricewrite<<currency<<price<<" for "<<product<<endl;
				pricewrite.close();
				goto endpr;
			}
			endpr:
				bootps(backTo);
		}
		// clock program
		void clockStartProgram(){
			// variables
			const string appName = "clock";
			// starting clock program
			bootcls();
			create_start_press(appName);
			bootcls();
			// showing clock
			system("echo Date : %date%");
			system("echo Time : %time%");
			cout<<endl<<endl;
			bootps(backTo);
		}
		// food office
		// document
		void documentStartProgram(){
			// variables
			const string appName = "Food Document";
			const string appVer = "3.0";
			// starting program
			bootcls();
			create_start_press(appName);
			bootcls();
			// starting document writing
			create_title(appName+" "+appVer,"=",adds);
			cout<<"exit code : >DONE<"<<endl<<endl;
			startWriting();
			bootps(backTo);
		}
};

// main function
// the program starts here
int main(int argc, char *argv[]){
	textbackground(BLUE);
	textcolor(WHITE);
	clrscr();
	// app Object for library
	AppEvent AppEventObj; // defining AppEventObj as object of AppEvent class
	// welcome screen
	cout<<COMPANY<<endl<<endl;
	cout<<BOOTNAME<<" "<<BOOTVER<<endl<<endl;
	bootps("Press any key to start Food Market . . . ");
    // start label
    start:
        bootcls(); // clearing console
        // starting food market program
        int libraryAppNumbers = 1;
        int i;
        // title
        create_title(BOOTWELCOME,"=",adds); // title layout
        cout<<"Version "<<BOOTVER<<endl;
        system("echo %date% %time%");
        cout<<endl;
        // Library
        cout<<SYSTYPE<<endl;
        for(i=0;i<MAPPM;i++){
            cout<<libraryAppNumbers<<". "<<apps[i]<<endl; // printing all programs in library
            libraryAppNumbers++;
        }
        // user input and if statement
        cout<<"open > ";
        fflush(stdin);cin.getline(sys_input,255);
		if(sys_input==commandExit){ // exit command to exit program
			bootcls();
			string exitInputYN;
			cout<<"exit food market ? [y] to exit : "; // checking if user is wanted to exit or not
			fflush(stdin);cin>>exitInputYN;
			if(exitInputYN==commandY||exitInputYN==commandYUpper){
				system("exit");
			}
			else{
				goto start;
			}
		}
		else
		if(sys_input==marketAppCommand){
			// calling market program function from appEventObj Object
			AppEventObj.marketStartProgram();
			// return to library
			goto start;
		}
		else
		if(sys_input==cashierAppCommand){
			// calling cashier program function from appEventObj Object
			AppEventObj.cashierStartProgram();
			// return to library
			goto start;
		}
		else
		if(sys_input==priceAppCommand){
			// calling price program function from appEventObj Object
			AppEventObj.priceStartProgram();
			// return to library
			goto start;
		}
		else
		if(sys_input==clockAppCommand){
			// calling clock program function from appEventObj Object
			AppEventObj.clockStartProgram();
			// return to library
			goto start;
		}
		else
		if(sys_input==documentAppCommand){
			// calling clock program function from appEventObj Object
			AppEventObj.documentStartProgram();
			// return to library
			goto start;
		}
		else{
			sendError("not found");
			goto start;
		}
    return 0;
}
