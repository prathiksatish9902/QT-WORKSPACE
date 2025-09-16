#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>
class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

    void createLoginPage();

public slots:
    void onSubmitButtonClicked();
    void onCancelButtonClicked();

private:
    QLabel *m_userName;
    QLabel *m_password;

    QTextEdit *m_usernameEdit;
    QTextEdit *m_passwordEdit;

    QPushButton *m_submitButton;
    QPushButton *m_cancelButton;

    QVBoxLayout *m_verticalLayout;
    QHBoxLayout *m_horizantalLayout;
};
#endif // LOGINPAGE_H
