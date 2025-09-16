#include "LoginPage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
{
    qDebug()<<Q_FUNC_INFO;
    setFixedSize(800,400);
    // createLoginPage();
}

LoginPage::~LoginPage()
{
    qDebug()<<Q_FUNC_INFO;

}

void LoginPage::createLoginPage()
{
    qDebug()<<Q_FUNC_INFO;

    m_verticalLayout = new QVBoxLayout;

    m_userName = new QLabel("UserName", this);
    m_usernameEdit = new QTextEdit(this);
    m_usernameEdit->setPlaceholderText("Enter Username: ");
    m_password = new QLabel("Password",this);
    m_passwordEdit = new QTextEdit(this);
    m_passwordEdit->setPlaceholderText("Enter Password: ");
    m_horizantalLayout = new QHBoxLayout;
    m_submitButton = new QPushButton("submit",this);
    m_cancelButton = new QPushButton("cancel",this);
    m_horizantalLayout->addWidget(m_submitButton);
    m_horizantalLayout->addWidget(m_cancelButton);

    connect(m_submitButton , &QPushButton::clicked, this , &LoginPage::onSubmitButtonClicked);
    connect(m_cancelButton , &QPushButton::clicked, this , &LoginPage::onCancelButtonClicked);


    m_verticalLayout->addWidget(m_userName);
    m_verticalLayout->addWidget(m_usernameEdit);
    m_verticalLayout->addWidget(m_password);
    m_verticalLayout->addWidget(m_passwordEdit);
    m_verticalLayout->addLayout(m_horizantalLayout);
    this->setLayout(m_verticalLayout);


}

void LoginPage::onSubmitButtonClicked()
{
    qDebug()<<Q_FUNC_INFO;
    QString dispalyUsername = m_usernameEdit->toPlainText();
    QString displayPassword = m_passwordEdit->toPlainText();

    qDebug()<<"Entered username and password is : "<<dispalyUsername<<"\t"<<displayPassword;

}

void LoginPage::onCancelButtonClicked()
{
    qDebug()<<Q_FUNC_INFO;
    exit(0);
}
