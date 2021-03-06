#ifndef DEMOFILEACCESSINTERFACE_H
#define DEMOFILEACCESSINTERFACE_H

#include <vector>
#include <QString>
#include "Demo.h"

class DemoFileAccessInterface {
public:
    virtual ~DemoFileAccessInterface() {};
    virtual Demo *getDemo(QString filepath) = 0;
    virtual void storeDemo(QString filepath, Demo *demo) = 0;
};

#endif // DEMOFILEACCESSINTERFACE_H
