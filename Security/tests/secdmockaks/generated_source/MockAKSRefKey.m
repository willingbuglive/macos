// This file was automatically generated by protocompiler
// DO NOT EDIT!
// Compiled from MockAKSRefKey.proto

#import "MockAKSRefKey.h"
#import <ProtocolBuffer/PBConstants.h>
#import <ProtocolBuffer/PBHashUtil.h>
#import <ProtocolBuffer/PBDataReader.h>

#if !__has_feature(objc_arc)
# error This generated file depends on ARC but it is not enabled; turn on ARC, or use 'objc_use_arc' option to generate non-ARC code.
#endif

@implementation MockAKSRefKey

- (BOOL)hasKey
{
    return _key != nil;
}
@synthesize key = _key;
- (BOOL)hasOptionalParams
{
    return _optionalParams != nil;
}
@synthesize optionalParams = _optionalParams;

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@ %@", [super description], [self dictionaryRepresentation]];
}

- (NSDictionary *)dictionaryRepresentation
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    if (self->_key)
    {
        [dict setObject:self->_key forKey:@"key"];
    }
    if (self->_optionalParams)
    {
        [dict setObject:self->_optionalParams forKey:@"optional_params"];
    }
    return dict;
}

BOOL MockAKSRefKeyReadFrom(__unsafe_unretained MockAKSRefKey *self, __unsafe_unretained PBDataReader *reader) {
    while (PBReaderHasMoreData(reader)) {
        uint32_t tag = 0;
        uint8_t aType = 0;

        PBReaderReadTag32AndType(reader, &tag, &aType);

        if (PBReaderHasError(reader))
            break;

        if (aType == TYPE_END_GROUP) {
            break;
        }

        switch (tag) {

            case 1 /* key */:
            {
                NSData *new_key = PBReaderReadData(reader);
                self->_key = new_key;
            }
            break;
            case 2 /* optionalParams */:
            {
                NSData *new_optionalParams = PBReaderReadData(reader);
                self->_optionalParams = new_optionalParams;
            }
            break;
            default:
                if (!PBReaderSkipValueWithTag(reader, tag, aType))
                    return NO;
                break;
        }
    }
    return !PBReaderHasError(reader);
}

- (BOOL)readFrom:(PBDataReader *)reader
{
    return MockAKSRefKeyReadFrom(self, reader);
}
- (void)writeTo:(PBDataWriter *)writer
{
    /* key */
    {
        if (self->_key)
        {
            PBDataWriterWriteDataField(writer, self->_key, 1);
        }
    }
    /* optionalParams */
    {
        if (self->_optionalParams)
        {
            PBDataWriterWriteDataField(writer, self->_optionalParams, 2);
        }
    }
}

- (void)copyTo:(MockAKSRefKey *)other
{
    if (_key)
    {
        other.key = _key;
    }
    if (_optionalParams)
    {
        other.optionalParams = _optionalParams;
    }
}

- (id)copyWithZone:(NSZone *)zone
{
    MockAKSRefKey *copy = [[[self class] allocWithZone:zone] init];
    copy->_key = [_key copyWithZone:zone];
    copy->_optionalParams = [_optionalParams copyWithZone:zone];
    return copy;
}

- (BOOL)isEqual:(id)object
{
    MockAKSRefKey *other = (MockAKSRefKey *)object;
    return [other isMemberOfClass:[self class]]
    &&
    ((!self->_key && !other->_key) || [self->_key isEqual:other->_key])
    &&
    ((!self->_optionalParams && !other->_optionalParams) || [self->_optionalParams isEqual:other->_optionalParams])
    ;
}

- (NSUInteger)hash
{
    return 0
    ^
    [self->_key hash]
    ^
    [self->_optionalParams hash]
    ;
}

- (void)mergeFrom:(MockAKSRefKey *)other
{
    if (other->_key)
    {
        [self setKey:other->_key];
    }
    if (other->_optionalParams)
    {
        [self setOptionalParams:other->_optionalParams];
    }
}

@end

