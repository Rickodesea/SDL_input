#pragma once

extern "C"
{

typedef struct Input   Input;
typedef struct Profile Profile;
typedef struct BindSrc BindSrc;
typedef struct Binding Binding;

typedef enum BindSrcType BindSrcType;

typedef void (*Callback)(Binding*);

enum BindSrcType {
    BindSrcType_Key = 1,
    BindSrcType_MouseAxis = 2,
    BindSrcType_MouseBtn = 3,
};
	
enum BindDest {
    BindDest_Undefined = 0,
    BindDest_Absolute = 1,
    BindDest_Relative = 2,
    BindDest_OnOff = 3,
    BindDest_Toggle = 4,
};

};

extern "C" Input* input_new_input();
extern "C" Profile* input_new_profile();
extern "C" BindSrc* input_new_bindsrc(BindSrcType type, Sint32 key);
extern "C" void input_add_profile(Input* input, Profile* profile);
extern "C" Binding* input_bind_onoff(Profile* profile, BindSrc* bindsrc, bool* varptr, Callback callback, void* userdata);
extern "C" Binding* input_bind_toggle(Profile* profile, BindSrc* bindsrc, bool* varptr, Callback callback, void* userdata);
extern "C" Binding* input_bind_absolute(Profile* profile, BindSrc* bindsrc, float* varptr, Callback callback, void* userdata);
extern "C" Binding* input_bind_relative(Profile* profile, BindSrc* bindsrc, float* varptr, Callback callback, void* userdata);
extern "C" void input_set_limit(Binding* binding, float min, float max);
extern "C" void input_set_wrap(Binding* binding, float min, float max);