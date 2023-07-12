#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
#include <algorithm>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel *nameLabel = new QLabel(tr("Name:"));
    nameLine = new QLineEdit;
    nameLine->setReadOnly(false);
    QLabel *phoneLabel = new QLabel(tr("Phone:"));
    phoneLine = new QLineEdit;
    phoneLine->setReadOnly(false);
    QLabel *emailLabel = new QLabel(tr("Email:"));
    emailLine = new QLineEdit;
    emailLine->setReadOnly(false);
    QLabel *addressLabel = new QLabel(tr("Address:"));
    addressText = new QTextEdit;
    addressText->setReadOnly(false);

    refreshButton = new QPushButton(tr("&REFRESH"));
    addButton = new QPushButton(tr("&ADD"));
    searchButton = new QPushButton(tr("&SEARCH"));
    searchButton->setEnabled(false);
    removeButton = new QPushButton(tr("&REMOVE"));
    removeButton->hide();
    bookmarkButton = new QPushButton(tr("&BOOKMARK"));
    bookmarkButton->hide();
    cancelButton = new QPushButton(tr("&CANCEL"));
    cancelButton->hide();

    connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchContact()));
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(refreshContact()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeContact()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelContact()));

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(refreshButton);
    buttonLayout1->addWidget(addButton);
    buttonLayout1->addWidget(searchButton);
    buttonLayout1->addStretch();

    QVBoxLayout *buttonLayout2 = new QVBoxLayout;
    buttonLayout2->addWidget(removeButton);
    buttonLayout2->addWidget(bookmarkButton);
    buttonLayout2->addWidget(cancelButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(phoneLabel,1,0);
    mainLayout->addWidget(emailLabel,2,0);
    mainLayout->addWidget(addressLabel,3,0,Qt::AlignTop);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(phoneLine,1,1);
    mainLayout->addWidget(emailLine,2,1,Qt::AlignTop);
    mainLayout->addWidget(addressText,3,1);

    mainLayout->addLayout(buttonLayout1,3,2);
    mainLayout->addLayout(buttonLayout2,4,2);

    setLayout(mainLayout);
    setWindowTitle(tr("Phone Book Program"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addContact()
{
    oldname = nameLine->text();
    oldphone = phoneLine->text();
    oldemail = emailLine->text();
    oldaddress = addressText->toPlainText();

    if (oldname.isEmpty()) {
       QMessageBox::information(this, tr("Empty Name"),
           tr("Please enter a Name"));
       return;
    }

    if(phonebook.is_name_in_list(oldname))
    {
        QMessageBox::information(this,
            tr("Confirm Addition"),
            tr("Name : %1 is already in PhoneBook.").arg(oldname));
        UpdateInterface(Old);
        return;
    }

    Person person(oldname, oldphone, oldemail, oldaddress, false);
    phonebook.add(person);
    QMessageBox::information(this, tr("Add Successful"),
    tr("Name : %1\nPhone Number : %2\nEmail : %3\nAddress : %4\nhas been added to your Phone Book.").arg(oldname,oldphone,oldemail,oldaddress));

    UpdateInterface(Initial);
}

void Widget::searchContact()
{
    oldname = nameLine->text();
    oldphone = phoneLine->text();
    oldemail = emailLine->text();
    oldaddress = addressText->toPlainText();

    if (oldname.isEmpty())
    {
        QMessageBox::information(this,
        tr("Search Error"),
        tr("Name is Empty.\nType Something!"));
        return;
    }

    search_index = phonebook.search(oldname);
    if (search_index==-1){
        QMessageBox::information(this,
        tr("Search Error"),
        tr("Name : %1 is not in PhoneBook.").arg(oldname));
    }
    else {
        Person found_person = phonebook.index_search(search_index);
        nameLine->setText(found_person.name);
        phoneLine->setText(found_person.phone);
        emailLine->setText(found_person.email);
        addressText->setText(found_person.address);
        UpdateInterface(Show);
    }
}

void Widget::refreshContact()
{
    UpdateInterface(Initial);
}

void Widget::removeContact()
{
    oldname = nameLine->text();
    oldphone = phoneLine->text();
    oldemail = emailLine->text();
    oldaddress = addressText->toPlainText();

    int button = QMessageBox::question(this,
        tr("Confirm Remove"),
        tr("Name : \"%1\" will be removed. \nAre you sure?").arg(oldname),
        QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::No) return;
    else {phonebook.remove(search_index); UpdateInterface(Initial);}
}

void Widget::cancelContact()
{
    UpdateInterface(Initial);
}

void Widget::UpdateInterface(Mode mode)
{
    CurrentMode = mode;
    switch (CurrentMode)
    {
        case Initial:
            nameLine->setReadOnly(false);
            phoneLine->setReadOnly(false);
            emailLine->setReadOnly(false);
            addressText->setReadOnly(false);

            nameLine->clear();
            phoneLine->clear();
            emailLine->clear();
            addressText->clear();

            refreshButton->setEnabled(true);
            addButton->setEnabled(true);
            searchButton->setEnabled(phonebook.size()>=2);
            removeButton->hide();
            cancelButton->hide();
            break;

        case Old:
            nameLine->setText(oldname);
            phoneLine->setText(oldphone);
            emailLine->setText(oldemail);
            addressText->setText(oldaddress);
            break;

        case Show:
            nameLine->setReadOnly(true);
            phoneLine->setReadOnly(true);
            emailLine->setReadOnly(true);
            addressText->setReadOnly(true);

            refreshButton->setEnabled(false);
            addButton->setEnabled(false);
            searchButton->setEnabled(false);
            removeButton->show();
            cancelButton->show();
            break;

    }
}


