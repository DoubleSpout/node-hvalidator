#ifndef SF_H
#define SF_H
#include <node.h>
#include <string>
#ifdef WIN32
  #include <regex>
#else
  #include <regex.h>
#endif

class SimpleF {
 public:
  static v8::Handle<v8::Value> trim(const v8::Arguments& args);
  static v8::Handle<v8::Value> ltrim(const v8::Arguments& args);
  static v8::Handle<v8::Value> rtrim(const v8::Arguments& args); 
  static v8::Handle<v8::Value> toXss(const v8::Arguments& args);
  static v8::Handle<v8::Value> replace(const v8::Arguments& args);
  static void show();
  
 protected:
  static void toCString(std::string& str, v8::Handle<v8::Value> strp);
  static void lTrimString(std::string& str,const std::string& filters = "\r\t\n ");
  static void rTrimString(std::string& str,const std::string& filters = "\r\t\n ");
  static void CSreplace(std::string& s1, std::string& s2, std::string& s3);
  static std::string* CSreplace(std::string* s1,std::string* s2,std::string* s3);


 private:
  SimpleF();
  ~SimpleF();
  
};

#endif