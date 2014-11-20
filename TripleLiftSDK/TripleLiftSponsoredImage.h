//
//  SponsoredImage.h
//  TripleLiftApp
//
//  Created by Brian D Lee on 5/31/13.
//  Copyright (c) 2013 Triple Lift. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TripleLiftSponsoredImage : NSObject

- (id)initFromObject:(NSDictionary *)jsonObject mobilePlatform:(NSString *)platform;

@property (nonatomic, readonly, copy) NSString *advertiser_name;
@property (nonatomic, readonly, copy) NSString *heading;
@property (nonatomic, readonly, copy) NSString *caption;
@property (nonatomic, readonly, copy) NSString *clickthroughLink;

@property (nonatomic, readonly, copy) NSString *imageUrl;
@property (nonatomic, readonly, copy) NSString *imageThumbnailUrl;

// These load the images synchronously
// It's recommended to use a third-party asynchronous image downloader
- (UIImage *)getImage;
- (UIImage *)getImageThumbnail;

- (void)logImpression;
- (void)logClickthrough;

// Not currently supported
- (void)logInteraction;
- (void)logShare:(NSString *)shareType;

// Can be used for third-party analytics, runs at most once per sponsored image.
@property (nonatomic, copy) void (^logImpressionBlock)(TripleLiftSponsoredImage *image);
@property (nonatomic, copy) void (^logClickthroughBlock)(TripleLiftSponsoredImage *image);

@end
