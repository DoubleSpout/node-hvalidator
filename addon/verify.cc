#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "SimpleVerify.h"
using namespace v8;



void Init(Handle<Object> target) {
  target->Set(String::NewSymbol("is"),
           FunctionTemplate::New(SimpleV::is)->GetFunction());
  target->Set(String::NewSymbol("isArray"),
           FunctionTemplate::New(SimpleV::isArray)->GetFunction());
  target->Set(String::NewSymbol("isNumber"),
           FunctionTemplate::New(SimpleV::isNumber)->GetFunction());
  target->Set(String::NewSymbol("isRegExp"),
           FunctionTemplate::New(SimpleV::isRegExp)->GetFunction());
  target->Set(String::NewSymbol("isPositive"),
           FunctionTemplate::New(SimpleV::isPositive)->GetFunction());
  target->Set(String::NewSymbol("isInt"),
           FunctionTemplate::New(SimpleV::isInt)->GetFunction());
  target->Set(String::NewSymbol("isString"),
           FunctionTemplate::New(SimpleV::isString)->GetFunction());
  target->Set(String::NewSymbol("notEmpty"),
           FunctionTemplate::New(SimpleV::notEmpty)->GetFunction());
  target->Set(String::NewSymbol("isNull"),
           FunctionTemplate::New(SimpleV::isNull)->GetFunction());
  target->Set(String::NewSymbol("notNull"),
           FunctionTemplate::New(SimpleV::notNull)->GetFunction());
  target->Set(String::NewSymbol("isLowercase"),
           FunctionTemplate::New(SimpleV::isLowercase)->GetFunction());
  target->Set(String::NewSymbol("isUppercase"),
           FunctionTemplate::New(SimpleV::isUppercase)->GetFunction());
   target->Set(String::NewSymbol("isIn"),
           FunctionTemplate::New(SimpleV::isIn)->GetFunction());
   target->Set(String::NewSymbol("isLen"),
           FunctionTemplate::New(SimpleV::isLen)->GetFunction());


  target->Set(String::NewSymbol("isDate"),
           FunctionTemplate::New(SimpleV::isDate)->GetFunction());
  target->Set(String::NewSymbol("isBefore"),
           FunctionTemplate::New(SimpleV::isBefore)->GetFunction());
  target->Set(String::NewSymbol("isAfter"),
           FunctionTemplate::New(SimpleV::isAfter)->GetFunction());
  target->Set(String::NewSymbol("isEmail"),
           FunctionTemplate::New(SimpleV::isEmail)->GetFunction());
  target->Set(String::NewSymbol("isIp"),
           FunctionTemplate::New(SimpleV::isIp)->GetFunction());
  target->Set(String::NewSymbol("isUrl"),
           FunctionTemplate::New(SimpleV::isUrl)->GetFunction());
}

NODE_MODULE(verify, Init)