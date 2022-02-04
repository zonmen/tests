#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include "include/hello.hpp"


//using namespace std;

void print_hello (void){
      

	
        for (int i=0; i<10; i++){
	
	    std::cout<<"Hello world!\n";
	}


               
	std::ofstream fout("filename.txt");
	
	if(!fout.is_open()){
	
		std::cout<<"mistake in opening the file\n";
	
	} else{

	
		std::cout<<"filename.txt has been successfully created, you can check it out in your current directory\n";
		
	   }
	   
	int i=0;
       
        while (i<10){

       	 fout<<"Hello world!\n";
       	 i++;

         }



	fout.close();
	
	}
          


void print_arg(const std::string& str) {
      
                int i=0;
                std::cout<<"Output text as argument\n";
     		 while (i<10){
          	 std::cout << str<<std::endl;
          	 i++;
             }  

		
		      
		std::ofstream fout("filename2.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename2.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       
	       
	       for(int i=0; i<10; i++){
                        
                        
	       	 fout << str <<std::endl;
	       	 

		 }

              

		fout.close();          

	      } 
	      
	      
	



void print_arg2(const std::string& str1, const std::string& str2) {
      
                int i=0;
                std::cout<<"Output text as argument\n";
     		 while (i<10){
          	 std::cout << str1<<std::endl;
          	 std::cout << str2<<std::endl;
          	 i++;
             }  

		
		      
		std::ofstream fout("filename3.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename2.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       
	       
	       for(int i=0; i<10; i++){
                        
                        
	       	 fout << str1<<std::endl;
	       	 fout << str2<<std::endl;

		 }

               

		fout.close();          

	      } 	
	      
	      
	      
	      
	      
	      
	      void print_arg3(const std::string& str3) {
      
                /*int i=0;
                std::cout<<"Output text as argument\n";
     		 while (i<10){
          	 std::cout << str3<<std::endl;
          	 i++;
             }  */

		
		      
		std::ofstream fout("filename4.txt");
		
		if(!fout.is_open()){
		
			std::cout<<"mistake in opening the file\n";
		
		} else{

		
			std::cout<<"filename4.txt has been successfully created, you can check it out in your current directory\n";
			
		   }
	       
		
	       
	       
	       
	       
	       int num=0;
	       
	       std::cout<<"the program will be finished after five iterations"<<std::endl;
	       
	       while(true){
                        
                        std::cout << str3 <<std::endl;
                        
	       	 fout << str3 <<std::endl;
	       	 
	       	 
	       	 
	       	 num++;
	       	 
	       	 if(num==5){
	       	 
	       	    fout.close();
	       	    
	       	    break;        
	       	 }
	       	 
	       	 sleep(5);

		 }

    
		    

	      } 
	      
	      
	      
