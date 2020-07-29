

#import "MBLaunchAdImageManager.h"
#import "MBLaunchAdCache.h"

@interface MBLaunchAdImageManager()

@property(nonatomic,strong) MBLaunchAdDownloader *downloader;
@end

@implementation MBLaunchAdImageManager

+(nonnull instancetype )sharedManager{
    static MBLaunchAdImageManager *instance = nil;
    static dispatch_once_t oneToken;
    dispatch_once(&oneToken,^{
        instance = [[MBLaunchAdImageManager alloc] init];
        
    });
    return instance;
}

- (instancetype)init{
    self = [super init];
    if (self) {
        _downloader = [MBLaunchAdDownloader sharedDownloader];
    }
    return self;
}

- (void)loadImageWithURL:(nullable NSURL *)url options:(MBLaunchAdImageOptions)options progress:(nullable MBLaunchAdDownloadProgressBlock)progressBlock completed:(nullable XHExternalCompletionBlock)completedBlock{
    if(!options) options = MBLaunchAdImageDefault;
    if(options & MBLaunchAdImageOnlyLoad){
        [_downloader downloadImageWithURL:url progress:progressBlock completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error) {
            if(completedBlock) completedBlock(image,data,error,url);
        }];
    }else if (options & MBLaunchAdImageRefreshCached){
        NSData *imageData = [MBLaunchAdCache getCacheImageDataWithURL:url];
        UIImage *image =  [UIImage imageWithData:imageData];
        if(image && completedBlock) completedBlock(image,imageData,nil,url);
        [_downloader downloadImageWithURL:url progress:progressBlock completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error) {
            if(completedBlock) completedBlock(image,data,error,url);
            [MBLaunchAdCache async_saveImageData:data imageURL:url completed:nil];
        }];
    }else if (options & MBLaunchAdImageCacheInBackground){
        NSData *imageData = [MBLaunchAdCache getCacheImageDataWithURL:url];
        UIImage *image =  [UIImage imageWithData:imageData];
        if(image && completedBlock){
            completedBlock(image,imageData,nil,url);
        }else{
            [_downloader downloadImageWithURL:url progress:progressBlock completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error) {
                [MBLaunchAdCache async_saveImageData:data imageURL:url completed:nil];
            }];
        }
    }else{//default
        NSData *imageData = [MBLaunchAdCache getCacheImageDataWithURL:url];
        UIImage *image =  [UIImage imageWithData:imageData];
        if(image && completedBlock){
            completedBlock(image,imageData,nil,url);
        }else{
            [_downloader downloadImageWithURL:url progress:progressBlock completed:^(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error) {
                if(completedBlock) completedBlock(image,data,error,url);
                [MBLaunchAdCache async_saveImageData:data imageURL:url completed:nil];
            }];
        }
    }
}

@end
