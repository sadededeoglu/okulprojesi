#include "temelverisinifi.h"

unsigned long long TemelVeriSinifi::getIdTuru() const
{
    return IdTuru;
}

void TemelVeriSinifi::setIdTuru(unsigned long long value)
{
    IdTuru = value;
}

TemelVeriSinifi::TemelVeriSinifi(QObject *parent) : QObject(parent)
{

}
