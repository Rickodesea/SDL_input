#include <stdbool.h>

#include "SDL_input.h"
#include "SDL_input.hpp"

struct Input
{
    input::Input* handle;
};

struct Profile
{
    input::Profile* handle;
};

struct BindSrc
{
    input::BindSrc handle;
};

struct Binding
{
    input::Binding* handle;
};

extern "C" Input* input_new_input()
{
    Input* input = malloc(sizeof(Input));
    memset(input, 0, sizeof(Input));
    input.handle = new input::Input();
    return input;
}

extern "C" Profile* input_new_profile()
{
    Profile* profile = malloc(sizeof(Profile));
    memset(profile, 0, sizeof(Profile));
    profile.handle = new input::Profile();
    return profile;
}

extern "C" BindSrc* input_new_bindsrc(BindSrcType type, Sint32 key)
{
    BindSrc* bindsrc = malloc(sizeof(BindSrc));
    memset(bindsrc, 0, sizeof(BindSrc));
    bindsrc.handle = input::BindSrc(type, key);
    return bindsrc;
}

extern "C" Binding* input_new_binding(/*BindSrc src, Callback callback, void* userdata*/)
{
    Binding* binding = malloc(sizeof(Binding));
    memset(binding, 0, sizeof(Binding));
    //binding.handle = new input::Binding(src, callback, userdata);
    return binding;
}

extern "C" void input_add_profile(Input* input, Profile* profile)
{
    input->handle.AddProfile(profile->handle);
}

extern "C" Binding* input_bind_onoff(Profile* profile, BindSrc* bindsrc, bool* varptr, Callback callback, void* userdata)
{
    Binding binding = input_new_binding();
    binding.handle = profile.handle->onoff(bindsrc->handle, varptr, callback, userdata);
    return binding;
}

extern "C" Binding* input_bind_toggle(Profile* profile, BindSrc* bindsrc, bool* varptr, Callback callback, void* userdata)
{
    Binding binding = input_new_binding();
    binding.handle = profile.handle->toggle(bindsrc->handle, varptr, callback, userdata);
    return binding;
}

extern "C" Binding* input_bind_absolute(Profile* profile, BindSrc* bindsrc, float* varptr, Callback callback, void* userdata)
{
    Binding binding = input_new_binding();
    binding.handle = profile.handle->absolute(bindsrc->handle, varptr, callback, userdata);
    return binding;
}

extern "C" Binding* input_bind_relative(Profile* profile, BindSrc* bindsrc, float* varptr, Callback callback, void* userdata)
{
    Binding binding = input_new_binding();
    binding.handle = profile.handle->relative(bindsrc->handle, varptr, callback, userdata);
    return binding;
}

extern "C" void input_set_limit(Binding* binding, float min, float max)
{
    binding->handle->SetLimit(min, max);
}

extern "C" void input_set_wrap(Binding* binding, float min, float max)
{
    binding->handle->SetWrap(min, max);
}