#pragma once
#include <d3d11.h>
#include <wrl/client.h>


namespace wrl = Microsoft::WRL;


class BindsBase 
{
public:
    BindsBase() = default;
    ~BindsBase() = default;

    virtual void bind() const = 0;
};
