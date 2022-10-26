//
//  Echat_unReadMsg.h
//  EchatVisitorPort
//
//  Created by mac on 2019/3/28.
//  Copyright © 2019年 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, Echat_MsgType){
    EchatMsgTextType = 1 << 0,    //访客发送消息
    EchatMsgNewsType = 1 << 1,    //客服消息
    EchatMsgPushUrlType = 1 << 2, //pushUrl
    EchatMsgFileType = 1 << 3,     //文件类型
    EchatMsgImageType = 1 << 4,     //图片类型
    EchatMsgVideoType = 1 << 5,     //视频类型
    EchatMsgVoiceType = 1 << 6,     //语音类型
    EchatMsgWaitType = 1 << 7,     //消息类型
    EchatMsgSystemType = 1 << 8,     //系统消息
    EchatMsgLocationType = 1 << 9,     //位置消息
};


@interface Echat_MsgModel : NSObject

///标题
@property (nonatomic, copy) NSString * title;

///公司名称
@property (nonatomic, copy) NSString * companyName;

///内容
@property (nonatomic, copy) NSString * content;

///排队位置
@property (nonatomic, assign) NSInteger position;

///公司Id
@property (nonatomic, assign) NSInteger companyId;

///类型
@property (nonatomic, assign) Echat_MsgType msgType;

///需要进行推送
@property (nonatomic, assign) BOOL needLocalPush;

///时间戳
@property (nonatomic, assign) NSInteger tm;

///推送时间间隔(单位:s)
@property (nonatomic, assign) NSTimeInterval interval;

@end
