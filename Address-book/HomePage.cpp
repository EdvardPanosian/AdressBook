#include "HomePage.h"

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    createLayout();

    setWindowTitle("Address-Book");

    setFixedSize(500,500);
}

void HomePage::createLayout()
{
    m_main_widget = new QWidget(this);

    m_main_layout = new QGridLayout(m_main_widget);

    m_left_layout = new LeftLayout();

    m_right_layout = new RightLayout();

    m_left_layout->createLayout();

    m_right_layout->createLayout();


    m_main_layout->addLayout(m_left_layout,  0, 0);

    m_main_layout->addLayout(m_right_layout, 0, 1);

    m_main_widget->setLayout(m_main_layout);

    setLayout(m_main_layout->layout());

}
