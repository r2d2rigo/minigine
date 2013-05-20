#import <QuartzCore/QuartzCore.h>
#import "GLView.hpp"
#include "Game.hpp"

using namespace Minigine;

@interface GLView (PrivateMethods)
- (void)createFramebuffer;
- (void)deleteFramebuffer;
@end


@implementation GLView

@synthesize context;

+ (Class)layerClass
{
    return [CAEAGLLayer class];
}

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    
	if (!self)
    {
        return nil;
    }
    
    self.contentScaleFactor = [[UIScreen mainScreen] scale];
    
    CAEAGLLayer *eaglLayer = (CAEAGLLayer *)self.layer;
    eaglLayer.opaque = TRUE;
    eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
                                    [NSNumber numberWithBool:FALSE], kEAGLDrawablePropertyRetainedBacking,
                                    kEAGLColorFormatRGBA8, kEAGLDrawablePropertyColorFormat,
                                    nil];
    
    context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
    
    if (!context || ![EAGLContext setCurrentContext:context])
    {
        NSLog(@"Could not create context!");
        return nil;
    }
    
    defaultFramebuffer = 0;
    colorRenderbuffer = 0;
    depthRenderbuffer = 0;
    
    Game::GetRunningInstance()->Initialize();
    
    return self;
}

- (void)createFramebuffer
{
    assert(defaultFramebuffer == 0);
    
    NSLog(@"EAGLView: creating Framebuffer");
    
    glGenFramebuffers(1, &defaultFramebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);
    
    glGenRenderbuffers(1, &colorRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
    
    [context renderbufferStorage:GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)self.layer];
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &framebufferWidth);
    glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &framebufferHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, colorRenderbuffer);
 
    glGenRenderbuffers(1, &depthRenderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, depthRenderbuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, framebufferWidth, framebufferHeight);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthRenderbuffer);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        NSLog(@"Failed to make complete framebuffer object %x", glCheckFramebufferStatus(GL_FRAMEBUFFER));
    }
}

- (void)deleteFramebuffer
{
    if (context)
    {
        [EAGLContext setCurrentContext:context];
        
        if (defaultFramebuffer)
        {
            glDeleteFramebuffers(1, &defaultFramebuffer);
            defaultFramebuffer = 0;
        }
        
        if (colorRenderbuffer)
        {
            glDeleteRenderbuffers(1, &colorRenderbuffer);
            colorRenderbuffer = 0;
        }
        
        if (depthRenderbuffer)
        {
            glDeleteRenderbuffers(1, &depthRenderbuffer);
            depthRenderbuffer = 0;
        }
    }
}

- (void)drawFrame
{
    if (context != nil)
    {
        [EAGLContext setCurrentContext:context];
        
        if (!defaultFramebuffer)
        {
            [self createFramebuffer];
        }
        
        glBindFramebuffer(GL_FRAMEBUFFER, defaultFramebuffer);
        
        Game* currentGame = Game::GetRunningInstance();
        glViewport(0, 0, currentGame->GetGraphicsDevice().GetScreenWidth(), currentGame->GetGraphicsDevice().GetScreenHeight());
  
        currentGame->Update(0.0f);
        currentGame->Draw(0.0f);
        
        glBindRenderbuffer(GL_RENDERBUFFER, colorRenderbuffer);
        [context presentRenderbuffer:GL_RENDERBUFFER];
    }
    else
    {
        NSLog(@"Context not set!");
    }
}

- (void)activate
{
    if(displayLink == nil)
    {
        displayLink = [self.window.screen displayLinkWithTarget:self selector:@selector(drawFrame)];
        
        [displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        NSLog(@"Starting Render Loop");
    }
}

- (void)deactivate
{
    if (displayLink != nil)
    {
        [displayLink invalidate];
        displayLink = nil;
        NSLog(@"Stopping Render Loop");
    }
}

- (void)layoutSubviews
{
    [self deleteFramebuffer];
}

- (void)dealloc
{
    [self deleteFramebuffer];
}

@end
