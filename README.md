### An Introduction to Callables
___
```
Designed and inspired with Godot Engine callables in mind to store functions as variables in a simple way.
```

### Examples
___
  
**Declaring a Callable:**
```c++
void helloWorld() { std::cout << "Hello, World!" << std::endl; }
int add(int a, int b) { return a+b; } 

int main(int argc, const char* argv[]) {
    Callable printFn(helloWorld); // makes a new Callable for helloWorld()
    Callable addFn(add); // makes a new Callable for add()
}
```
**Declaring an Uninitialized Callable:**
```c++
int main(int argc, const char* argv[]) {
    // declaring an unitialized callable requires you to supply the return type and parameters manually
    // it is structured as followed: <returnType, param1, param2, param3, ... >
    // declaring a callable that returns an int, and takes two ints as the parameters would look like this:

    Callable<int, int, int> myFn;
}
```
**Using a Callable:**
```c++
void helloWorld() { std::cout << "Hello, World!" << std::endl; }
int add(int a, int b) { return a+b; } 

int main(int argc, const char* argv[]) {
    Callable printFn(helloWorld);
    printFn.Call() // calls the print function and prints 'Hello, World!'

    Callable addFn(add);
    std::cout << addFn.Call(1,2) << std::endl; // calls the add function with supplied paramters and prints '3'
}
```

**Binding a New Callable:**
```c++
// binding a callable is a way to update the callable value
// callables can only be binded if the function signatures are matching because of delegate behaviors

void helloWorld() { std::cout << "Hello, World!" << std::endl; }
int add(int a, int b) { return a+b; }
int mult(int a, int b) { return a*b; }

int main(int argc, const char* argv[]) {

    Callable printFn(helloWorld);
    // this is NOT allowed, it does not match the original function signature of void f(void)
    // the compiler will NOT allow this binding ...
    printFn.Bind(add) 

    Callable calcFn(add);
    std::cout << calcFn.Call(1,2) << std::endl; // prints '3'

    // since this function matches the original function signature of int f(int, int) this is a valid binding
    calcFn.Bind(mult) 
    std::cout << calcFn.Call(3,2) << std::end; // now prints '6' because calcFn now points to mult()
}
```
