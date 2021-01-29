/*
 * boot.h
 * header file for Food Market Software
 * company : ifoodsoft computers
 * filename : boot.h
 */

#include <iostream>
#include <cstdlib>

// defining memory size
#define MVMCN 16
#define MVALN 256
#define MVALM 1024
#define MAPPM 16

using namespace std;

// function prototype
void bootps(string cmstr);
void bootpsn();
void bootcls();
int checkzero(int value);
void sendError(string error);
void create_start_press(string programName);
void file_not_found(string filename);

// checking file
void file_not_found(string filename){
	cout<<endl<<"File "<<filename<<" not found! . .. "<<endl;
}
// checking number
int checkzero(int value){
	if(value<=0){
		return 0;
	}
	else{
		return value;
	}
}
// console pause
void bootps(string cmstr){
    cout<<cmstr;
    system("pause>nul");
}

// console pause with no message
void bootpsn(){
	system("pause>nul");
}

// clearing screen
void bootcls(){
    system("cls"); // clearing screen
}

// error message
void sendError(string errorType){
	bootcls();
	cout<<"Error "<<errorType<<" . . ."<<endl;
	bootpsn();
	bootcls();
}

// press any key to start the program . . . .
void create_start_press(string programName){
	cout<<"Press any key to start "<<programName<<" program . . . ";  
	bootpsn();
}
