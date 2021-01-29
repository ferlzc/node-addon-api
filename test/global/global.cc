#include "napi.h"

using namespace Napi;

Value CheckSetTimeout(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("clearTimeout"));
}

Value CheckClearTimeout(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("clearTimeout"));
}

Value CheckSetInterval(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("setInterval"));
}

Value CheckClearInterval(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("clearInterval"));
}

Value CheckConsole(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("console"));
}

Value CheckTextEncoder(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("TextEncoder"));
}

Value CheckTextDecoder(const CallbackInfo& info) {
  Env env = info.Env();
  Object global = env.Global();
  return Boolean::New(info.Env(), global.Has("TextDecoder"));
}

Object InitGlobal(Env env) {
  Object exports = Object::New(env);

  exports["CheckSetTimeout"] = Function::New(env, CheckSetTimeout);
  exports["CheckClearTimeout"] = Function::New(env, CheckClearTimeout);
  exports["CheckSetInterval"] = Function::New(env, CheckSetInterval);
  exports["CheckClearInterval"] = Function::New(env, CheckClearInterval);
  exports["CheckConsole"] = Function::New(env, CheckConsole);

  exports["CheckTextEncoder"] = Function::New(env, CheckTextEncoder);
  exports["CheckTextDecoder"] = Function::New(env, CheckTextDecoder);

  return exports;
}
