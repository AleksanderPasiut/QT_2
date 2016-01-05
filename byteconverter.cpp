#include "byteconverter.h"

ByteConverter::ByteConverter(QObject* parent)
    : QObject(parent)   {}

void ByteConverter::setDec(const QString& string)
{
    emit binChanged(QString::number(string.toInt(0, 10), 2));
    emit hexChanged(QString::number(string.toInt(0, 10), 16));
}

void ByteConverter::setHex(const QString& string)
{
    emit binChanged(QString::number(string.toInt(0, 16), 2));
    emit decChanged(QString::number(string.toInt(0, 16), 10));
}

void ByteConverter::setBin(const QString& string)
{
    emit decChanged(QString::number(string.toInt(0, 2), 10));
    emit hexChanged(QString::number(string.toInt(0, 2), 16));
}
