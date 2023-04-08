#include <iostream>
#include <vector>
#include <stdbool.h>

// #include <SqliteStatement>
class Value                                                     // Abstract class because of virtual functions
{
public:
    Value() { std::cout << "Value\n"; }                         // Construtor
    virtual ~Value() { std::cout << "~Value\n"; }                       // Destructor

    virtual bool equals(Value const *other){return false;}// const = 0;
    virtual bool equals(Boolean const *other) const { return false; };
};

bool operator == (Value const &a, Value const &b);
bool operator != (Value const &a, Value const &b);

class Boolean : public Value                                    // Boolean is Derived from Value
{
public:
    Boolean(bool value = true) { std::cout << "Boolean\n"; }    // Construtor
    virtual ~Boolean() { std::cout << "~Boolean\n"; }                   // Destructor
    virtual bool equals(Value const *other) //const override      // Method
    {
        return other->equals(this);
    }
    virtual bool equals(Boolean const *other) const override    // Polymorphism -> Multiple methods with same name, Also a method
    {
        return other->value == this->value;
    }
    bool boolValue() const { return value; }                    // Method

private:
    bool value;
};

class Check
{
public:
    Check() { 
        std::cout << "Check\n";
    }                         // Constructor
    ~Check() {
        std::cout << "~Check\n";
    }                       // Destructor
    // std::shared_ptr<Value> newValue(SqliteStatement& statement, int typeIndex, int valueIndex);
};

int main()
{
    Check c;
    // Value *b = new Boolean();
    Value *b = new Boolean();
    delete b;
    // std::cout << "blah:" << std::endl;
}
