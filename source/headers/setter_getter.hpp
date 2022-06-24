#ifndef SetGetGeneric_H
#define SETTER_GETTER_H

template <typename T>
class SetGetGeneric
{
private:
    T *t = nullptr; // nullptr

public:
    SetGetGeneric(/* args */);
    ~SetGetGeneric();
};

SetGetGeneric::SetGetGeneric(T _t) :
{
    t = new T(_t);
}

SetGetGeneric::~SetGetGeneric()
{
    delete t;
}

#endif