

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#pragma mark - MBLaunchAdDownload

typedef void(^MBLaunchAdDownloadProgressBlock)(unsigned long long total, unsigned long long current);

typedef void(^MBLaunchAdDownloadImageCompletedBlock)(UIImage *_Nullable image, NSData * _Nullable data, NSError * _Nullable error);

typedef void(^MBLaunchAdDownloadVideoCompletedBlock)(NSURL * _Nullable location, NSError * _Nullable error);

typedef void(^MBLaunchAdBatchDownLoadAndCacheCompletedBlock) (NSArray * _Nonnull completedArray);

@protocol MBLaunchAdDownloadDelegate <NSObject>

- (void)downloadFinishWithURL:(nonnull NSURL *)url;

@end

@interface MBLaunchAdDownload : NSObject
@property (assign, nonatomic ,nonnull)id<MBLaunchAdDownloadDelegate> delegate;
@end

@interface MBLaunchAdImageDownload : MBLaunchAdDownload

@end

@interface MBLaunchAdVideoDownload : MBLaunchAdDownload

@end

#pragma mark - MBLaunchAdDownloader
@interface MBLaunchAdDownloader : NSObject

+(nonnull instancetype )sharedDownloader;

- (void)downloadImageWithURL:(nonnull NSURL *)url progress:(nullable MBLaunchAdDownloadProgressBlock)progressBlock completed:(nullable MBLaunchAdDownloadImageCompletedBlock)completedBlock;

- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadImageAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable MBLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

- (void)downloadVideoWithURL:(nonnull NSURL *)url progress:(nullable MBLaunchAdDownloadProgressBlock)progressBlock completed:(nullable MBLaunchAdDownloadVideoCompletedBlock)completedBlock;

- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray;
- (void)downLoadVideoAndCacheWithURLArray:(nonnull NSArray <NSURL *> * )urlArray completed:(nullable MBLaunchAdBatchDownLoadAndCacheCompletedBlock)completedBlock;

@end

