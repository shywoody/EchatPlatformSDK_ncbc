//
//  EchatConfig.h
//  EchatPlatformSDK
//
//  Created by shywoody on 2023/2/4.
//  Copyright © 2023 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
//Echat配置单例
@interface EchatConfig : NSObject

/*
 权限额外提示UI相关配置
 */

///额外权限提示UI开关,默认关闭
@property(nonatomic,assign) BOOL openExtralPrivacyNote;
///额外权限UI提示背景色,默认白色
@property(nonatomic,strong) UIColor * extralPrivacyNoteBgColor;
///额外权限UI标题颜色,默认黑色
@property(nonatomic,strong) UIColor * extralPrivacyNoteTitleColor;
///额外权限UI权限描述文字颜色, 默认淡灰色
@property(nonatomic,strong) UIColor * extralPrivacyNoteSubTitleColor;

///初始化
+(instancetype)config;
@end

NS_ASSUME_NONNULL_END
