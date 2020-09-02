#ifndef CLIPINSPECTORVIEW_H
#define CLIPINSPECTORVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include "models/clipinspectormodel.h"
#include "controllers/clipinspectorcontroller.h"

class ClipInspectorView : public QWidget
{
    Q_OBJECT
public:
    explicit ClipInspectorView(QWidget *parent = nullptr);
    void setModel(ClipInspectorModel *model);
    void setController(ClipInspectorController *controller);

private:
    QLabel *clipNameLabel;
    QComboBox *sceneComboBox;

    ClipInspectorModel *model;
    ClipInspectorController *controller;

private Q_SLOTS:
    void selectedClipChanged();
    void sceneListChanged();

};

#endif // CLIPINSPECTORVIEW_H