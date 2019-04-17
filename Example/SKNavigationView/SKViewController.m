//
//  SKViewController.m
//  SKNavigationView
//
//  Created by luckyLSK on 04/17/2019.
//  Copyright (c) 2019 luckyLSK. All rights reserved.
//

#import "SKViewController.h"
#import "SKNavigationViewMacro.h"

@interface SKViewController ()

@property (nonatomic, strong) SKNavigationView *navigationView;

@end

@implementation SKViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
//    [self initUINavbar];
}

- (void)initUINavbar{
    self.navigationView = [[SKNavigationView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, 90)];
    [self.view addSubview:self.navigationView];

    [self.navigationView setTitle:@"标题"];
    [self.navigationView addLeftButtonWithTitle:@"左按钮" clickCallBack:^(UIView *view) {
        NSLog(@"左按钮点击");
    }];

    [self.navigationView addRightButtonWithTitle:@"右按钮" clickCallBack:^(UIView *view) {
        NSLog(@"右按钮点击");
    }];


    UIView *leftView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 99, 50)];
    leftView.backgroundColor = [UIColor redColor];
    [self.navigationView addLeftView:leftView clickCallback:^(UIView *view) {
        NSLog(@"leftView点击");
    }];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
