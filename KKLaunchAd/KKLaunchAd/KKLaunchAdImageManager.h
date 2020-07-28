

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "KKLaunchAdDownloader.h"

typedef NS_OPTIONS(NSUInteger, KKLaunchAdImageOptions) {
    /** 有缓存,读取缓存,不重新下载,没缓存先下载,并缓存 */
    KKLaunchAdImageDefault = 1 << 0,
    /** 只下载,不缓存 */
    KKLaunchAdImageOnlyLoad = 1 << 1,
    /** 先读缓存,再下载刷新图片和缓存 */
    KKLaunchAdImageRefreshCached = 1 << 2 ,
    /** 后台缓存本次不显示,缓存OK后下次再显示(建议使用这种方式)*/
    KKLaunchAdImageCacheInBackground = 1 << 3
};

typedef void(^XHExternalCompletionBlock)(UIImage * _Nullable image,NSData * _Nullable imageData, NSError * _Nullable error, NSURL * _Nullable imageURL);

@interface KKLaunchAdImageManager : NSObject

+(nonnull instancetype )sharedManager;
- (void)loadImageWithURL:(nullable NSURL *)url options:(KKLaunchAdImageOptions)options progress:(nullable KKLaunchAdDownloadProgressBlock)progressBlock completed:(nullable XHExternalCompletionBlock)completedBlock;

@end
