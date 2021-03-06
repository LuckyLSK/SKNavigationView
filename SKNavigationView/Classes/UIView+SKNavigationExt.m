//
//  UIView+SKNavigationExt.m
//  SKNavigationView_Example
//
//  Created by 李烁凯 on 2019/4/17.
//  Copyright © 2019 luckyLSK. All rights reserved.
//

#import "UIView+SKNavigationExt.h"

@implementation UIView (SKNavigationExt)

- (CGFloat)x {
    return self.frame.origin.x;
}
- (void)setX:(CGFloat)x {
    CGRect frame = self.frame;
    frame.origin.x = x;
    self.frame = frame;
}
- (CGFloat)y {
    return self.frame.origin.y;
}
- (void)setY:(CGFloat)y {
    CGRect frame = self.frame;
    frame.origin.y = y;
    self.frame = frame;
}
- (CGFloat)width {
    return self.frame.size.width;
}

- (void)setWidth:(CGFloat)width {
    CGRect frame = self.frame;
    frame.size.width = width;
    self.frame = frame;
}

- (CGFloat)height {
    return self.frame.size.height;
}

- (void)setHeight:(CGFloat)height {
    CGRect frame = self.frame;
    frame.size.height = height;
    self.frame = frame;
}



- (void (^)(UIView *))didAddsubView
{
    return objc_getAssociatedObject(self, _cmd);
}

- (void)setDidAddsubView:(void (^)(UIView *))didAddsubView
{
    objc_setAssociatedObject(self, @selector(didAddsubView), didAddsubView, OBJC_ASSOCIATION_COPY_NONATOMIC);
}


+ (void)load
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        //方法交换。当有视图加到这个view上时，得到通知
        Class viewClass = [UIView class];
        
        SEL originalSelector = @selector(addSubview:);
        SEL swizzledSelector = @selector(easyAddSubview:);
        
        Method originalMethod = class_getInstanceMethod(viewClass, originalSelector);
        Method swizzledMethod = class_getInstanceMethod(viewClass, swizzledSelector);
        
        BOOL didAddMethod =
        class_addMethod(viewClass,
                        originalSelector,
                        method_getImplementation(swizzledMethod),
                        method_getTypeEncoding(swizzledMethod));
        
        if (didAddMethod) {
            class_replaceMethod(viewClass,
                                swizzledSelector,
                                method_getImplementation(originalMethod),
                                method_getTypeEncoding(originalMethod));
        }
        else {
            method_exchangeImplementations(originalMethod, swizzledMethod);
        }
    });
}


- (void)easyAddSubview:(UIView *)view
{
    [self easyAddSubview:view];
    
    if (self.didAddsubView) {
        self.didAddsubView(view);
    }
}


- (UIViewController *)currentViewController
{
    for (UIView* next = [self superview]; next; next = next.superview) {
        UIResponder *nextResponder = [next nextResponder];
        if ([nextResponder isKindOfClass:[UIViewController class]]) {
            return (UIViewController *)nextResponder;
        }
    }
    return nil;
}

- (void)addTapCallBack:(id)target sel:(SEL)selector
{
    self.userInteractionEnabled = YES;
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:target action:selector];
    [self addGestureRecognizer:tap];
}

@end
