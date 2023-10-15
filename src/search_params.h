#ifndef SEARCH_PARAMS_H_
#define SEARCH_PARAMS_H_
#include "./deps/ada/ada.h"

#include <string>
#include <nan.h>

using std::string;

class SearchParams: public Nan::ObjectWrap {
    public:
        static void Init(v8::Local<v8::Object> exports);
        static Nan::Persistent<v8::Function> constructor;
        static NAN_METHOD(Append);
        static NAN_METHOD(ToString);
    private:
        explicit SearchParams(string str = "");
        static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
        ada::url_search_params searchParams;
};

#endif