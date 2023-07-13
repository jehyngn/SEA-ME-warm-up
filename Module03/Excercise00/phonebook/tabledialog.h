#ifndef TABLEDIALOG_H
#define TABLEDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QLineEdit;
class QPushButton;
QT_END_NAMESPACE

class TableDialog : public QDialog
{
    Q_OBJECT
public:
    TableDialog(QWidget *parent = 0);
public slots:
    void allContact();
    void bookmarkedContact();
private:
    QPushButton *all_listButton;
    QPushButton *bookmark_listButton;
};

#endif // TABLEDIALOG_H
