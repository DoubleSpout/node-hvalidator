#define BUILDING_NODE_EXTENSION

#include <node.h>
#include <string>
#include <iostream>
#ifdef WIN32
  #include <regex>
#else
  #include <regex.h>
#endif


#include "SimpleVerify.h"

using namespace v8;

SimpleV::SimpleV() {};
SimpleV::~SimpleV() {};


Handle<Value> SimpleV::isArray(const Arguments& args) {//是否是数组
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsArray()));
}


Handle<Value> SimpleV::isNumber(const Arguments& args) {//是否是数字
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsNumber()));
}

Handle<Value> SimpleV::isRegExp(const Arguments& args) {//是否是数字
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsRegExp()));
}

Handle<Value> SimpleV::isPositive(const Arguments& args) {//是否是数字,并且大于0
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsNumber() && (args[0]->NumberValue()>0) ));
}


Handle<Value> SimpleV::isInt(const Arguments& args) {//是否是整数
  HandleScope scope;
  return scope.Close(Boolean::New(int(args[0]->NumberValue()) == args[0]->NumberValue() ));
}

Handle<Value> SimpleV::isString(const Arguments& args) {//是否是整数
  HandleScope scope;
  return scope.Close(Boolean::New(int(args[0]->IsString())));
}

Handle<Value> SimpleV::isNull(const Arguments& args) {//是否是null或者undefined
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsNull() || args[0]->IsUndefined()));
}

Handle<Value> SimpleV::notNull(const Arguments& args) {//是否不是null而且不是undefined
  HandleScope scope;
  return scope.Close(Boolean::New(!(args[0]->IsNull()) && !(args[0]->IsUndefined())));
}


Handle<Value> SimpleV::notEmpty(const Arguments& args) {//是否为空
  HandleScope scope;
  if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  std::string s = toCString(args[0]);;
  return scope.Close(Boolean::New(s!=""));
}



Handle<Value> SimpleV::isLowercase(const Arguments& args) {//是否全部为小写字母
  HandleScope scope;
  if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  std::string str = toCString(args[0]);;
  int size = str.size();
  for ( int ix = 0; ix < size; ix++ ){
        if(str[ix]>='A' && str[ix]<='Z'){
            return scope.Close(Boolean::New(0));
         }
  }
  return scope.Close(Boolean::New(1));
}

Handle<Value> SimpleV::isUppercase(const Arguments& args) {//是否全部为大写字母
  HandleScope scope;
  if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  std::string str =  toCString(args[0]);;
  int size = str.size();
  for ( int ix = 0; ix < size; ix++ ){
        if(str[ix]>='a' && str[ix]<='z'){
            return scope.Close(Boolean::New(0));
         }
  }
  return scope.Close(Boolean::New(1));
}

Handle<Value> SimpleV::isIn(const Arguments& args) {//是否存在在这个string或者array里
  HandleScope scope;
  if((args[0]->IsString()||args[0]->IsNumber())&& args[1]->IsString()){
        std::string str1 = toCString(args[0]);
        std::string str2 =  toCString(args[1]);
        std::string::size_type loc = str2.find(str1,0);//查找字符串
        if( loc != std::string::npos ) return scope.Close(Boolean::New(1));//如果不是返回npos，则返回true
        else return scope.Close(Boolean::New(0));
  }
  else if((args[0]->IsString()||args[0]->IsNumber()) && args[1]->IsArray()){
        std::string str1 = toCString(args[0]);
        int length = 0;
        Local<Object> obj;
        obj = args[1]->ToObject();
        length = obj->Get(String::New("length"))->ToObject()->Uint32Value();
        for(int i = 0; i < length; i++){
        std::string str2 = toCString(obj->Get(i));
            if(str1 == str2) return scope.Close(Boolean::New(1));
        }
         return scope.Close(Boolean::New(0));
  }
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
}


Handle<Value> SimpleV::isLen(const Arguments& args) {//判断字符串或者数组长度
  HandleScope scope;
  if(!(args[1]->IsNumber()) || !(args[2]->IsNumber())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  bool isStr,isArr,isNum;
  isStr = args[0]->IsString();
  isArr = args[0]->IsArray();
  isNum = args[0]->IsNumber();
  if(!isStr && !isArr && !isNum){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
   }
   int min,max,len=0;
   min = int(args[1]->NumberValue());
   max = int(args[2]->NumberValue());
   if(isStr){
         len = toCString(args[0]).size();
   }
   else if(isNum){
        len = int(args[0]->NumberValue());
   }
   else {
        len = args[0]->ToObject()->Get(String::New("length"))->ToObject()->Uint32Value();
     }
   return (len>=min && len<=max)? scope.Close(Boolean::New(1)) :  scope.Close(Boolean::New(0));
}



Handle<Value> SimpleV::isDate(const Arguments& args) {//是否是日期格式
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsDate()));
}

Handle<Value> SimpleV::isAfter(const Arguments& args) {//是否是日期格式
  HandleScope scope;
   if(!(args[0]->IsDate()) && !(args[1]->IsDate())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  double ts1,ts2;
  ts1 = args[0]->NumberValue();
  ts2 = args[1]->NumberValue();
  return scope.Close(Boolean::New(ts1>ts2));
}

Handle<Value> SimpleV::isBefore(const Arguments& args) {//是否是日期格式
  HandleScope scope;
     if(!(args[0]->IsDate()) && !(args[1]->IsDate())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  double ts1,ts2;
  ts1 = args[0]->NumberValue();
  ts2 = args[1]->NumberValue();
  return scope.Close(Boolean::New(ts1<ts2));
}

Handle<Value> SimpleV::is(const Arguments& args) {//利用正则表达式判断
  HandleScope scope;
     if(!(args[1]->IsRegExp()) && (!(args[0]->IsString())&&!(args[0]->IsNumber()))){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  std::string str = toCString(args[0]);
  std::string strReg,strFlag;
  String::Utf8Value strRegU(Local<RegExp>::Cast(args[1])->GetSource());
  strReg = *strRegU;
  //int flag;
  //flag = int(Local<RegExp>::Cast(args[1])->GetFlags());
  int result = match(str, strReg);
  if(result == 3){
         ThrowException(Exception::TypeError(String::New("compile regex error")));
         return scope.Close(Undefined());
  }
  return scope.Close(Boolean::New(result));
}


Handle<Value> SimpleV::isEmail(const Arguments& args) {//是否是日期格式
  HandleScope scope;
   if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  
  std::string email = "[_\\.0-9a-z-]+@([0-9a-z][0-9a-z-]+\\.)+[a-z]{2,3}$";
  std::string str = toCString(args[0]);
  int result = match(str, email);
  if(result == 3){
         ThrowException(Exception::TypeError(String::New("compile regex error")));
         return scope.Close(Undefined());
  }
   return scope.Close(Boolean::New(result));
}


Handle<Value> SimpleV::isIp(const Arguments& args) {//是否是日期格式
  HandleScope scope;
   if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  
  std::string ip = "^(25[0-4]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[1-9])[.](25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[.](25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[.](25[0-4]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[1-9])$";
  std::string str = toCString(args[0]);
  int result = match(str, ip);
  if(result == 3){
         ThrowException(Exception::TypeError(String::New("compile regex error")));
         return scope.Close(Undefined());
  }
   return scope.Close(Boolean::New(result));
}

Handle<Value> SimpleV::isUrl(const Arguments& args) {//是否是日期格式
  HandleScope scope;
   if(!(args[0]->IsString())){
     ThrowException(Exception::TypeError(String::New("Wrong arguments")));
     return scope.Close(Undefined());
  }
  
  std::string url = "[a-zA-z]+://[^\\s]*";
  std::string str = toCString(args[0]);
  int result = match(str, url);
  if(result == 3){
         ThrowException(Exception::TypeError(String::New("compile regex error")));
         return scope.Close(Undefined());
  }
   return scope.Close(Boolean::New(result));
}



std::string SimpleV::toCString(Handle<Value> strp){
     String::Utf8Value utf8_value(strp->ToString());//转化成v8::Utf8Value
      std::string str = *utf8_value;//转化为string
      return str;
}

#ifdef WIN32
  int SimpleV::match(std::string& str,std::string& part,int flag){
    std::regex pattern(part,std::regex_constants::extended);
    std::match_results<std::string::const_iterator> result;
    bool valid = std::regex_match(str,result,pattern);
    return valid?0:1;
}

#else
  int SimpleV::match(std::string& str,std::string& part,int flag){
    regex_t preg;
    const char *buf = (char *)str.c_str();
    const char *regex = (char *)part.c_str();

    if (regcomp(&preg, regex, REG_EXTENDED|REG_NOSUB)) {//编译正则表达式失败
        return 3;
    }

    int z;
    const size_t nmatch = 1;
    regmatch_t pm[nmatch];
    z = regexec(&preg, buf, nmatch, pm, 0);
    regfree(&preg);//释放正则表达式
    return z == REG_NOMATCH ? 0:1;
}
#endif




void SimpleV::show(){
}