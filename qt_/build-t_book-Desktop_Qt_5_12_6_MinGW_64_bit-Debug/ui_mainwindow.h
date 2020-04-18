/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *name;
    QLineEdit *name_line;
    QHBoxLayout *horizontalLayout;
    QLabel *tel;
    QLineEdit *tel_line;
    QTextBrowser *output;
    QVBoxLayout *verticalLayout_3;
    QPushButton *read_but;
    QPushButton *add_but;
    QPushButton *del_but;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(446, 294);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_4 = new QHBoxLayout(centralwidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        name = new QLabel(centralwidget);
        name->setObjectName(QString::fromUtf8("name"));

        horizontalLayout_2->addWidget(name);

        name_line = new QLineEdit(centralwidget);
        name_line->setObjectName(QString::fromUtf8("name_line"));

        horizontalLayout_2->addWidget(name_line);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tel = new QLabel(centralwidget);
        tel->setObjectName(QString::fromUtf8("tel"));

        horizontalLayout->addWidget(tel);

        tel_line = new QLineEdit(centralwidget);
        tel_line->setObjectName(QString::fromUtf8("tel_line"));

        horizontalLayout->addWidget(tel_line);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        output = new QTextBrowser(centralwidget);
        output->setObjectName(QString::fromUtf8("output"));

        verticalLayout_2->addWidget(output);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(30, 30, 30, 30);
        read_but = new QPushButton(centralwidget);
        read_but->setObjectName(QString::fromUtf8("read_but"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(read_but->sizePolicy().hasHeightForWidth());
        read_but->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(read_but);

        add_but = new QPushButton(centralwidget);
        add_but->setObjectName(QString::fromUtf8("add_but"));
        sizePolicy.setHeightForWidth(add_but->sizePolicy().hasHeightForWidth());
        add_but->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(add_but);

        del_but = new QPushButton(centralwidget);
        del_but->setObjectName(QString::fromUtf8("del_but"));
        sizePolicy.setHeightForWidth(del_but->sizePolicy().hasHeightForWidth());
        del_but->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(del_but);


        horizontalLayout_3->addLayout(verticalLayout_3);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 446, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        name->setText(QApplication::translate("MainWindow", "Name", nullptr));
        tel->setText(QApplication::translate("MainWindow", "Phone", nullptr));
        read_but->setText(QApplication::translate("MainWindow", "Read", nullptr));
        add_but->setText(QApplication::translate("MainWindow", "Add", nullptr));
        del_but->setText(QApplication::translate("MainWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
