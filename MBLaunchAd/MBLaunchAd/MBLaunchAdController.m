

#import "MBLaunchAdController.h"
#import "MBLaunchAdConst.h"

@interface MBLaunchAdController ()

@end

@implementation MBLaunchAdController

-(BOOL)shouldAutorotate{
    
    return NO;
}

-(BOOL)prefersHomeIndicatorAutoHidden{
    
    return MBLaunchAdPrefersHomeIndicatorAutoHidden;
}

@end
