/**
 * Time.cpp
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;

Time::Time( )
{
   seconds = 0;
}

Time::Time( int _seconds )
{
   seconds = _seconds;
}

Time::Time( string t )
{
   setTime( t );
}

Time Time::add( Time t )
{
   return seconds += t.seconds;
}

Time Time::subtract( Time t )
{
   return seconds -= t.seconds;
}

std::string Time::str() const
{
   /* Use ostringstream to convert from int to string. This will be covered in
    * detail in week 8
    */
   ostringstream oss;
   oss << seconds / 3600 << ":" << setfill('0') << setw(2) << ( seconds % 3600 ) / 60;
   return oss.str();
}

void Time::setTime( std::string t )
{
   /* Your code here */
 
  for(int i=0; i<t.length(); i++)
  {
    bool found=false;
    if(t[i]==':')
    {
	  found= true;
      int hrs=0;
      int sec=0;
      hrs=atoi( (t.substr( 0, i)).c_str() ) * 60 * 60;
      seconds+=hrs;
      sec=atoi( (t.substr( i+1, t.length()-i+1)).c_str() ) * 60;
      seconds+=sec;
      break;
    }
    else if(i==t.length()-1 && !found)
    {
	  seconds+=atoi( t.c_str() ) * 3600;
	  break;
    }
  }
}
