#pragma once

#include "Layouts.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QTextEdit>
#include <QInputDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QDir>


class LeftLayout : public QVBoxLayout , public Layouts
{
    Q_OBJECT

public:

   explicit LeftLayout(QWidget* parent = nullptr);

public:
    void createLayout() override;

public:
    void createButtons();

private slots:
    void addFunctionally();
    void deleteFunctionally();
    void editFunctionally();

private:
    QVBoxLayout* m_left_layout {nullptr};
    QPushButton* buttons {nullptr};
    QWidget* widget {nullptr};
    QVBoxLayout* layout {nullptr};

private:
    QPushButton* addButton {nullptr};
    QPushButton* removeButton {nullptr};
    QPushButton* editButton {nullptr};

private:
    QListWidget* listWidget {nullptr};
};




