#ifndef BUTTON_H
#define BUTTON_H

class Button
{
public:
    Button(int length);
    void print();
private:
    int m_length;
    bool m_click;
};

#endif // BUTTON_H
