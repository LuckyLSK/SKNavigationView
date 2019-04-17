//
//  SKNavigationViewMacro.h
//  SKNavigationView
//
//  Created by 李烁凯 on 2019/4/17.
//  Copyright © 2019 luckyLSK. All rights reserved.
//

#ifndef SKNavigationViewMacro_h
#define SKNavigationViewMacro_h

#import "SKNavigationView.h"
#import "UIView+SKNavigationExt.h"
#import "UIScrollView+SKNavigationExt.h"


#define kTitleViewEdge 50.0f //title左右边距
#define kViewMaxWidth 100.0f //左右两边按钮，视图，最大的的宽度
#define kViewMinWidth  44.0f //左右两边按钮，视图，最小的的宽度
#define kViewEdge   2.0f //按钮之间的间距
#define kAnimationDuring 0.3f //动画执行时间
#define kNavNormalHeight 44.0f     //导航栏原始高度

//屏幕宽高
#define kNavScreenWidth  [[UIScreen mainScreen] bounds].size.width
#define kNavScreenHeight [[UIScreen mainScreen] bounds].size.height

//屏幕的高度
#define kNavScreenMaxLength (MAX(kNavScreenWidth, kNavScreenHeight))

//屏幕是否是横屏状态
#define kNavIsHorizontalScreen  UIDeviceOrientationIsLandscape([UIDevice currentDevice].orientation)

//屏幕尺寸判断
#define kNavIsIphone    (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
#define kNavIsIphone_4  (kNavIsIphone && kNavScreenMaxLength == 480.0f)  // 4/4s            3.5寸   320*480
#define kNavIsIphone_5  (kNavIsIphone && kNavScreenMaxLength == 568.0f)  // 5/5s/se           4寸   320*568
#define kNavIsIphone_6  (kNavIsIphone && kNavScreenMaxLength == 667.0f)  // 6/6s/7/8        4.7寸   375*667
#define kNavIsIphone_6P (kNavIsIphone && kNavScreenMaxLength == 736.0f)  // 6p/6ps/7p/8p    5.5寸   414*736
#define kNavIsIphone_X  (kNavIsIphone && kNavScreenMaxLength == 812.0f)  // iPhonex         5.8寸   375*812

//statusbar默认高度 orginal
#define kNavStatusbarOrginalHeight  ([UIApplication sharedApplication].statusBarFrame.size.height)

//状态栏高度
#define kNavStatusbarHeight (kNavIsHorizontalScreen ? (kNavIsIphone_X ? 0 : kNavStatusbarOrginalHeight) : kNavStatusbarOrginalHeight )

#define kNavigationHeight (kNavStatusbarHeight + 44)

static int sknavigation_button_tag = 1 ; //视图放到数组中的唯一标示

/**
 * 创建视图的位置，放在左边还是右边
 */
typedef NS_ENUM(NSUInteger , buttonPlaceType) {
    buttonPlaceTypeLeft ,
    buttonPlaceTypeRight ,
};

/**
 * 导航条改变的类型
 */
typedef NS_ENUM(NSUInteger , NavigationChangeType) {
    NavigationChangeTypeUnKnow ,
    NavigationChangeTypeAlphaChange ,
    NavigationChangeTypeAnimation ,
    NavigationChangeTypeSmooth ,
};

#ifdef DEBUG
#   define SKLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#   define SKLog(...)
#endif

#endif /* SKNavigationViewMacro_h */
