#include "dersler.h"

std::shared_ptr<Dersler> Dersler::getPtr() const
{
    return ptr;
}

void Dersler::setPtr(const std::shared_ptr<Dersler> &value)
{
    ptr = value;
}

Dersler::Dersler(QObject *parent) : QObject(parent)
{
    
}
