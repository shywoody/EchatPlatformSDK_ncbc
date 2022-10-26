//
//  EchatPlatformSDK.h
//  EchatPlatformSDK
//
//  Created by mac on 2020/7/15.
//  Copyright © 2020 mac. All rights reserved.
//


#import <UIKit/UIKit.h>

//! Project version number for EchatPlatformSDK.
FOUNDATION_EXPORT double EchatPlatformSDKVersionNumber;

//! Project version string for EchatPlatformSDK.
FOUNDATION_EXPORT const unsigned char EchatPlatformSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <EchatPlatformSDK/PublicHeader.h>

#import "EchatSDK.h"

///对话管理
#import "EchatConversationManager.h"

///对话控制器
#import "EchatChatController.h"

///消息盒子控制器
#import "EchatMessageBoxController.h"


///单商户对话初始化模型
#import "Echat_accessConditions.h"

///多商户对话初始化模型
#import "Echat_PlatFromConditions.h"

///图文模型
#import "Echat_visEvtModel.h"

///图片
#import "EchatImageModel.h"

///视频
#import "EchatVideoModel.h"

///订阅
#import "EchatSubscribeMsgModel.h"

///消息
#import "Echat_MsgModel.h"
