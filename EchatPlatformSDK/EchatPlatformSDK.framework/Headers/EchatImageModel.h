//
//  EchatImageModel.h
//  EchatPlatformSDK
//
//  Created by shywoody on 2022/2/8.
//  Copyright © 2022 mac. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface EchatImageModel : NSObject

@property(nonatomic, copy) NSString * smallImg;
@property(nonatomic, copy) NSString * bigImg;
@property(nonatomic, copy) NSString * sourceImg;
@property(nonatomic, copy) NSString * fileName;
@property(nonatomic, copy) NSString * localFile;
@property(nonatomic, copy) NSString * clientFileId;
@property(nonatomic, copy) NSString * identityKey;

@end

@interface EchatImageMessage : NSObject

@property(nonatomic, assign) NSInteger current;

@property(nonatomic, strong) NSArray<EchatImageModel*>* urls;

@property(nonatomic, assign) BOOL isOrignal;

@end




