//
//  SequenceUtils.h
//  BaseProject
//
//  Created by Zachary Noe on 1/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef id (^ SequenceBlock)(id);
typedef BOOL (^ PredicateBlock)(id);

@interface NSArray (SequenceUtils)

- (NSArray *)mapWithBlock:(SequenceBlock)block;
- (NSArray *)filterWithBlock:(PredicateBlock)block;

- (BOOL)anyWithBlock:(PredicateBlock)block;
- (id)detectWithBlock:(PredicateBlock)block;

- (id)firstObject;

+ (NSArray *)arrayWithNumbersFromInts:(int)count, ...;

@end

@interface NSSet (SequenceUtils)

- (NSSet *)mapWithBlock:(SequenceBlock)block;
- (NSSet *)filterWithBlock:(PredicateBlock)block;

- (BOOL)anyWithBlock:(PredicateBlock)block;
- (id)detectWithBlock:(PredicateBlock)block;

@end

@interface NSDictionary (SequenceUtils)

- (NSDictionary *)mapWithBlock:(SequenceBlock)block;
- (NSDictionary *)mapKeysWithBlock:(SequenceBlock)block;
- (NSDictionary *)filterWithBlock:(PredicateBlock)block;
- (NSDictionary *)filterByKeyWithBlock:(PredicateBlock)block;

- (BOOL)anyWithBlock:(PredicateBlock)block;
- (BOOL)anyKeyWithBlock:(PredicateBlock)block;
- (id)detectWithBlock:(PredicateBlock)block;
- (id)detectKeyWithBlock:(PredicateBlock)block;

@end

@interface NSMutableArray (SequenceUtils)

- (void)addObjectToFront:(id)object;
- (void)removeFirstObject;

@end

@interface NSNumber (SimpleMath)

+ (NSNumber *)numberByAddingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSNumber *)numberBySubtractingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSNumber *)numberByMultiplyingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
+ (NSNumber *)numberByDividingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;

@end