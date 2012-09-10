//
//  OBTabBarController.m
//  Fever
//
//  Created by Oriol Blanc on 11/22/11.
//  Copyright (c) 2011 Oriol Blanc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class OBTabBarController;

@protocol OBTabBarControllerDelegate <NSObject>
    - (UIImage *)imageTabAtIndex:(NSUInteger)index;
    
    @optional
    - (UIImage *)tabBarBackground;
    - (UIImage *)highlightedImageTabAtIndex:(NSUInteger)index;
    - (BOOL)shouldSelectTabAtIndex:(NSUInteger)index;
    - (void)didSelectedTabAtIndex:(NSUInteger)index;
@end

@interface OBTabBarController : UIViewController

@property (nonatomic, retain) NSArray *viewControllers;
@property (nonatomic, assign) id <OBTabBarControllerDelegate> delegate;
@property (nonatomic, assign) NSInteger selectedIndex;

- (id)initWithViewControllers:(NSArray *)viewControllers delegate:(id <OBTabBarControllerDelegate>)delegate;

- (void)presentModalViewController:(UIViewController *)modalViewController animated:(BOOL)animated;
- (void)dismissModalViewControllerAnimated:(BOOL)animated;
- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

+ (CGFloat)tabBarHeight;

@end

@interface UIActionSheet(OBTabBarActionSheetAdditions)
- (void)showFromFeverTabBar:(OBTabBarController *)tabBarController;
@end