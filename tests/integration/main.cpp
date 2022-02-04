#include "include/hello.hpp"
#include <string>
#include <iostream>

using namespace std;

   int main (int argc, char *argv[]){
   


	print_hello();
	
	
	
	
        cout << "Output some text to stdout and file: "<<endl;
	string str;
	cout << "Enter some text: "<<endl;
	getline(cin, str);
	print_arg(str);
	
	
	cout << "Now output text1 and text2 to stdout and file: "<<endl;
	cout << "Enter some text: "<<endl;
	string str1;
	getline(cin, str1);
	
	cout<<endl;
	
        string str2;
	getline(cin, str2);
	
        print_arg2(str1, str2);
	
	
	
	cout<<endl;
	
        cout << "Now output some text in infinite loop to stdout and file with interval 5 seconds: "<<endl;
	string str3;
	cout << "Enter some text: "<<endl;
	getline(cin, str3);
	print_arg3(str3);
	
	cout<<endl;
	
	return 0;

}
