#pragma once

class Layouts
{
public:
    Layouts() = default;
protected:
    virtual constexpr void createLayout() = 0;
protected:
    virtual ~Layouts() = default;
};
