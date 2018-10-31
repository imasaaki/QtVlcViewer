#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoframegetter.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSizePolicy>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pUrlLabel(nullptr),
    pUrlLineEdit(nullptr),
    pUrlConnectStartPushButton(nullptr),
    pVideoFrameGetter(nullptr)
{
    this->pUrlLabel = new QLabel;
    this->pUrlLabel->setText(tr("URL"));

    this->pUrlLineEdit = new QLineEdit;
    // this->pUrlLineEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->pUrlLineEdit->setText("rtsp://192.168.1.32:8554");


    this->pUrlConnectStartPushButton = new QPushButton;
    this->pUrlConnectStartPushButton->setText("start");

    auto *urlLayout = new QHBoxLayout;
    urlLayout->addWidget(this->pUrlLabel);
    urlLayout->addWidget(this->pUrlLineEdit);
    urlLayout->addWidget(this->pUrlConnectStartPushButton);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(urlLayout);
    mainLayout->addStretch();
    ui->setupUi(this);

    ui->centralWidget->setLayout(mainLayout);

    connect(
                this->pUrlConnectStartPushButton,
                SIGNAL(clicked()),
                this,
                SLOT(startConnect()));

    this->pVideoFrameGetter = new VideoFrameGetter(reinterpret_cast<void*>(this));
}

MainWindow::~MainWindow()
{
    if (this->pVideoFrameGetter != nullptr)
    {
        delete this->pVideoFrameGetter;
    }

    delete ui;
}

void MainWindow::startConnect()
{
    if (this->pVideoFrameGetter != nullptr)
    {
        this->pVideoFrameGetter->start(
                    this->pUrlLineEdit->text(),
                    MainWindow::callbackReceivedFrame);
    }
}

void MainWindow::callbackReceivedFrame(void* pSelf, char* pFrameData, int width, int height)
{

}

