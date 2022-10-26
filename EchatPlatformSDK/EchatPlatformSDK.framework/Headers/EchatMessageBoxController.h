//
//  EchatMessageBoxController.h
//  EchatPlatformSDK
//
//  Created by mac on 2020/9/9.
//  Copyright © 2020 mac. All rights reserved.
//

#import <UIKit/UIKit.h>
@class Echat_accessConditions;
@class EchatChatController;

NS_ASSUME_NONNULL_BEGIN

typedef EchatChatController *_Nonnull(^Echat_PushToChatControllerCallback)(Echat_accessConditions * condition);

@interface EchatMessageBoxController : UIViewController
@property (atomic, assign, readonly) NSInteger unreadCountSum;//未读消息总数
@property (nonatomic, copy) Echat_PushToChatControllerCallback  pushToChatControllerCallback;

//返回方法
- (void)back;

//清除唯独消息条数
- (void)cleanUnread;
@end

NS_ASSUME_NONNULL_END
