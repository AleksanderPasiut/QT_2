#include "byteconverterdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ByteConverterDialog dialog;
    dialog.show();

    return a.exec();
}
