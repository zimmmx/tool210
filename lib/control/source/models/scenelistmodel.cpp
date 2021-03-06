#include "models/scenelistmodel.h"
#include <QDebug>

SceneListModel::SceneListModel(QAbstractListModel *parent) :
    QAbstractTableModel(parent),
    data_(nullptr)
{

}

int SceneListModel::rowCount(const QModelIndex& /*parent*/) const
{
    if(data_)
        return static_cast<int>(data_->size());
    else
        return 0;
}

int SceneListModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 2;
}

QVariant SceneListModel::data(const QModelIndex &index, int role) const
{
    if(data_ == nullptr)
        return QVariant();

    Scene *scene = data_->at(index.row());

    QVariant data;

    switch (role) {
        case Qt::DisplayRole:
        case Qt::EditRole:
        switch (index.column()) {
        case 0:
            data.setValue(QString::fromStdString(scene->name()));
            break;
        case 1:
            data.setValue(QString::fromStdString(scene->shaderFileName()));
            break;
        }
        break;

        case SceneName:
            data.setValue(QString::fromStdString(scene->name()));
            break;
        default:
            return data;
    }

    return data;
}

bool SceneListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole)
        return false;

    Scene *scene = data_->at(index.row());

    switch (index.column())
    {
    case 0: // scene name
        scene->setName(value.toString().toStdString());
        break;
    case 1: // shader filename
        addSceneInteractor->setSceneShaderFilename(scene->id(), value.toString().toStdString());
        qDebug() << "filename changed";
        break;
    }

    emit dataChanged(index, index);
    return true;
}

bool SceneListModel::insertRows(int /*row*/, int count, const QModelIndex &/*parent*/)
{
    for(int i = 0; i < count; i++) {
        data_->push_back(new Scene);
    }
    return true;
}

void SceneListModel::setSceneList(std::vector<Scene *> *sceneList)
{
    data_ = sceneList;
    emit dataChanged(index(0, 0), index(rowCount(), 0));
}

void SceneListModel::setAddScenenInteractor(AddSceneInteractor *addSceneInteractor)
{
    this->addSceneInteractor = addSceneInteractor;
}
