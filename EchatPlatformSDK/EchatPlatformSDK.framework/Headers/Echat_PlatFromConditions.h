//
//  Echat_accessConditions+EchatPlatForm.h
//  EchatPlatformSDK
//
//  Created by mac on 2020/9/16.
//  Copyright © 2020 mac. All rights reserved.
//


#import "Echat_accessConditions.h"

NS_ASSUME_NONNULL_BEGIN

@interface Echat_accessConditions (EchatPlatForm)

/* 当是单商户接入时,shopId为单商户companyId
 * 当为多商户时候shopId为每个不同的商户的不同companyId
 */
@property (nonatomic, assign) NSInteger shopId;

//暂时未开放, 在客服端均可进行设置
@property (nonatomic, copy) NSString * shopCoverImageUrlString;
@property (nonatomic, copy) NSString * shopTitle;

@end

NS_ASSUME_NONNULL_END
