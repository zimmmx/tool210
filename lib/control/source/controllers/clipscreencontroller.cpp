#include "clipscreencontroller.h"

ClipScreenController::ClipScreenController(QObject *parent) : QObject(parent)
{

}

void ClipScreenController::setModel(OpenGLModel *model)
{
    this->model = model;
    model->setParent(this);
}

void ClipScreenController::setTime(float time)
{
}

void ClipScreenController::setClipToRender(Clip *clip)
{
    model->setClipToRender(clip);
}

void ClipScreenController::toggleRun()
{
}


