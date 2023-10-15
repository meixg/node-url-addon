#include "url.h"
#include <string>
#include "./deps/ada/ada.cpp"

using std::string;

URL::URL(string str) {
    this->url = ada::parse<ada::url>(str);

    if (!this->url) {
        Nan::ThrowError("Invalid URL");
    }
}

NAN_GETTER(URL::GetHash) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto hash = url->url->get_hash();
    info.GetReturnValue().Set(Nan::New(hash).ToLocalChecked());
}
NAN_SETTER(URL::SetHash) {
    string hash = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_hash(hash);
    info.GetReturnValue().Set(Nan::New(hash).ToLocalChecked());
}
NAN_GETTER(URL::GetHost) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto host = url->url->get_host();
    info.GetReturnValue().Set(Nan::New(host).ToLocalChecked());
}
NAN_SETTER(URL::SetHost) {
    string host = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_host(host);
    info.GetReturnValue().Set(Nan::New(host).ToLocalChecked());
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
NAN_GETTER(URL::GetHref) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto href = url->url->get_href();
    info.GetReturnValue().Set(Nan::New(href).ToLocalChecked());
}
NAN_SETTER(URL::SetHref) {
    string href = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_href(href);
    info.GetReturnValue().Set(Nan::New(href).ToLocalChecked());
}
NAN_GETTER(URL::GetOrigin) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto origin = url->url->get_origin();
    info.GetReturnValue().Set(Nan::New(origin).ToLocalChecked());
}
NAN_GETTER(URL::GetPassword) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto password = url->url->get_password();
    info.GetReturnValue().Set(Nan::New(password).ToLocalChecked());
}
NAN_SETTER(URL::SetPassword) {
    string password = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_password(password);
    info.GetReturnValue().Set(Nan::New(password).ToLocalChecked());
}
NAN_GETTER(URL::GetPathname) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    std::string_view sv = url->url->get_pathname();
    string str(sv);
    info.GetReturnValue().Set(Nan::New(str).ToLocalChecked());
}
NAN_SETTER(URL::SetPathname) {
    string pathname = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_pathname(pathname);
    info.GetReturnValue().Set(Nan::New(pathname).ToLocalChecked());
}
NAN_GETTER(URL::GetPort) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto port = url->url->get_port();
    info.GetReturnValue().Set(Nan::New(port).ToLocalChecked());
}
NAN_SETTER(URL::SetPort) {
    string port = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_port(port);
    info.GetReturnValue().Set(Nan::New(port).ToLocalChecked());
}
NAN_GETTER(URL::GetProtocol) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto protocol = url->url->get_protocol();
    info.GetReturnValue().Set(Nan::New(protocol).ToLocalChecked());
}
NAN_SETTER(URL::SetProtocol) {
    string protocol = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_protocol(protocol);
    info.GetReturnValue().Set(Nan::New(protocol).ToLocalChecked());
}
NAN_GETTER(URL::GetSearch) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto search = url->url->get_search();
    info.GetReturnValue().Set(Nan::New(search).ToLocalChecked());
}
NAN_SETTER(URL::SetSearch) {
    string search = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_search(search);
    info.GetReturnValue().Set(Nan::New(search).ToLocalChecked());
}
NAN_GETTER(URL::GetUsername) {
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    auto username = url->url->get_username();
    info.GetReturnValue().Set(Nan::New(username).ToLocalChecked());
}
NAN_SETTER(URL::SetUsername) {
    string username = *Nan::Utf8String(value);
    URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
    url->url->set_username(username);
    info.GetReturnValue().Set(Nan::New(username).ToLocalChecked());
}
// NAN_GETTER(URL::GetSearchParams) {
//     URL* url = ObjectWrap::Unwrap<URL>(info.Holder());
//     auto search = url->url->get_search();
//     v8::Local<v8::Function> con = Nan::New(SearchParams::constructor);
//     v8::Local<v8::Value> argv[] = { Nan::New(search).ToLocalChecked() };
//     auto searchParams = Nan::NewInstance(con, 1, argv).ToLocalChecked();
//     info.GetReturnValue().Set(searchParams);
// }

template <auto Getter, auto Setter>
void SetAccessor(v8::Local<v8::FunctionTemplate> tpl, const char* name) {
    Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New(name).ToLocalChecked(), Getter, Setter);
}

void URL::Init(v8::Local<v8::Object> exports) {
    v8::Local<v8::Context> context = exports->CreationContext();
    Nan::HandleScope scope;

    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("URL").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    // Nan::SetAccessor(tpl->InstanceTemplate(), Nan::New("hostname").ToLocalChecked(), URL::GetHostname, URL::SetHostname);
    SetAccessor<URL::GetHash, URL::SetHash>(tpl, "hash");
    SetAccessor<URL::GetHost, URL::SetHost>(tpl, "host");
    SetAccessor<URL::GetHostname, URL::SetHostname>(tpl, "hostname");
    SetAccessor<URL::GetHref, URL::SetHref>(tpl, "href");
    SetAccessor<URL::GetOrigin, 0>(tpl, "origin");
    SetAccessor<URL::GetPassword, URL::SetPassword>(tpl, "password");
    SetAccessor<URL::GetPathname, URL::SetPathname>(tpl, "pathname");
    SetAccessor<URL::GetPort, URL::SetPort>(tpl, "port");
    SetAccessor<URL::GetProtocol, URL::SetProtocol>(tpl, "protocol");
    SetAccessor<URL::GetSearch, URL::SetSearch>(tpl, "search");
    SetAccessor<URL::GetUsername, URL::SetUsername>(tpl, "username");

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
        Nan::ThrowError("Must be called as a constructor");
    }
}