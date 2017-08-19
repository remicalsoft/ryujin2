#pragma once
class SystemMain final
{
public:
    SystemMain() = default;
    ~SystemMain() = default;
    bool initialize() const;
    void finalize() const;
    void main() const;
};

