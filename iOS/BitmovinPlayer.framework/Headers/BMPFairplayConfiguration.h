//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a FairPlay Streaming DRM configuration.
 */
NS_SWIFT_NAME(FairplayConfiguration)
@interface BMPFairplayConfiguration : BMPDRMConfiguration
@property (nonatomic, strong) NSURL *certificateUrl;
/** A dictionary to specify custom HTTP headers for the license request. */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *licenseRequestHeaders;
/** A dictionary to specify custom HTTP headers for the certificate request. */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *certificateRequestHeaders;
/**
 * An optional block to prepare the data which is sent as the body of the POST license request. As many DRM providers
 * expect different, vendor-specific messages, this can be done using this user-defined block.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareMessage)(NSData *spcData, NSString *assetID);
/**
 * An optional block to prepare the contentId, which is sent to the Fairplay license server as request body (optional),
 * and which is used to build the SPC data. As many DRM providers expect different, vendor-specific messages, this can
 * be done using this user-defined block. The parameter is the skd:// URI extracted from the HLS manifset (m3u8) and the return value
 * should be the contentID as string.
 */
@property (nonatomic, copy, nullable) NSString *(^prepareContentId)(NSString *contentId);
/**
 * An optional block to prepare the loaded certificate before building SPC data and passing it into the system. This is needed
 * if the server responds with anything else than the certificate, e.g. if the certificate is wrapped into a JSON object.
 * The server response for the certificate request is passed as parameter “as is”.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareCertificate)(NSData *certificate);
/**
 * An optional block to prepare the loaded CKC Data before passing it to the system. This is needed if the server responds
 * with anything else than the license, e.g. if the license is wrapped into a JSON object.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareLicense)(NSData *ckc);

- (instancetype)initWithUUID:(NSUUID *)uuid NS_UNAVAILABLE;
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_UNAVAILABLE;
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl certificateURL:(NSURL *)certificateUrl NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithCertificateURL:(NSURL *)certificateUrl;
@end

NS_ASSUME_NONNULL_END
