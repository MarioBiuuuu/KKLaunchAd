

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - KKLaunchAdDownload

typedef void(^KKLaunchAdDownloadProgressBlock)(unsigned long long total, unsigned long long current);

typedef void(^KKLaunchAdDownloadImageCompletedBlock)(UIImage *_Nullable image, NSData * _Nullable data, NSError * _Nullable error);

typedef void(^KKLaunchAdDownloadVideoCompletedBlock)(NSURL * _Nullable location, NSError * _Nullable error);

typedef void(^KKLaunchAdBatchDownLoadAndCacheCompletedBlock) (NSArray * _Nonnull completedArray);

@protocol KKLaunchAdDownloadDelegate <NSObject>

- (void)downloadFinishWithURL:(nonnull NSURL *)url;

@end

@interface KKLaunchAdDownload : NSObject
@property (assign, nonatomic ,nonnull)id<KKLaunchAdDownloadDelegate> delegate;
@end

@interface KKLaunchAdImageDownload : KKLaunchAdDownload

@end

@interface KKLaunchAdVideoDownload : KKLaunchAdDownload

@end

#pragma mark - KKLaunchAdDownloader
@interface KKLaunchAdDownloader : NSObject

+(nonnull instancetype )sharedDownloader;

- (void)downloadImageWithURL:(nonnull NSURL *)url progress:(nullable KKLaunchAdDownloadProgressBlock)progressBlock completed:(nullable KKLaunchAdDownloadImageCompletedBlock)completedBlock;

- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable KKLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

- (void)downloadVideoWithURL:(nonnull NSURL *)url progress:(nullable KKLaunchAdDownloadProgressBlock)progressBlock completed:(nullable KKLaunchAdDownloadVideoCompletedBlock)completedBlock;

- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable KKLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

@end

