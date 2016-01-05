#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "byteconverterdialog.h"
#include "byteconverter.h"

ByteConverterDialog::ByteConverterDialog()
{
    setFixedSize(220, 150);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QGridLayout* editLayout = new QGridLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QLabel* labelDec = new QLabel("Decimal");
    QLabel* labelHex = new QLabel("Hexadecimal");
    QLabel* labelBin = new QLabel("Binary");
    QLineEdit* textDec = new QLineEdit;
    QLineEdit* textHex = new QLineEdit;
    QLineEdit* textBin = new QLineEdit;
    QPushButton* buttonQuit = new QPushButton("Quit");

    mainLayout->addLayout(editLayout);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(buttonLayout);

    editLayout->addWidget(labelDec, 0, 0);
    editLayout->addWidget(labelHex, 1, 0);
    editLayout->addWidget(labelBin, 2, 0);

    editLayout->addWidget(textDec, 0, 1);
    editLayout->addWidget(textHex, 1, 1);
    editLayout->addWidget(textBin, 2, 1);

    buttonLayout->addSpacing(180);
    buttonLayout->addWidget(buttonQuit);

    ByteConverter* converter = new ByteConverter(this);

    connect(textDec, SIGNAL(textChanged(QString)), converter, SLOT(setDec(QString)));
    connect(textBin, SIGNAL(textChanged(QString)), converter, SLOT(setBin(QString)));
    connect(textHex, SIGNAL(textChanged(QString)), converter, SLOT(setHex(QString)));

    connect(converter, SIGNAL(decChanged(QString)), textDec, SLOT(setText(QString)));
    connect(converter, SIGNAL(binChanged(QString)), textBin, SLOT(setText(QString)));
    connect(converter, SIGNAL(hexChanged(QString)), textHex, SLOT(setText(QString)));

    connect(buttonQuit, SIGNAL(clicked(bool)), this, SLOT(close()));
}
