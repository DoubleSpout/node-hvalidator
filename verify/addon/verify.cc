#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "SimpleVerify.h"
using namespace v8;



void Init(Handle<Object> target) {

  target->Set(String::NewSymbol("isArray"),
           FunctionTemplate::New(SimpleV::isArray)->GetFunction());
}

NODE_MODULE(verify, Init)