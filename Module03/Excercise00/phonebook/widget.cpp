#include "widget.h"
#include "ui_widget.h"
#include <QtWidgets>
#include <algorithm>
#include <QDebug>

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

    loadButton = new QPushButton(tr("&LOAD"));
    loadButton->setEnabled(true);
    saveButton = new QPushButton(tr("&SAVE"));
    saveButton->setEnabled(false);

    connect(addButton, SIGNAL(clicked()), this, SLOT(addContact()));
    connect(searchButton, SIGNAL(clicked()), this, SLOT(searchContact()));
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(refreshContact()));
    connect(bookmarkButton, SIGNAL(clicked()), this, SLOT(bookmarkContact()));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeContact()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelContact()));
    connect(loadButton, SIGNAL(clicked()), this, SLOT(loadContact()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveContact()));

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(refreshButton);
    buttonLayout1->addWidget(addButton);
    buttonLayout1->addWidget(searchButton);
    buttonLayout1->addStretch();
    buttonLayout1->addWidget(removeButton);
    buttonLayout1->addWidget(bookmarkButton);
    buttonLayout1->addWidget(cancelButton);

    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(saveButton);
    buttonLayout2->addWidget(loadButton);

    maintable = new QTableWidget;
    maintable->setColumnCount(4);
    QStringList m_TableHeader;
    m_TableHeader<<"Name"<<"Phone"<<"email"<<"Address";
    maintable->setHorizontalHeaderLabels(m_TableHeader);
    maintable->setShowGrid(true);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel,0,0);
    mainLayout->addWidget(phoneLabel,1,0);
    mainLayout->addWidget(emailLabel,2,0);
    mainLayout->addWidget(addressLabel,3,0,Qt::AlignTop);
    mainLayout->addWidget(nameLine,0,1);
    mainLayout->addWidget(phoneLine,1,1);
    mainLayout->addWidget(emailLine,2,1);
    mainLayout->addWidget(addressText,3,1,3,1,Qt::AlignTop);

    mainLayout->addLayout(buttonLayout1,0,2,4,2);
    mainLayout->addLayout(buttonLayout2,5,1);

    mainLayout->addWidget(maintable,6,1);

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
    UpdateInterface(addTable);
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
    maintable->setRowCount(maintable->rowCount()-1);
    UpdateInterface(addTable);
}

void Widget::cancelContact()
{
    UpdateInterface(Initial);
}


void Widget::bookmarkContact()
{
    phonebook.bookmark(search_index);
    UpdateInterface(Show);
}

void Widget::loadContact()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Address Book"), "",
                                                    tr("All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        phonebook.PB.clear();
        in >> phonebook.PB;

        if (phonebook.PB.empty()) {
            QMessageBox::information(this, tr("No PhoneBook in file"),
                                     tr("The file you are attempting to open PhoneBook no PhoneBook."));
        } else {
            Person temp_person = phonebook.index_search(0);
            UpdateInterface(Initial);
        }
    }
}

void Widget::saveContact()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Address Book"), "",
        tr("All Files (*)"));

    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream out(&file);
        out.setVersion(QDataStream::Qt_4_5);
        out << phonebook.PB;
        UpdateInterface(Old);
    }
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
            bookmarkButton->hide();
            removeButton->hide();
            cancelButton->hide();
            loadButton->setEnabled(true);
            saveButton->setEnabled(phonebook.size()>=1);
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
            bookmarkButton->show();
            bookmarkButton->setEnabled(!phonebook.is_bookmarked(search_index));
            removeButton->show();
            cancelButton->show();
            break;

        case addTable:
            maintable->clear();
            QStringList m_TableHeader;
            m_TableHeader<<"Name"<<"Phone"<<"email"<<"Address";
            maintable->setHorizontalHeaderLabels(m_TableHeader);
            maintable->setShowGrid(true);
            for(int i=0;i<(int)phonebook.size();i++){
                if (i>=maintable->rowCount()){
                    maintable->insertRow(maintable->rowCount());
                }
                maintable->setItem(i,0,new QTableWidgetItem(phonebook.PB[i].name));
                maintable->setItem(i,1,new QTableWidgetItem(phonebook.PB[i].phone));
                maintable->setItem(i,2,new QTableWidgetItem(phonebook.PB[i].email));
                maintable->setItem(i,3,new QTableWidgetItem(phonebook.PB[i].address));
            }
            break;

    }
}
