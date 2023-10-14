#include <nan.h>
// #include "./deps/ada/ada.h"
// #include "./deps/ada/ada.cpp"
#include "url.h"

NAN_METHOD(parse) {
    if (info.Length() < 1) {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }
    auto str = info[0]->IsUndefined() ? "" : *Nan::Utf8String(info[0]);

    auto url = ada::parse<ada::url>(str);
    if (!url) {
        info.GetReturnValue().Set(Nan::New("").ToLocalChecked());
        return;
    }

    auto hostname = url->get_hostname();
    info.GetReturnValue().Set(Nan::New(hostname).ToLocalChecked());
}



NAN_MODULE_INIT(init) {
    URL::Init(target);
    // Nan::Set(target, Nan::New("parse").ToLocalChecked(),
    //     Nan::GetFunction(Nan::New<v8::FunctionTemplate>(parse)).ToLocalChecked());
}

NODE_MODULE(hello, init)