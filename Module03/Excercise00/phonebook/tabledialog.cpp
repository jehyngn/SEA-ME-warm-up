#include "tabledialog.h"

#include <QtWidgets>

TableDialog::TableDialog(QDialog *parent)
    : QDialog(parent)
{
    all_listButton = new QPushButton(tr("&ALL"));
    all_listButton->show();
//    bookmark_listButton = new QPushButton(tr("&Bookmarked"));
//    bookmark_listButton->show();

//    connect(all_listButton, SIGNAL(clicked()), this, SLOT(allContact()));
//    connect(bookmark_listButton, SIGNAL(clicked()), this, SLOT(bookmarkedContact()));

//    QHBoxLayout *buttonLayout4 = new QHBoxLayout;
//    buttonLayout1->addWidget(all_listButton, Qt::AlignTop);
//    buttonLayout1->addWidget(bookmark_listButton);

//    QGridLayout *subLayout = new QGridLayout;
//    subLayout->addLayout(nameLabel, 0, 0);
}


