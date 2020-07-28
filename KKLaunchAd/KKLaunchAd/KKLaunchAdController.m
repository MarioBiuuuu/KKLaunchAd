

#import "KKLaunchAdController.h"
#import "KKLaunchAdConst.h"

@interface KKLaunchAdController ()

@end

@implementation KKLaunchAdController

-(BOOL)shouldAutorotate{
    
    return NO;
}

-(BOOL)prefersHomeIndicatorAutoHidden{
    
    return KKLaunchAdPrefersHomeIndicatorAutoHidden;
}

@end
