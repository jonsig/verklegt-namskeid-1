#ifndef ADDRELATION_H
#define ADDRELATION_H

#include <QDialog>

namespace Ui {
class addrelation;
}

class addrelation : public QDialog
{
    Q_OBJECT

public:
    explicit addrelation(QWidget *parent = 0);
    ~addrelation();

private:
    Ui::addrelation *ui;
};

#endif // ADDRELATION_H
