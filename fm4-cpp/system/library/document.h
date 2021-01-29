#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio2.h>

using namespace std;

void startWriting()
{
	// variables
    bool a;
    ofstream writefile;
    int i = 0;
    int z;
    const string saveFiley = "y";
    const string saveFileY = "Y";
    const string shelltype = ">";
    char saveYN[20];
    string x;
    char textWrite[255];
    string textSave[1024];
    string exitcode = ">DONE<";
    // starting program
    while(true)
    {
    	// writing here
        cout<<shelltype<<" ";
        fflush(stdin);cin.get(textWrite,255);
        // checking if user is want to exit or not
        if(textWrite!=exitcode)
        {
            textSave[i] = textWrite;
            i++; // saving file to the memory
        }
        else
        {
        	// prompting user to checking if user want to save the current file or not
        	cout<<"save your file ? [y] to save : ";
        	fflush(stdin);cin.get(saveYN,16);
        	// checking yes or not
        	// if .. yes ->
        	if(saveYN==saveFiley||saveYN==saveFileY){
        		char filename[255];
            	cout<<"Enter Filename : ";
				fflush(stdin);cin.get(filename,255); // file name input
            	writefile.open(filename,ios::app); // open the file
            	// writing text to the file
            	for(z=0;z<=i;z++)
            	{
                	writefile<<textSave[z]<<endl; // writing the file
            	}
            	writefile.close(); // closing the file
            	break;	
			}
			else{
				break;
			}
        }
    }
}
