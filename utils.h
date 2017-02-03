#ifndef UTILS_H
#define UTILS_H

#endif // UTILS_H

#include <QMessageBox>

template<class T>
void Messenger(const QString& text, const QMainWindow* window, T&& functor) {
    QMessageBox msgBox(window->parentWidget());
    msgBox.setText(text);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);

    if (msgBox.exec() == QMessageBox::Yes)
        functor();
}
