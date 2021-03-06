#include "demofileaccessinterface.h"
#include "demojsonfileaccess.h"

#include <vector>
#include "Demo.h"
#include "Clip.h"

#include <iostream>

int main()
{
    DemoFileAccessInterface *demoFileAccess = new DemoJsonFileAccess();

    Demo *demo = demoFileAccess->getDemo("resources/demo.json");

    assert(!demo->name().compare("Test Demo"));

    std::vector<Clip *> clipList = demo->clipList();
    for(Clip *clip : clipList) {
        std::cout << clip->name() << std::endl;
    }

    assert(!clipList.at(0)->name().compare("first clip"));
    assert(clipList.at(0)->name().compare("wrong clip name"));

    std::vector<Scene *> sceneList = demo->sceneList();
    for(Scene *scene : sceneList) {
        std::cout << scene->name() << std::endl;
    }

    assert(!clipList.at(0)->scene()->name().compare("FirstScene"));
    assert(clipList.at(0)->scene()->name().compare("Wrong Scene"));

    demoFileAccess->storeDemo("resources/demo1.json", demo);

    return 0;
}
