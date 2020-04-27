#include "handycontroller.h"

HandyController::HandyController(Qt3DCore::QNode *parent):
    Qt3DCore::QEntity(parent)
{
    isButLeftPressed = false;
    isKeyUpPressed = false;
    dx = 0;
    dy = 0;
    lookVelocity = 180.0f;
    linearVelocity = 50.0f;
    cam = 0;

    mouseDev = new  Qt3DInput::QMouseDevice(this);
    keyboardDev = new Qt3DInput::QKeyboardDevice(this);
    logicalDev = new Qt3DInput::QLogicalDevice(this);

    actKeyUp = new Qt3DInput::QAction(this);
    actButLeft = new Qt3DInput::QAction(this);
    inpKeyUp = new Qt3DInput::QActionInput(this);
    inpKeyLeft = new Qt3DInput::QActionInput(this);
    xAxi = new Qt3DInput::QAxis(this);
    yAxi = new Qt3DInput::QAxis(this);
    inpMouseX = new Qt3DInput::QAnalogAxisInput;
    inpMouseY = new Qt3DInput::QAnalogAxisInput;

    frameAct = new Qt3DLogic::QFrameAction(this);

    inpKeyUp->setButtons(QVector<int>() << Qt::Key_Up);
    inpKeyUp->setSourceDevice(keyboardDev);
    actKeyUp->addInput(inpKeyUp);
    // for connect set the alias for actKeyUp
    actKeyUp->setObjectName("key_up");

    inpKeyLeft->setButtons(QVector<int>() << Qt::LeftButton);
    inpKeyLeft->setSourceDevice(mouseDev);
    actButLeft->addInput(inpKeyLeft);
    // for connect -//-
    actButLeft->setObjectName("but_left");

    inpMouseX->setAxis(Qt3DInput::QMouseDevice::X);
    inpMouseX->setSourceDevice(mouseDev);
    xAxi->addInput(inpMouseX);
    // for connect -//-
    xAxi->setObjectName("Axis_x");

    inpMouseY->setAxis(Qt3DInput::QMouseDevice::Y);
    inpMouseY->setSourceDevice(mouseDev);
    yAxi->addInput(inpMouseY);
    // for connect -//-
    yAxi->setObjectName("Axis_y");

    logicalDev->addAction(actKeyUp);
    logicalDev->addAction(actButLeft);
    logicalDev->addAxis(xAxi);
    logicalDev->addAxis(yAxi);

    connect(actKeyUp, SIGNAL(activeChanged(bool)), this, SLOT(activeChanged(bool)));
    connect(actButLeft, SIGNAL(activeChanged(bool)), this, SLOT(activeChanged(bool)));

    connect(xAxi, SIGNAL(valueChanged(float)), this, SLOT(valueChanged(float)));
    connect(yAxi, SIGNAL(valueChanged(float)), this, SLOT(valueChanged(float)));

    connect(frameAct, SIGNAL(triggered(float)), this, SLOT(frameActionTriggered(float)));
}

void HandyController::setCamera(Qt3DRender::QCamera *value)
{
    cam = value;
}

float HandyController::getLookSpeed()
{
    return lookVelocity;
}

void HandyController::setLookSpeed(float value)
{
    lookVelocity = value;
}

float HandyController::getLinearSpeed()
{
    return linearVelocity;
}

void HandyController::setLinearSpeed(float value)
{
    linearVelocity = value;
}

void HandyController::activeChanged(bool isActive)
{
    if (sender()->objectName() == "key_up")
        isKeyUpPressed = isActive;
    else if (sender()->objectName() == "but_left")
        isButLeftPressed = isActive;
}

void HandyController::valueChanged(float value)
{
    if (sender()->objectName() == "Axis_x")
        dx = value;
    else if (sender()->objectName() == "Axis_y")
        dy = value;
}

void HandyController::frameActionTriggered(float dt)
{
    if (cam != 0)
    {
        if (isButLeftPressed == true)
        {
            cam->panAboutViewCenter(-dx * lookVelocity * dt);
            cam->tiltAboutViewCenter(-dy * lookVelocity * dt);
        }
        else if (isKeyUpPressed == true)
        {
            cam->rollAboutViewCenter(lookVelocity * 0.5 * dt);
        }
    }
}
