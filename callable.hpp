#ifndef CALLABLE_HPP
#define CALLABLE_HPP

template <typename Return, typename ... Args>
class Callable {
    using FunctionVariant = Return(*)(Args...);
    
private:
    FunctionVariant func = nullptr;

public:
    Callable() {} 
    Callable(FunctionVariant f) : func(f) {}
    void Bind(FunctionVariant f) { func = f; }
    Return Call(Args... args) { return IsValid() ? func(args...) : Return{}; }
    bool IsValid() { return func != nullptr; }
};

#endif
