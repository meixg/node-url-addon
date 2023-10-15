#ifndef URLOBJECT_H
#define URLOBJECT_H

#include <nan.h>
#include <string>
#include "./deps/ada/ada.h"
// #include "./search_params.h"

using std::string;

class URL: public Nan::ObjectWrap {
    public:
        static void Init(v8::Local<v8::Object> exports);
        static NAN_GETTER(GetHash);
        static NAN_SETTER(SetHash);
        static NAN_GETTER(GetHost);
        static NAN_SETTER(SetHost);
        static NAN_GETTER(GetHostname);
        static NAN_SETTER(SetHostname);
        static NAN_GETTER(GetHref);
        static NAN_SETTER(SetHref);
        static NAN_GETTER(GetOrigin);
        static NAN_GETTER(GetPassword);
        static NAN_SETTER(SetPassword);
        static NAN_GETTER(GetPathname);
        static NAN_SETTER(SetPathname);
        static NAN_GETTER(GetPort);
        static NAN_SETTER(SetPort);
        static NAN_GETTER(GetProtocol);
        static NAN_SETTER(SetProtocol);
        static NAN_GETTER(GetSearch);
        static NAN_SETTER(SetSearch);
        static NAN_GETTER(GetUsername);
        static NAN_SETTER(SetUsername);
        // static NAN_GETTER(GetSearchParams);
    private:
        explicit URL(string str = "");
        static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
        ada::result<ada::url> url;

};
#endif