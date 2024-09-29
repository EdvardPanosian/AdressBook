#include "LeftLayout.h"

LeftLayout::LeftLayout(QWidget *parent)
    : QVBoxLayout(parent)
{

    this->createButtons();
}

void LeftLayout::createLayout()
{
    m_left_layout = new QVBoxLayout();

    listWidget = new QListWidget();

    QString filePath = QDir::homePath() + "/Desktop/data.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            listWidget->addItem(line);
        }
        file.close();
    } else {
        throw std::logic_error("File does not open");
    }

    m_left_layout->addWidget(listWidget);
    this->addLayout(m_left_layout);
}

void LeftLayout::createButtons()
{
        widget = new QWidget();
        layout = new QVBoxLayout();

        widget->setLayout(layout);

        addButton = new QPushButton(QString("Add"));

        addButton->setFixedSize(500 , 100);

        addButton->setStyleSheet("background-color: orange");

        layout->addWidget(addButton);

        QObject::connect(addButton , &QPushButton::clicked ,this, &LeftLayout::addFunctionally);

        removeButton = new QPushButton(QString("Remove"));

        removeButton->setFixedSize(500 , 100);
        removeButton->setStyleSheet("background-color: red");

        layout->addWidget(removeButton);

        QObject::connect(removeButton , &QPushButton::clicked ,this, &LeftLayout::deleteFunctionally);

        editButton = new QPushButton(QString("Edit"));

        editButton->setFixedSize(500,100);
        editButton->setStyleSheet("background-color: green");

        layout->addWidget(editButton);

        QObject::connect(editButton , &QPushButton::clicked ,this, &LeftLayout::editFunctionally);


        this->addWidget(widget);
}


void LeftLayout::addFunctionally()
{
    QString name = QInputDialog::getText(widget , "Add Element" , "Please Input Name");
    QString mail = QInputDialog::getText(widget , "Add Element" , "Please Input mail");
    QString password = QInputDialog::getText(widget ,"Add Element" , "Please Input password");

    if (!name.isEmpty() && !mail.isEmpty() && !password.isEmpty())
    {
        listWidget->addItem(name);
        listWidget->addItem(mail);
        listWidget->addItem(password);

        QString filePath = QDir::homePath() + "/Desktop/data.txt";

        QFile file(filePath);

        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out << name << "\n";
            file.close();
        }
        else
        {
            throw std::logic_error("File does not open");
        }
    }

}

void LeftLayout::deleteFunctionally()
{
    QListWidgetItem* item = listWidget->currentItem();

    if (item)
    {
        QString itemText = item->text();

        delete item;

        QString filePath = QDir::homePath() + "/Desktop/data.txt";

        QFile file(filePath);

        if (file.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream in(&file);
            QStringList list;

            while (!in.atEnd())
            {
                QString string = in.readLine();
                if (string != itemText)
                {
                    list << string;
                }
            }

            file.seek(0);

            QTextStream out(&file);
            for (const QString& line : list)
            {
                out << line << "\n";
            }


            file.resize(file.pos());
            file.close();
        }
        else
        {
            throw std::logic_error("File does not open");
        }
    }
}

void LeftLayout::editFunctionally()
{
    QListWidgetItem *item = listWidget->currentItem();
    if (item)
    {
        QString oldString = item->text();

        QString text = QInputDialog::getText(widget, "Edit Element","Enter new text:", QLineEdit::Normal, oldString);

        if (!text.isEmpty() && text != oldString)
        {
            item->setText(text);

            QString filePath = QDir::homePath() + "/Desktop/data.txt";
            QFile file(filePath);

            if (file.open(QIODevice::ReadWrite| QIODevice::Text))
            {
                QTextStream in(&file);
                QStringList lines;
                while (!in.atEnd())
                {
                    QString string = in.readLine();
                    if (string == oldString)
                    {
                        lines << text;
                    }
                    else
                    {
                        lines << string;
                    }
                }

                file.seek(0);


                QTextStream out(&file);
                for (const QString& line : lines)
                {
                    out << line << "\n";
                }

                file.resize(file.pos());
                file.close();
            }
            else
            {
                throw std::logic_error("File does not open");
            }
        }
    }
}

