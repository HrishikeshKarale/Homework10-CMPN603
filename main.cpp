/**
 * main.cpp
 * Homework 2
 * fall 2014
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Hrishikesh Karale (hhk9433)
 */
#include "Time.h"
#include <iostream>

using namespace std;

/* Your code here */

int main()
{
  std::string strr;
  std::string time_out;
  Time *time(0);
  /* Your code here */
  do
  {
  	time= new Time(0);
    //bool variable stores false for subtraction and true for addition.
  	bool sign = true;
  	int counter = 0;
    int start = 0;
    getline( cin, strr );

    for(int i=0;i<strr.length(); i++)
    {
    	if(strr[i]=='+')
    	{
    		if(start==0)
    		{
    			time->setTime(strr.substr(0, i));
    			start=i+1;
    		}
    		else
    		{
    			Time *time_object= new Time(strr.substr(start, (i-start)));
    			start = i+1;
    			if(sign)
    			{
    				time->add(*time_object);
    			}
    			else
    			{
    				time->subtract(*time_object);
    			}
    		}
			sign= true;
    	}
    	else if(strr[i]=='-')
    	{
    		if(start==0)
    		{
    			time->setTime(strr.substr(0, i));
    			start = i+1;
    		}
    		else
    		{
    			Time *time_object= new Time(strr.substr(start, (i-start)));
    			start = i+1;
    			if(sign)
    			{
    				time->add(*time_object);
    			}
    			else
    			{
    				time->subtract(*time_object);
    			}
    		}
			sign=false;
    	}
    	else if(i==strr.length()-1)
    	{
    		Time *time_object= new Time(strr.substr(start, (i-start+1)));
    		if(start==0 || sign)
    		{
    			time->add(*time_object);
    		}
    		else
    		{
    			time->subtract(*time_object);
    		}
    	}
	  }
    time_out = time->str();
    cout<< time_out<< endl;
  } while ( !cin.eof() );
  return 0;
}