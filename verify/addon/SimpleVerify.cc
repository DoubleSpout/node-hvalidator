#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "SimpleVerify.h"

using namespace v8;

SimpleV::SimpleV() {};
SimpleV::~SimpleV() {};

Handle<Value> SimpleV::isArray(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Boolean::New(args[0]->IsArray()));
}

void SimpleV::show(){
}