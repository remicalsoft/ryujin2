#pragma once

#include <map>

class Parameter
{
public:
    const static int Error = -1;

    Parameter() = default;
    virtual ~Parameter() = default;

    void set(std::string key, int val);
    int  get(std::string key) const;

private:
    std::map<std::string, int> _map;
};
