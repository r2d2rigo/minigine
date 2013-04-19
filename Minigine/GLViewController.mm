#import "GLViewController.hpp"
#import "GLView.hpp"

@implementation GLViewController

//-(id)init
//{
//    self = [super init];
//    
////    CGRect frame = [[UIScreen mainScreen] bounds];
////    self.view = [[GLView alloc] initWithFrame:frame];
//    
//    return self;
//}

- (void)loadView
{
    [super loadView];

    CGRect frame = [[UIScreen mainScreen] bounds];
    self.view = [[GLView alloc] initWithFrame:frame];
}

@end
