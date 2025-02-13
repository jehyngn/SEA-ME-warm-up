#ifndef WIDGET_H
#define WIDGET_H

#include "phonebook.h"
#include "person.h"
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;
class QTableWidget;
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    enum Mode {Initial, Old, Show, addTable};

public slots:
    void addContact();
    void searchContact();
    void refreshContact();
    void removeContact();
    void cancelContact();
    void bookmarkContact();
    void loadContact();
    void saveContact();

private:
    int search_index;

    QPushButton *addButton;
    QPushButton *searchButton;
    QPushButton *refreshButton;

    QPushButton *removeButton;
    QPushButton *bookmarkButton;
    QPushButton *cancelButton;

    QPushButton *loadButton;
    QPushButton *saveButton;

    QLineEdit *nameLine;
    QLineEdit *phoneLine;
    QLineEdit *emailLine;
    QTextEdit *addressText;

    QString oldname;
    QString oldphone;
    QString oldemail;
    QString oldaddress;

    PhoneBook phonebook;
    void UpdateInterface(Mode mode);
    Mode CurrentMode;



    QTableWidget *maintable;

    Ui::Widget *ui;

};
#endif // WIDGET_H
