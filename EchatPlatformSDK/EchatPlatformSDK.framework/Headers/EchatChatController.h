//
//  EchatChatViewController.h
//  EchatPlatformSDK
//
//  Created by mac on 2020/9/7.
//  Copyright © 2020 mac. All rights reserved.
//

#import <UIKit/UIKit.h>

@class EchatImageMessage;
@class EchatVideoModel;
@class Echat_accessConditions;

NS_ASSUME_NONNULL_BEGIN

typedef void(^EchatVisEvtCallBack)(NSString * data);

@interface EchatChatController : UIViewController

/*设置navigationItem图片,传入imageName
 如果要同时设置UIControlStateHighlighted图片 预备两张名为图片 A 与 A_highlighted*/

///leftItemImageName
@property(nonatomic,copy) NSString * leftItemImageName;

///rightItemImageName
@property(nonatomic,copy) NSString * rightItemImageName;

///图文消息如果type是custom则会返回字段供开发者自己去操作
@property (nonatomic,copy) EchatVisEvtCallBack visEvtCallBackblock;

///自定义图库控制器
@property (nonatomic,strong) UIViewController * imagePickerLoaderViewController;

///自定义地理位置控制器
@property (nonatomic, strong) UIViewController * mapLoaderViewController;

///默认为YES,控制器内部设置了Navigation左右item,分别为返回back和对话关闭功能closeConversation
@property (nonatomic, assign) BOOL defaultNavigationItemVisualable;

///initlize
+ (instancetype)chatWithCondition:(Echat_accessConditions *)condition;


/// 接管url链接方法
/// @param info url参数包含地址和类型
- (BOOL)echat_OpenLink:(NSDictionary *)info;


/// 图片预览功能接管
/// @param dict 预览图片信息
//-(void)echat_PreviewImages:(NSDictionary *)dict;
-(void)echat_PreviewImages:(EchatImageMessage *)imageMessage;


/// 视频播放接管
/// @param model 视频模型
-(void)echat_bridge4playVideo:(EchatVideoModel *)model;



/// 地理位置发送控制器接管
- (void)echat_openMap;

#pragma mark -- 导航栏按钮方法
///左侧按钮点击事件（返回）
- (void)back;

///右侧按钮点击事件（结束当前对话）
- (void)closeConversation;
@end

NS_ASSUME_NONNULL_END
