#pragma once

#import <UIKit/UIKit.h>
#import "GLView.hpp"

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) GLView *view;

@end
