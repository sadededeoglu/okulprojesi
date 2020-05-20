#include "temelverisinifi.h"

TemelVeriSinifi::TemelVeriSinifi(QObject *parent) : QObject(parent)
{
    _Id = 0;
}
TemelVeriSinifi::IdTuru TemelVeriSinifi::Id() const
{
    return _Id;
}
void TemelVeriSinifi::setId(const TemelVeriSinifi::IdTuru &Id)
{
    if (_Id != Id) {
        this->_Id = Id;
        IdDegisti(this->_Id);
    }
}
