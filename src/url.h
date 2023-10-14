#ifndef URLOBJECT_H
#define URLOBJECT_H

#include <nan.h>
#include <string>
#include "./deps/ada/ada.h"

using std::string;

class URL: public Nan::ObjectWrap {
    public:
        static void Init(v8::Local<v8::Object> exports);
        static NAN_GETTER(GetHostname);
        static NAN_SETTER(SetHostname);
    private:
        explicit URL(string str = "");
        static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
        ada::result<ada::url> url;

};
#endif