#ifndef TOOLS_HPP
#define TOOLS_HPP

struct Dummy {
    Dummy() = default;
    explicit Dummy(int x) : x_(x) {}
    int x_ = 0; // 1 bytes
};

struct Buffer
{
    explicit Buffer(int size) 
        : len_(0), buf_(new Dummy[size]) {}

    ~Buffer() {
        delete []buf_;
    }

    int len_ = 0;
    Dummy *buf_ = 0;
};



#endif
