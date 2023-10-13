//
//  EchatUserInfo.h
//  EchatPlatformSDK
//
//  Created by echat on 2023/7/14.
//  Copyright © 2023 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EchatUserInfo : NSObject
/**
 * 会员的唯一值 （vip=1时必须）支持数字、英文大小写、字符。 其中支持字符如下：!，#，$，(，)，*，+，-，.，@，_，{，~，} 传入不支持字符当做匿名访客处理
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * uid;

/**
 * 当前客户信息是否为会员客户信息，如果为会员客户信息，那么所有渠道（PC、手机、app、微信D)的访客身份将保持统一一洽会识别为同一个访客。
 * 1:会员 默认为1。如果传递的客户信息为非会员信息那么会员的访客ID则使用一洽识别的当前渠道ID
 */
@property (nonatomic, assign) int vip;

/**
 * 会员级别 传值： 0 / 1 / 2 / 3 ...
 */
@property (nonatomic, copy) NSString * grade;

/**
 * 会员类别 例如：金牌会员
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * category;

/**
 * 会员姓名 例如：王宝强
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * name;

/**
 * 会员的昵称 例如：宝宝
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * nickName;

/**
 * 会员的性别
 * 0-未知， 1-男， 2-女
 */
@property (nonatomic, assign) NSUInteger gender;

/**
 * 会员的年龄
 * >=0; <=100
 */
@property (nonatomic, assign) NSUInteger age;

/**
 * 会员的生日 例如：1990-08-01
 * 格式yyyy-MM-dd
 */
@property (nonatomic, copy) NSString * birthday;

/**
 * 婚姻状况 1：未婚 2：已婚 0：未知
 */
@property (nonatomic, copy) NSString * maritalStatus;

/**
 * 会员的联系电话
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * phone;

/**
 * 会员的QQ号码
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * qq;

/**
 * 会员的微信号码
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * wechat;

/**
 * 会员的邮箱
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * email;

/**
 * 会员的国家
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * nation;

/**
 * 会员的省份
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * province;

/**
 * 会员的城市
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * city;

/**
 * 会员的地址
 * 最长不超过50位
 */
@property (nonatomic, copy) NSString * address;

/**
 * 会员的头像地址
 * 最长不超过255位
 */
@property (nonatomic, copy) NSString * photo;

/**
 * 会员备注信息
 * 最长不超过255位
 */
@property (nonatomic, copy) NSString * memo;

/**
 * 会员自定义字段
 * 最长不超过255位
 */

@property (nonatomic, copy) NSString * c1;
@property (nonatomic, copy) NSString * c2;
@property (nonatomic, copy) NSString * c3;
@property (nonatomic, copy) NSString * c4;
@property (nonatomic, copy) NSString * c5;
@property (nonatomic, copy) NSString * c6;
@property (nonatomic, copy) NSString * c7;
@property (nonatomic, copy) NSString * c8;
@property (nonatomic, copy) NSString * c9;
@property (nonatomic, copy) NSString * c10;
@property (nonatomic, copy) NSString * c11;
@property (nonatomic, copy) NSString * c12;
@property (nonatomic, copy) NSString * c13;
@property (nonatomic, copy) NSString * c14;
@property (nonatomic, copy) NSString * c15;
@property (nonatomic, copy) NSString * c16;
@property (nonatomic, copy) NSString * c17;
@property (nonatomic, copy) NSString * c18;
@property (nonatomic, copy) NSString * c19;
@property (nonatomic, copy) NSString * c20;

@end

NS_ASSUME_NONNULL_END
