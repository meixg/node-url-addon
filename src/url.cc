#include "url.h"
#include <string>
#include "./deps/ada/ada.h"
#include "./deps/ada/ada.cpp"

using std::string;

URL::URL(string str) {
    this->url = ada::parse<ada::url>(str);

    if (!this->url) {
        Nan::ThrowError("Invalid URL");
    }
}

NAN_GETTER(URL::GetHostname) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto hostname = url->url->get_hostname();
    info.GetReturnValue().Set(Nan::New(hostname).ToLocalChecked());
}
NAN_SETTER(URL::SetHostname) {
    string hostname = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_hostname(hostname);
    info.GetReturnValue().Set(Nan::New(hostname).ToLocalChecked());
}

// URL::GetHostname(Nan::NAN_GETTER_ARGS_TYPE info) {
//     URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
//     auto hostname = url->url->get_hostname();
//     info.GetReturnValue().Set(Nan::New(hostname).ToLocalChecked());
// }

void URL::Init(v8::Local<v8::Object> exports) {
    v8::Local<v8::Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("URL").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetAccessor(
        tpl->InstanceTemplate(),
        Nan::New("hostname").ToLocalChecked(),
        GetHostname,
        SetHostname
    );

    exports->Set(context, Nan::New("URL").ToLocalChecked(), tpl->GetFunction(context).ToLocalChecked());
}

void URL::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.IsConstructCall()) {
        string str = info[0]->IsUndefined() ? "" : *Nan::Utf8String(info[0]);
        URL* url = new URL(str);
        url->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    }
    else {

    }
}