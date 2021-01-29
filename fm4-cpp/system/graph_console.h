/*
 * graph_console.h header file for Food Market Software
 * company : ifoodsoft computers
 * filename : graph_console.h
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// function prototype
void create_title(string title_text,string title_line,int adds);
void create_start_press(string programName);

// title layout
void create_title(string title_text,string title_line,int adds)
{
    // creating layout
    string code_line = title_line;
    string code_text = title_text;
    int code_text_len = code_text.length();
    int code_adds = adds;
    int code_adds_up_down = adds + 2 + code_text_len;
    int i;
    for(i=0;i<code_adds;i++)
    {
        cout<<code_line;
    }
    for(i=0;i<code_adds_up_down;i++)
    {
        cout<<code_line;
    }
    cout<<endl;
    for(i=0;i<code_adds;i++)
    {
        cout<<code_line;
    }
    cout<<" "<<code_text<<" ";
    for(i=0;i<code_adds;i++)
    {
        cout<<code_line;
    }
    cout<<endl;
    for(i=0;i<code_adds;i++)
    {
        cout<<code_line;
    }
    for(i=0;i<code_adds_up_down;i++)
    {
        cout<<code_line;
    }
    cout<<endl;
}
