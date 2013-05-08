#import "GLViewController.hpp"
#import "GLView.hpp"
#include "Input/Touch.hpp"
#include "Input/TouchPosition.hpp"

using namespace Minigine::Input;

@implementation GLViewController

- (void)loadView
{
    [super loadView];

    self.view = [[GLView alloc] initWithFrame:CGRectMake(0, 0, 0, 0)];
}

-(BOOL) shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation
{
    return YES;
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch* touch = [touches anyObject];
    CGPoint touchPosition = [touch locationInView:[self view]];
    CGFloat scale = [[self view] contentScaleFactor];
    
    Touch::touches[0].Active = true;
    Touch::touches[0].Position = Vector2F(touchPosition.x * scale, touchPosition.y * scale);
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch* touch = [touches anyObject];
    CGPoint touchPosition = [touch locationInView:[self view]];
    CGFloat scale = [[self view] contentScaleFactor];
    
    Touch::touches[0].Active = true;
    Touch::touches[0].Position = Vector2F(touchPosition.x * scale, touchPosition.y * scale);
}

-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    Touch::touches[0].Active = false;
}

-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    Touch::touches[0].Active = false;
}

@end
