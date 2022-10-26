//
//  Echat_visEvtModel.h
//  EchatSDKDemo
//
//  Created by xll on 2018/6/22.
//  Copyright © 2018年 xielang. All rights reserved.
//

//图文消息
#import <Foundation/Foundation.h>
@interface Echat_visEvtModel : NSObject<NSCoding>
///文本内容
@property (nonatomic,copy) NSString  * content;
///图文消息类型
@property (nonatomic,strong) NSNumber * customizeMsgType;
///是否重复发送,0可重复,1去重
@property (nonatomic,strong) NSNumber *  dedup;
///图文消息Id
@property (nonatomic,copy) NSString  * eventId;
///图文图片地址
@property (nonatomic,copy) NSString  * imageUrl;
///图文消息的描述
@property (nonatomic,copy) NSString  * memo;
///标题
@property (nonatomic,copy) NSString  * title;
///图文消息提供给访客打开的url
@property(nonatomic,copy) NSString * urlForVisitor;
///图文消息提供给客服打开的url，可以为空
@property(nonatomic,copy) NSString * urlForStaff;
///图文消息的可见范围.1:访客客服都可见（默认）2:只有客服可见，访客不可见
@property(nonatomic,strong) NSNumber *  visibility;
///访客是否可点击图文消息打开设置的url
@property(nonatomic,strong) NSNumber *  urlEnableForVisitor;

@end
