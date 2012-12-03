#ifndef SV_H
#define SV_H
#include <node.h>

class SimpleV {
 public:
  static v8::Handle<v8::Value> isArray(const v8::Arguments& args);
  static void show();

 private:
  SimpleV();
  ~SimpleV();
};

#endif