#define BUILDING_NODE_EXTENSION

#include <node.h>
#include <string>
#include <iostream>
#ifdef WIN32
  #include <regex>
#else
  #include <regex.h>
#endif


#include "SimpleFilter.h"

using namespace v8;

namespace xssStr {


	
	 std::string lt="<";
	 std::string ltd="&lt;";

	 std::string gt=">";
	 std::string gtd="&gt;";

     std::string quotes = "\'";
	 std::string quotesd = "&#146;";

     std::string dquotes = "\"";
	 std::string dquotesd="&quot;";

	 std::string amp="&";
	 std::string ampd="&amp;";

}


  v8::Handle<v8::Value> SimpleF::trim(const v8::Arguments& args){
	  HandleScope scope;
	  if(!(args[0]->IsString())){
		ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
	  }
	  std::string s;
	  toCString(s, args[0]);
	  if(s.size() != 0){
		  if(args[1]->IsString()){
				std::string fs;
				toCString(fs, args[1]);
				rTrimString(s, fs);
				lTrimString(s, fs);
			}
			else{
				rTrimString(s);
				lTrimString(s);
			}
			
	  }	 
	  const char *sp = s.c_str();
	  return scope.Close(String::New(sp));
	  
  };



  v8::Handle<v8::Value> SimpleF::ltrim(const v8::Arguments& args){
	  HandleScope scope;
	  if(!(args[0]->IsString())){
		ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
	  }
	  std::string s;
	  toCString(s, args[0]);
	  if(s.size() != 0){
			 if(args[1]->IsString()){
				std::string fs;
				toCString(fs, args[1]);
				lTrimString(s, fs);
			}
			else lTrimString(s);
	  }	 
	  const char *sp = s.c_str();
	  return scope.Close(String::New(sp));
	  
  };



  v8::Handle<v8::Value> SimpleF::rtrim(const v8::Arguments& args){
	  HandleScope scope;
	  if(!(args[0]->IsString())){
		ThrowException(Exception::TypeError(String::New("Wrong arguments")));
        return scope.Close(Undefined());
	  }
	  std::string s;
	  toCString(s, args[0]);
	  if(s.size() != 0){
		    if(args[1]->IsString()){
				std::string fs;
				toCString(fs, args[1]);
				rTrimString(s, fs);
			}
			else rTrimString(s);
			
	  }	 
	  const char *sp = s.c_str();
	  return scope.Close(String::New(sp));
	  
  };

  v8::Handle<v8::Value> SimpleF::toXss(const v8::Arguments& args){//js simple xss
	  HandleScope scope;
	  using namespace xssStr;
	  if(!(args[0]->IsString())){
		  ThrowException(Exception::TypeError(String::New("Wrong arguments")));
          return scope.Close(Undefined());
	  }
	  std::string s;
	  toCString(s, args[0]);

	 // std::string* sp = &s;
	  //std::cout<<s<<"  "<<std::endl;
	  //sp = CSreplace(sp, &amp, &ampd);
	  //sp = CSreplace(sp, &lt, &ltd);
	  //sp = CSreplace(sp, &gt, &gtd);
	  //sp = CSreplace(sp, &quotes, &quotesd);
	  //sp = CSreplace(sp, &dquotes, &dquotesd);

	  CSreplace(s, amp, ampd);
      CSreplace(s, lt, ltd);
	  CSreplace(s, gt, gtd);
	  CSreplace(s, quotes, quotesd);
	  CSreplace(s, dquotes, dquotesd);
	  
      const char *sp = s.c_str();
	  return scope.Close(String::New(sp));
   }


   v8::Handle<v8::Value> SimpleF::replace(const v8::Arguments& args){//js replace
	  /*
	  HandleScope scope;
	  
	  if(!(args[0]->IsString()) || !(args[1]->IsString()) || !(args[2]->IsString())){
		  ThrowException(Exception::TypeError(String::New("Wrong arguments")));
          return scope.Close(Undefined());
	  }

	   
	   char *s = *String::Utf8Value(args[0]);//toCString(args[0]);
	   char *p = *String::Utf8Value(args[1]);// toCString(args[1]);
	   char *d = *String::Utf8Value(args[2]);// toCString(args[2]);
	   char *sp = 0;
	   if(args[3]->IsInt32()){
			int n = args[3]->Int32Value();
			//sp = xssStr::replace(s, p, d);
	   }
	   else{
			//sp = xssStr::replace(s, p, d);
	   }

	  return scope.Close(String::New(""));
	  */
   }





  void SimpleF::lTrimString(std::string& s,const std::string& filters){
	  s.erase(0,s.find_first_not_of(filters));
  };
  void SimpleF::rTrimString(std::string& s,const std::string& filters){
	  s.erase(s.find_last_not_of(filters)+1);
  };


  

void SimpleF::CSreplace(std::string& s1,std::string& s2,std::string& s3)
{
	std::string::size_type pos=0;
	std::string::size_type a=s2.size();
	std::string::size_type b=s3.size();


		while((pos=s1.find(s2,pos))!=std::string::npos)
		{
			s1.replace(pos,a,s3);
			pos+=b;
		}

}


std::string* SimpleF::CSreplace(std::string* s1,std::string* s2,std::string* s3)
{
	std::string::size_type pos=0;
	std::string::size_type a=s2->size();
	std::string::size_type b=s3->size();


		while((pos=s1->find(*s2,pos))!=std::string::npos)
		{
			s1->replace(pos,a,*s3);
			pos+=b;
		}
	return s1;
}
 

inline void SimpleF::toCString(std::string& str, Handle<Value> strp){
      String::Utf8Value utf8_value(strp->ToString());//转化成v8::Utf8Value
      str = *utf8_value;//转化为string
}




SimpleF::SimpleF() {};
SimpleF::~SimpleF() {};

void SimpleF::show(){}