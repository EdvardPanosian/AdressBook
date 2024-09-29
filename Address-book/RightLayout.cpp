#include "RightLayout.h"

RightLayout::RightLayout(QWidget *parent)
    : QVBoxLayout(parent)
{}

void RightLayout::createLayout()
{
    m_right_layout = new QVBoxLayout();
}
