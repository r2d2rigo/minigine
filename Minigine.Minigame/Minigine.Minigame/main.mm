#import <UIKit/UIKit.h>

#include "Minigame.hpp"

int main(int argc, char *argv[])
{
    @autoreleasepool
    {
        Minigame* g = new Minigame();
        g->Run();
  
        return 0;
//        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}
