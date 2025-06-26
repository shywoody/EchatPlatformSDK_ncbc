//
//  EchatSDK.h
//  EchatSDKDemo
//
//  Created by mac on 2018/7/19.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_MsgModel.h"
#import "EchatSubscribeMsgModel.h"
#import "EchatUserInfo.h"


@class Echat_accessConditions;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
@class UNNotificationResponse;
#endif


@interface EchatSDK : NSObject
@property(nonatomic,readonly,assign) BOOL openDebug;
@property(nonatomic,readonly,assign) BOOL sdkInitlized;



+(instancetype)share;

//单商户初始化
//---------------------------------------------------------------------

/// 单商户初始化
/// @param appid appId
/// @param appsecret appSecret
/// @param companyId 公司Id
+ (void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret CompanyId:(NSString *)companyId DEPRECATED_MSG_ATTRIBUTE("Please use [EchatSDK startSDKWithAppID:AppSecret:serverAppId:serverEncodingKey:serverToken:companyId:serverUrl:]");


/// 单商户初始化(私有云)
/// @param appid appId
/// @param appsecret appSecret
/// @param companyId 公司Id
/// @param server 私有云地址形如https://xxx.xxxxx.com
+(void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret CompanyId:(NSString *)companyId server:(NSString *)server DEPRECATED_MSG_ATTRIBUTE("Please use [EchatSDK startSDKWithAppID:AppSecret:serverAppId:serverEncodingKey:serverToken:companyId:serverUrl:]");

//多商户初始化
//---------------------------------------------------------------------

/// 多商户平台接入
/// @param appid appId
/// @param appsecret appSecret
/// @param platFormId 平台Id
/// @param apiAppId APIAPPId
/// @param apiToken APIToken
+ (void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret PlatFormId:(NSString *)platFormId APIAppId:(NSString *)apiAppId APIToken:(NSString *)apiToken DEPRECATED_MSG_ATTRIBUTE("Please use [EchatSDK startSDKWithAppID:AppSecret:serverAppId:serverEncodingKey:serverToken:companyId:serverUrl:]");

/// 多商户平台接入(私有云)
/// @param appid appId
/// @param appsecret appSecret
/// @param platFormId 平台Id
/// @param apiAppId APIAPPId
/// @param apiToken APIToken
/// @param server 私有云地址形如https://e.echatsoft.com
+ (void)AppID:(NSString *)appid AppSecret:(NSString *)appsecret PlatFormId:(NSString *)platFormId APIAppId:(NSString *)apiAppId APIToken:(NSString *)apiToken server:(NSString *)server DEPRECATED_MSG_ATTRIBUTE("Please use [EchatSDK startSDKWithAppID:AppSecret:serverAppId:serverEncodingKey:serverToken:companyId:serverUrl:]");


/// 新初始化接口
/// @param appid appId
/// @param appsecret appSecret
/// @param serverAppId API接入APPID
/// @param serverEncodingKey 消息加密Key
/// @param serverToken API接入Token
/// @param companyId 公司Id, 如果是多商户接入则写入平台公司Id，如果是单商户接入则写入公司Id
+ (void)startSDKWithAppID:(NSString *)appid
    AppSecret:(NSString *)appsecret
  serverAppId:(NSString *)serverAppId
serverEncodingKey:(NSString *)serverEncodingKey
  serverToken:(NSString *)serverToken
    companyId:(NSString *)companyId;


/// 新初始化接口(带服务器地址)
/// @param appid appId
/// @param appsecret appSecret
/// @param serverAppId API接入APPID
/// @param serverEncodingKey 消息加密Key
/// @param serverToken API接入Token
/// @param companyId 公司Id, 如果是多商户接入则写入平台公司Id，如果是单商户接入则写入公司Id
/// @param serverUrl 私有云服务器地址，形如https://xxx.xxxx.com
+ (void)startSDKWithAppID:(NSString *)appid
    AppSecret:(NSString *)appsecret
  serverAppId:(NSString *)serverAppId
serverEncodingKey:(NSString *)serverEncodingKey
  serverToken:(NSString *)serverToken
    companyId:(NSString *)companyId
    serverUrl:(NSString *)serverUrl;

#pragma mark -- 对外接口

/// 自主上传获取uploadInfo
/// @param fileType 文件类型-1语音、2视频、4图片、0其他
/// @param duration 语音时长(是语音文件传入, 单位：ms)
/// @param success 成功信息回调
/// @param fail 失败回调
+ (void)echat_getFileUploadInfoWithFileType:(NSInteger)fileType
                          haveVoiceduration:(NSNumber *)duration
                                    Success:(void (^)(NSDictionary * info))success
                                    failure:(void (^)(NSString * errorMsg))fail;

#pragma mark -- 推送
/// 注册token
/// @param deviceToken 上传推送证书至echat, 建立推送服务时, pushInfo为deviceTokenData
+ (void)echat_registPushInfo:(NSData *)deviceToken;

///设置pushInfo
/// @param pushInfo 通过指定服务器接收推送消息, 由开发者自行建立推送服务时,pushInfo为任意约定字符串(要求:能自行识别来自于那种设备类型)
+ (void)echat_setPushInfo:(NSString *)pushInfo;

#pragma mark -- 会员信息
/// 登陆
/// @param uid 唯一id
/// @param metaData 会员信息
/// @param callBack 状态回调
+ (void)echat_SDKLoginWithUid:(NSString *)uid
                     MetaData:(NSString *)metaData
               StatusCallback:(void(^)(BOOL flag,NSString * message))callBack;

/// 登出
/// @param uid 唯一id
/// @param success 成功回调
/// @param fail 失败回调
+ (void)echat_SDKLogoutWithUid:(NSString *)uid
                          Success:(dispatch_block_t)success
                             fail:(void(^)(NSString * errorMessage))fail;


/// 判断当前用户是否已经登陆会员(静态)
/// @param uid 唯一Id
+ (BOOL)echat_isLogin:(NSString *)uid;


/// 判断当前用户是否已经登陆会员(动态)
/// @param uid 唯一Id
/// @param callBack 系统登陆状态回调(状态变动也会回调,一般不做判断依据,需要保证metaData的正确性)
+ (void)echat_isLogin:(NSString *)uid StatusCallback:(void(^)(BOOL flag,NSString * message))callBack;


/// 更新会员信息
/// @param metaDataString 更新后的会员信息
/// @param uid 身份标识
/// @param complete 成功回调
/// @param fail 失败回调
+ (void)echat_updateMetaData:(NSString *)metaDataString UId:(NSString *)uid Success:(dispatch_block_t)complete fail:(void(^)(NSString *errorMessage))fail;


/// 设置会员信息
+ (void)setUserInfo:(EchatUserInfo *)userInfo;

/// 获取会员信息
+ (EchatUserInfo *)getUserInfo;

///清除会员信息
+ (void)clearUserInfo;


#pragma mark -- 对话相关
/// 获取入口参数
/// @param companyId 通过公司Id去获取入口参数,只有已经建立过对话的才会查询到
+ (Echat_accessConditions *)getConditionWithCompanyId:(NSInteger)companyId;


/// 获取当前栈顶控制器 (如果包含聊天控制器,会尝试移除(存在无法移除现象,因为测试场景可能无法全部涵盖。若无法移除则需要开发者自定义跳转))
+ (id)getCurrentViewController;

#pragma mark -- 推送
//iOS 10 之前
+ (void)echat_hanleUserNotificationBefore10WithInfo:(NSDictionary * )info;


//iOS 10 之后
+ (void)echat_hanleUserNotificationAfter10WithResponse:(UNNotificationResponse *)response API_AVAILABLE(ios(10.0));


#pragma mark -- 功能开关

/// 本地推送
/// @param open 是否关闭,默认开启
+ (void)echat_DefaultNotification:(BOOL)open;


/// 地理位置信息功能
/// @param open 是否开启位置信息功能,需要引用EchatCommen和引入高德地图,默认关闭
+ (void)echat_DefaultLocationFunction:(BOOL)open;


/// 消息震动提醒
/// @param open 是否开启消息震动提示功能(默认开启)
+ (void)echat_DefaultMessageVibration:(BOOL)open;


/// 获取未读消息数轮询
/// @param open 是否开启(默认关闭,当不接入远程推送,也希望尽量去获得准确未读消息数)
+ (void)echat_UnReadCountPolling:(BOOL)open;


/// 消息复制功能
/// @param open 是否关闭消息复制功能:(默认开启)
+ (void)echat_LongpressCopyMessageFunction:(BOOL)open;
#pragma mark -- 设置

/// 全局语言设置
/// @param lan (eg: @"zh", @"en") 需要在初始化SDK之前进行设置,默认为系统语言,对话中途修改语言会在下次对话生效
+ (void)echat_setLan:(NSString *)lan;


/// 打开隐私权限（app上架所在国家或者区域会需要禁止相册权限可以开启隐私权限,同时需要最低支持iOS11）
+ (void)openHighPrivacy;


/// 获取SDK版本
+ (NSString *)sdkversion;
#pragma mark -- 清理

///获取缓存大小
+ (double)getMemorySize;

/// 清理全部缓存
+ (void)cleanAllMemory;

@end
