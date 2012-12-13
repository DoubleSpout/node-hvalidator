#ifndef SV_H
#define SV_H
#include <node.h>
#include <string>
#ifdef WIN32
  #include <regex>
#else
  #include <regex.h>
#endif

class SimpleV {
 public:
  static v8::Handle<v8::Value> isArray(const v8::Arguments& args);
  static v8::Handle<v8::Value> isRegExp(const v8::Arguments& args);
  static v8::Handle<v8::Value> isNumber(const v8::Arguments& args);
  static v8::Handle<v8::Value> isPositive(const v8::Arguments& args);
  static v8::Handle<v8::Value> isInt(const v8::Arguments& args);
  static v8::Handle<v8::Value> notEmpty(const v8::Arguments& args);
  static v8::Handle<v8::Value> isNull(const v8::Arguments& args);
  static v8::Handle<v8::Value> notNull(const v8::Arguments& args);
  static v8::Handle<v8::Value> isLowercase(const v8::Arguments& args);
  static v8::Handle<v8::Value> isUppercase(const v8::Arguments& args);
  static v8::Handle<v8::Value> isIn(const v8::Arguments& args);
  static v8::Handle<v8::Value> isString(const v8::Arguments& args);
  static v8::Handle<v8::Value> isLen(const v8::Arguments& args);
  static v8::Handle<v8::Value> isAlpha(const v8::Arguments& args);
  static v8::Handle<v8::Value> isAlphanumeric(const v8::Arguments& args);

  
  static v8::Handle<v8::Value> isDate(const v8::Arguments& args);
  static v8::Handle<v8::Value> isBefore(const v8::Arguments& args);
  static v8::Handle<v8::Value> isAfter(const v8::Arguments& args);
  static v8::Handle<v8::Value> isEmail(const v8::Arguments& args);
  static v8::Handle<v8::Value> isIp(const v8::Arguments& args);
  static v8::Handle<v8::Value> isUrl(const v8::Arguments& args);

  static void show();
  
 protected:
  static std::string toCString(v8::Handle<v8::Value> strp);
  static int match(std::string& str,std::string& part,int flag=0);

 private:
  SimpleV();
  ~SimpleV();
  
};

#endif