// This file was automatically generated by protocompiler
// DO NOT EDIT!
// Compiled from SecDbBackupRecoverySet.proto

#import <Foundation/Foundation.h>
#import <ProtocolBuffer/PBCodable.h>

@class SecDbBackupBagIdentity;

#ifdef __cplusplus
#define SECDBBACKUPRECOVERYSET_FUNCTION extern "C"
#else
#define SECDBBACKUPRECOVERYSET_FUNCTION extern
#endif

/**
 *    optional bytes aksWrappedMetadataKey = 3;     // wrapped by device bag for daily use. Not in use right now.
 * Insert into backuprecoverysets table, v12_recoverySet column
 */
@interface SecDbBackupRecoverySet : PBCodable <NSCopying>
{
    SecDbBackupBagIdentity *_bagIdentity;
    int32_t _recoveryType;
    NSData *_wrappedBagSecret;
    NSData *_wrappedKCSKSecret;
    NSData *_wrappedRecoveryKey;
    struct {
        int recoveryType:1;
    } _has;
}


@property (nonatomic) BOOL hasRecoveryType;
@property (nonatomic) int32_t recoveryType;

@property (nonatomic, readonly) BOOL hasBagIdentity;
@property (nonatomic, retain) SecDbBackupBagIdentity *bagIdentity;

@property (nonatomic, readonly) BOOL hasWrappedBagSecret;
/** 'passphrase' to unlock backup bag's private keys */
@property (nonatomic, retain) NSData *wrappedBagSecret;

@property (nonatomic, readonly) BOOL hasWrappedKCSKSecret;
/** recovers KCSKs to verify authenticity of IKs and MCKs */
@property (nonatomic, retain) NSData *wrappedKCSKSecret;

@property (nonatomic, readonly) BOOL hasWrappedRecoveryKey;
/** wraps the above two secrets */
@property (nonatomic, retain) NSData *wrappedRecoveryKey;

// Performs a shallow copy into other
- (void)copyTo:(SecDbBackupRecoverySet *)other;

// Performs a deep merge from other into self
// If set in other, singular values in self are replaced in self
// Singular composite values are recursively merged
// Repeated values from other are appended to repeated values in self
- (void)mergeFrom:(SecDbBackupRecoverySet *)other;

SECDBBACKUPRECOVERYSET_FUNCTION BOOL SecDbBackupRecoverySetReadFrom(__unsafe_unretained SecDbBackupRecoverySet *self, __unsafe_unretained PBDataReader *reader);

@end

