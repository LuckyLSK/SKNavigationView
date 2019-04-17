//
//  UIScrollView+SKNavigationExt.h
//  SKNavigationView_Example
//
//  Created by 李烁凯 on 2019/4/17.
//  Copyright © 2019 luckyLSK. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger ,ScrollDirection) {
    ScrollDirectionUnknow = 0,
    ScrollDirectionUp,//向上滚动
    ScrollDirectionDown,//向下滚动
    
};

NS_ASSUME_NONNULL_BEGIN

@interface UIScrollView (SKNavigationExt)

/**
 * 开始改变方向标
 */
@property (nonatomic, assign) ScrollDirection direction;

/**
 * 开始改变方向时scrollview的距离
 */
@property (nonatomic, assign)float scrollDistance ;

/**
 *  是否正在动画
 */
//@property (nonatomic , assign)BOOL isScrolling ;


@property (nonatomic, assign) BOOL enableDirection;

@end

NS_ASSUME_NONNULL_END
