#ifndef FOLDERSCANNER_H
#define FOLDERSCANNER_H

#include <QObject>

class folderScanner : public QObject
{
    Q_OBJECT
public:
    explicit folderScanner(QObject *parent = 0);

signals:

public slots:
};

#endif // FOLDERSCANNER_H
