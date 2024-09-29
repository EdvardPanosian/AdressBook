#pragma once

#include "LeftLayout.h"
#include "Layouts.h"
#include "RightLayout.h"
#include <QtWidgets>


class HomePage : public QWidget, public Layouts
{
    Q_OBJECT
public:
    HomePage(QWidget* parent = nullptr);

public:
    void createLayout() override;
private:
    LeftLayout* m_left_layout {nullptr};

    RightLayout* m_right_layout {nullptr};

    QGridLayout* m_main_layout {nullptr};

    QWidget* m_main_widget {nullptr};

};



