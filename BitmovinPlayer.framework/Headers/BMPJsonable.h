//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Jsonable)
@protocol BMPJsonable <NSObject>
- (nullable NSString *)toJsonString:(NSError **)error;
- (NSDictionary *)toJsonData;
@end

NS_ASSUME_NONNULL_END