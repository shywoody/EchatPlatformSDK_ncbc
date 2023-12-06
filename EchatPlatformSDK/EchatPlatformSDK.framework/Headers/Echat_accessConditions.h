//
//  Echat_accessConditions.h
//  EchatSDKDemo
//
//  Created by xll on 2018/6/22.
//  Copyright © 2018年 xielang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Echat_visEvtModel.h"




@interface Echat_accessConditions : NSObject<NSCoding>

/* 当是单商户接入时,shopId为单商户companyId
 * 当为多商户时候shopId为每个不同的商户的不同companyId
 * 必填参数
 */
@property (nonatomic, assign) NSInteger shopId;

///自定义扩展参数
@property (nonatomic, copy) NSString  * myData;

///消息推送字段
@property (nonatomic, copy) NSString  * pushInfo;

///入口/入口标签
@property (nonatomic, copy) NSString  * echatTag;

///图文消息
@property (nonatomic, strong) Echat_visEvtModel  * visEvt;

///咨询入口id
@property (nonatomic, copy) NSString * routeEntranceId;

///指派接待客服的ID
@property (nonatomic,copy) NSString * acdStaffId;

///分配优先级，0-优先，1-指派
@property (nonatomic,copy) NSString * acdType;

///访客自动默认发出第一条消息(默认: 无)
/*
 *   1 文本消息
 *   msgType        String      text
 *   content        String      文本内容,支持html最大长度限制10000
 *
 *   2 图片消息
 *   msgType        String      image
 *   picUrl         String      图片地址,对大长度限制1024
 *   thumbUrl       String      图片缩略图地址,最大长度限制1024
 *
 *   3 视频消息
 *   msgType        String      video
 *   fileUrl        String      文件地址
 *   fileName       String      文件名称
 *   fileSize       number      文件大小(kb)
 *   thumbUrl       String      视频缩略图地址
 *
 *   4 文件
 *   msgType        String      file
 *   fileUrl        String      文件地址,最大长度：1024
 *   fileName       String      文件名称,最大长度：1024
 *   fileSize       number      文件大小(kb)
 */
@property (nonatomic,strong) NSDictionary * fm;

@end

