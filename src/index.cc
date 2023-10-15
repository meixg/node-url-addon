#include <nan.h>
#include "url.h"

NAN_MODULE_INIT(init) {
    URL::Init(target);
    // Nan::Set(target, Nan::New("parse").ToLocalChecked(),
    //     Nan::GetFunction(Nan::New<v8::FunctionTemplate>(parse)).ToLocalChecked());
}

NODE_MODULE(hello, init)