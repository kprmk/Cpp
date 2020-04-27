#ifndef HANDYCONTROLLER_H
#define HANDYCONTROLLER_H

#include <Qt3DCore/QEntity>
#include <Qt3DInput/QMouseDevice>
#include <Qt3DInput/QKeyboardDevice>
#include <Qt3DInput/QLogicalDevice>
#include <Qt3DInput/QAction>
#include <Qt3DInput/QActionInput>
#include <Qt3DInput/QAxis>
#include <Qt3DInput/QAnalogAxisInput>
#include <Qt3DRender/QCamera>
#include <Qt3DLogic/QFrameAction>


class HandyController: public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    HandyController(Qt3DCore::QNode *parent = 0);

    void setCamera(Qt3DRender::QCamera *value);

    float getLookSpeed();
    void setLookSpeed(float value);

    float getLinearSpeed();
    void setLinearSpeed(float value);

protected slots:
    void activeChanged(bool isActive);
    void valueChanged(float value);
    void frameActionTriggered(float dt);

private:
    Qt3DInput::QMouseDevice *mouseDev;
    Qt3DInput::QKeyboardDevice *keyboardDev;
    Qt3DInput::QLogicalDevice *logicalDev;

    Qt3DInput::QAction *actKeyUp;
    Qt3DInput::QAction *actButLeft;
    Qt3DInput::QActionInput *inpKeyUp;
    Qt3DInput::QActionInput *inpKeyLeft;
    Qt3DInput::QAxis *xAxi;
    Qt3DInput::QAxis *yAxi;
    Qt3DInput::QAnalogAxisInput *inpMouseX;
    Qt3DInput::QAnalogAxisInput *inpMouseY;

    Qt3DLogic::QFrameAction *frameAct;

    Qt3DRender::QCamera *cam;
    float lookVelocity;
    float linearVelocity;

    bool isKeyUpPressed;
    bool isButLeftPressed;

    float dx;
    float dy;
};

#endif // HANDYCONTROLLER_H
