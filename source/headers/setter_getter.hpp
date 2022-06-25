#ifndef SETTER_GETTER_H
#define SETTER_GETTER_H

template <typename T>
class Getter
{
protected:
    T &_value;

public:
    Getter(T &value) : _value(value)
    {
    }
    operator const T() const
    {
        return _value;
    }
};

template <typename T>
class GetterSetter : public Getter<T>
{
    using Getter<T>::_value;
    using Getter<T>::Getter;

public:
    GetterSetter<T> &
    operator=(const T val)
    {
        _value = val;
        return *(this);
    };
};

#endif