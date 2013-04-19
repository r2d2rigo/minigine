#pragma once

#import <UIKit/UIKit.h>

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

@class EAGLContext;
    
@interface GLView : UIView
{
    @private
    GLint framebufferWidth;
    GLint framebufferHeight;
        
    GLuint defaultFramebuffer, colorRenderbuffer, depthRenderbuffer;
        
    CADisplayLink* displayLink;
        
    BOOL useDepthBuffer;
        
}
    
@property (nonatomic, retain) EAGLContext* context;
    
- (void) activate;
- (void) deactivate;

@end
