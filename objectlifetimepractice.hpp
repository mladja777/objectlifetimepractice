#include <iostream>

#define print() \
    do { \
        std::cout << __PRETTY_FUNCTION__ << std::endl; \
    } while (0)

#define separate_args(...) separate_impl(__VA_ARGS__)
#define separate_impl(arg1, ...) arg1 separator __VA_ARGS__
#define separator , public 

#define define_struct(A) \
    struct A { \
        A() { \
            print(); \
        } \
        ~A() { \
            print(); \
        } \
        A(const A&) { \
            print(); \
        } \
        A(A&&) { \
            print(); \
        } \
        A& operator()(const A&) { \
            print(); \
            return *this; \
        } \
        A& operator()(A&&) { \
            print(); \
            return *this; \
        } \
        void foo() { \
            print(); \
        } \
        void bar() { \
            print(); \
        } \
    };

#define define_struct_virtual(A) \
    struct A { \
        A() { \
            print(); \
        } \
        virtual ~A() { \
            print(); \
        } \
        A(const A&) { \
            print(); \
        } \
        A(A&&) { \
            print(); \
        } \
        A& operator()(const A&) { \
            print(); \
            return *this; \
        } \
        A& operator()(A&&) { \
            print(); \
            return *this; \
        } \
        virtual void foo() { \
            print(); \
        } \
        virtual void bar() { \
            print(); \
        } \
    };

#define define_struct_with_bases(A, ...) \
    struct A : public separate_args(__VA_ARGS__) { \
        A() { \
            print(); \
        } \
        virtual ~A() { \
            print(); \
        } \
        A(const A&) { \
            print(); \
        } \
        A(A&&) { \
            print(); \
        } \
        A& operator()(const A&) { \
            print(); \
            return *this; \
        } \
        A& operator()(A&&) { \
            print(); \
            return *this; \
        } \
        virtual void foo() { \
            print(); \
        } \
        virtual void bar() { \
            print(); \
        } \
    };

// Example usage:
// define_struct(X);
// define_struct_virtual(Y);
// define_struct_virtual(Q);
// define_struct_with_bases(Z, X, Y, Q)

// int main() {
//     Z* z = new Z();
//     X* x = z;
//     delete x;

//     return 0;
// }
