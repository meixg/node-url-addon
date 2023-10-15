#include "search_params.h"

using std::string;

Nan::Persistent<v8::Function> SearchParams::constructor;

SearchParams::SearchParams(string str) {
    ada::url_search_params search_params(str);
    this->searchParams = search_params;
}

NAN_METHOD(SearchParams::Append) {
    string name = *Nan::Utf8String(info[0]);
    string value = *Nan::Utf8String(info[1]);
    SearchParams* searchParams = ObjectWrap::Unwrap<SearchParams>(info.Holder());
    searchParams->searchParams.append(name, value);
    info.GetReturnValue().Set(Nan::New(value).ToLocalChecked());
}
NAN_METHOD(SearchParams::ToString) {
    SearchParams* searchParams = ObjectWrap::Unwrap<SearchParams>(info.Holder());
    auto str = searchParams->searchParams.to_string();
    info.GetReturnValue().Set(Nan::New(str).ToLocalChecked());
}

void SearchParams::Init(v8::Local<v8::Object> exports) {
    v8::Local<v8::Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("SearchParams").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "append", Append);
    Nan::SetPrototypeMethod(tpl, "toString", ToString);

    constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
    exports->Set(context, Nan::New("SearchParams").ToLocalChecked(), tpl->GetFunction(context).ToLocalChecked());
}

void SearchParams::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
    if (info.IsConstructCall()) {
        string str = *Nan::Utf8String(info[0]);
        SearchParams* searchParams = new SearchParams(str);
        searchParams->Wrap(info.This());

        info.GetReturnValue().Set(info.This());
    }
    else {
        Nan::ThrowError("Must be called as a constructor");
    }
}
