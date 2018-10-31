#pragma once
#include <QMainWindow>

class QLabel;
class QLineEdit;
class QPushButton;
class VideoFrameGetter;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QLabel* pUrlLabel;
    QLineEdit* pUrlLineEdit;
    QPushButton* pUrlConnectStartPushButton;
    VideoFrameGetter* pVideoFrameGetter;
    static void callbackReceivedFrame(void* pSelf, char* pFrameData, int width, int height);
private slots:
    void startConnect();
};
