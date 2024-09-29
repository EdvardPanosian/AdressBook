#pragma once

#include <QVBoxLayout>
#include "Layouts.h"
#include <QWidget>


class RightLayout : public QVBoxLayout , Layouts
{
    Q_OBJECT
public:
    explicit RightLayout(QWidget* parent = nullptr);

public:
    void createLayout() override;

private:
    QVBoxLayout* m_right_layout {nullptr};

};
