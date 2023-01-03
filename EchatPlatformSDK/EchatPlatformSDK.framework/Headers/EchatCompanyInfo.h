//
//  EchatCompanyInfo.h
//  EchatPlatformSDK
//
//  Created by echat on 2022/12/23.
//  Copyright © 2022 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EchatCompanyInfo : NSObject
@property (nonatomic, assign) NSInteger unreadCount;
@property (nonatomic, copy) NSString * lastMsg;
@end

NS_ASSUME_NONNULL_END
