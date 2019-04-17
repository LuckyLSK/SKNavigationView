//
//  UIView+SKNavigationExt.h
//  SKNavigationView_Example
//
//  Created by 李烁凯 on 2019/4/17.
//  Copyright © 2019 luckyLSK. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <objc/runtime.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (SKNavigationExt)

@property (nonatomic) CGFloat x;
@property (nonatomic) CGFloat y;
@property(nonatomic) CGFloat width;
@property(nonatomic) CGFloat height;

/**
 * 获取当前view所在的控制器
 */
- (UIViewController *)currentViewController;

/**
 * addSubview之后的回调
 */
@property (nonatomic, copy) void(^didAddsubView)(UIView *view);

/**
 * 为视图添加一个事件
 */
- (void)addTapCallBack:(id)target sel:(SEL)selector;

@end

NS_ASSUME_NONNULL_END
