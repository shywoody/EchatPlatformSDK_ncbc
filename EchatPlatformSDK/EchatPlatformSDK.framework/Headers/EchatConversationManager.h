//
//  EchatConversationManager.h
//  EchatPlatformSDK
//
//  Created by mac on 2021/5/19.
//  Copyright © 2021 mac. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_MsgModel.h"
#import "Echat_visEvtModel.h"

typedef void(^UnReadMsgBlock)(Echat_MsgModel * _Nullable unReadMsg);

NS_ASSUME_NONNULL_BEGIN
@protocol EchatConversationDelegate <NSObject>

/*
 *           获取动态变化的未读消息总数(未读消息数变化回调)
 */
@optional
- (void)unReadMessagesSumCountChanged:(NSInteger)count;

/*
 *           动态获取未读消息
 */
@optional
- (void)getReceivedMessage:(Echat_MsgModel *)message;

@end

@interface EchatConversationManager : NSObject
@property (nonatomic, weak) id<EchatConversationDelegate> delegate;

+ (instancetype)manager;


/// 获取静态总数(用于主动获取非动态变化的未读消息总数)
- (NSInteger)getAllUnreadCountSum;


/// 获取静态未读消息数（获取对应公司的未读消息数）
/// @param companyId 公司id
- (NSInteger)getUnreadCountWithCompanyId:(NSInteger)companyId;


/// 发送文本(多商户)
/// @param msg 内容
/// @param companyId 公司Id
/// @param success 成功回调
/// @param fail 失败回调
+ (void)sendMessage:(NSString *)msg companyId:(NSString *)companyId Success:(dispatch_block_t)success Failure:(void(^)(NSString * errorMsg))fail;


/// 发送图文(多商户)
/// @param model 图文消息模型
/// @param companyId 公司Id
/// @param success 成功回调
/// @param fail 失败回调
+ (void)sendVisEvtWithVisEventModel:(Echat_visEvtModel *)model companyId:(NSString *)companyId Success:(dispatch_block_t)success Failure:(void(^)(NSString * errorMsg))fail;

/// 发送文本(单商户)
/// @param msg 内容
/// @param success 成功回调
/// @param fail 失败回调
+ (void)sendMessage:(NSString *)msg Success:(dispatch_block_t)success Failure:(void(^)(NSString * errorMsg))fail;


/// 发送图文(单商户)
/// @param model 图文消息模型
/// @param success 成功回调
/// @param fail 失败回调
+ (void)sendVisEvtWithVisEventModel:(Echat_visEvtModel *)model Success:(dispatch_block_t)success Failure:(void(^)(NSString * errorMsg))fail;


/// 发送地理位置信息
/// @param info 位置消息字典,格式见文档
+(void)sendLocationInfo:(NSDictionary *)info;


/// 切换路由
/// @param echatTag 路由标签
/// @param success 成功回调
/// @param fail 失败回调
+ (void)changeOtherRoute:(NSString *)echatTag success:(dispatch_block_t)success fail:(void(^)(NSString * errorMsg))fail;


/// 匿名访客转会员
/// @param metaStr 会员信息加密字符串
/// @param uid 与metaData配对唯一标识
/// @param success 成功回调
/// @param fail 失败回调
+(void)anonymousVisitorRegistMetaData:(NSString *)metaStr UId:(NSString *)uid success:(dispatch_block_t)success fail:(void(^)(NSString * errorMsg))fail;


/// 关闭连接
+ (void)disConnect;

/// 关闭当前所有对话
/// @param success 成功回调
/// @param fail 失败回调
+ (void)closeAllConversationSuccess:(dispatch_block_t _Nullable)success fail:(void(^)(NSString * _Nullable errorMsg))fail;

@end

NS_ASSUME_NONNULL_END
