#pragma once

template <typename _T>
class Singleton {

protected:
    Singleton() = default;
    virtual ~Singleton() = default;
    Singleton(const Singleton& r) = default;
    Singleton& operator=(const Singleton& r) = default;

public:
	static _T* getIns() {
		static _T inst;
		return &inst;
	};

};
