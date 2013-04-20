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

    self.view = [[GLView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
}

-(BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return YES;
}

@end
