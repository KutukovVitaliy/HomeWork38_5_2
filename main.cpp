#include "widget.h"

#include <QApplication>

#include <QHBoxLayout>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QtWebEngineWidgets/QWebEngineView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QHBoxLayout hbox(&w);
    auto *textField = new QPlainTextEdit;
    textField->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    auto *webView = new QWebEngineView;
    webView->setSizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
    webView->setHtml(textField->toPlainText());
    hbox.addWidget(textField);
    hbox.addWidget(webView);
    w.setWindowTitle("HTML Editor");
    QObject::connect(textField, &QPlainTextEdit::textChanged, [textField, webView](){
        webView->setHtml(textField->toPlainText());
    });
    w.show();
    return a.exec();
}
