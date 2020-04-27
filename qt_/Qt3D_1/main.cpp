#include <QGuiApplication>

#include <Qt3DCore/QTransform>

#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QOrbitCameraController>

#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>

#include "handycontroller.h"

Qt3DCore::QEntity *createScene();

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow view;

    Qt3DCore::QEntity *rootEntity = createScene();

    Qt3DRender::QCamera * camera = view.camera();

    camera->lens()->setPerspectiveProjection(60.0f, (float)view.width() / view.height(), 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0.0f, 0.0f, 40.0f));
    camera->setViewCenter(QVector3D(0.0f, 0.0f, 10.0f));

//    Qt3DExtras::QOrbitCameraController *cameraController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    HandyController *cameraController = new HandyController(rootEntity);
    cameraController->setCamera(camera);
    cameraController->setLookSpeed(180.0f);
    cameraController->setLinearSpeed(50.0f);

    view.setRootEntity(rootEntity);
    view.show();
    return app.exec();
}

Qt3DCore::QEntity *createScene()
{
    Qt3DCore::QEntity *resultEntity = new Qt3DCore::QEntity;

    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh(resultEntity);

    torusMesh->setRadius(15.0f);
    torusMesh->setMinorRadius(5.0f);
    torusMesh->setSlices(50);
    torusMesh->setRings(50);

    Qt3DExtras::QPhongMaterial * torusMaterial = new Qt3DExtras::QPhongMaterial(resultEntity);
    torusMaterial->setDiffuse(QColor(255, 255, 0));

    Qt3DCore::QTransform * torusTranform = new Qt3DCore::QTransform(resultEntity);

    resultEntity->addComponent(torusMesh);
    resultEntity->addComponent(torusMaterial);
    resultEntity->addComponent(torusTranform);

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(resultEntity);
    Qt3DRender::QPointLight *pointLight = new Qt3DRender::QPointLight(resultEntity);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(resultEntity);
    lightTransform->setTranslation(QVector3D(25.0f, 15.0f, 20.0f));

    lightEntity->addComponent(pointLight);
    lightEntity->addComponent(lightTransform);

    return resultEntity;
}

