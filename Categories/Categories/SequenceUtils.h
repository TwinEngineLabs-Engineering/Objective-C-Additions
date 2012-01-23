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

/** 
 @return An array whose contents have had the operation in the block param applied to them
 @param block - A block which takes an object as a parameter and returns that object which has been modified
 */
- (NSArray *)mapWithBlock:(SequenceBlock)block;
/** 
 @return An array whose contents match the conditions specified in the block parameter
 @param block - A block which takes a single object and returns YES or NO based on some condition which will filter the contents of the array.
 */
- (NSArray *)filterWithBlock:(PredicateBlock)block;
/** 
 @return A boolean indicating whether any of the contents of this array matches the predicate specified in the block.
 @param block - A block containing a test for the elements of this array
 */
- (BOOL)anyWithBlock:(PredicateBlock)block;
/** 
 @return The first object to match the conditions specified in the block paramter
 @param block - A block containing a test for the elements of this array
 */
- (id)detectWithBlock:(PredicateBlock)block;

/** 
 Same as calling [self objectAtIndex:0]
 @return firstObject - The first object in the array. Returns nil if array is empty
 */
- (id)firstObject;

/** 
 @return NSArray of NSNumber objects which wrap the integers specified 
 */
+ (NSArray *)arrayWithNumbersFromInts:(int)first, ... NS_REQUIRES_NIL_TERMINATION;

@end

@interface NSSet (SequenceUtils)
/** 
 @return A set whose contents have had the operation in the block param applied to them
 @param block - A block which takes an object as a parameter and returns that object which has been modified
 */
- (NSSet *)mapWithBlock:(SequenceBlock)block;
/** 
 @return An set whose contents match the conditions specified in the block parameter
 @param block - A block which takes a single object and returns YES or NO based on some condition which will filter the contents of the array.
 */
- (NSSet *)filterWithBlock:(PredicateBlock)block;
/** 
 @return A boolean indicating whether any of the contents of this set matches the predicate specified in the block
 @param block - A block containing a test for the elements of this set
 */
- (BOOL)anyWithBlock:(PredicateBlock)block;
/** 
 @return The first object to match the conditions specified in the block paramter
 @param block - A block containing a test for the elements of this set
 */
- (id)detectWithBlock:(PredicateBlock)block;

@end

@interface NSDictionary (SequenceUtils)
/** 
 @return A dictionary whose values have had the operation in the block param applied to them
 @param block - A block which takes an object as a parameter and returns that object which has been modified
 */
- (NSDictionary *)mapWithBlock:(SequenceBlock)block;
/** 
 @return A dictionary whose keys have had the operation in the block param applied to them
 @param block - A block which takes an object as a parameter and returns that object which has been modified
 */
- (NSDictionary *)mapKeysWithBlock:(SequenceBlock)block;
/** 
 @return A dictionary whose values match the conditions specified in the block parameter
 @param block - A block which takes a single object and returns YES or NO based on some condition which will filter the values of the dictionary.
 */
- (NSDictionary *)filterWithBlock:(PredicateBlock)block;
/** 
 @return An dictionary whose keys match the conditions specified in the block parameter
 @param block - A block which takes a single object and returns YES or NO based on some condition which will filter the keys of the dictionary.
 */
- (NSDictionary *)filterByKeyWithBlock:(PredicateBlock)block;
/** 
 @return A boolean indicating whether any of the values of this dictionary match the predicate specified in the block
 @param block - A block containing a test for the values of this dictionary
 */
- (BOOL)anyWithBlock:(PredicateBlock)block;
/** 
 @return A boolean indicating whether any of the keys of this dictionary matches the predicate specified in the block
 @param block - A block containing a test for the keys of this dictionary
 */
- (BOOL)anyKeyWithBlock:(PredicateBlock)block;
/** 
 @return The first value of the dictionary to match the conditions specified in the block paramter
 @param block - A block containing a test for the values of this dictionary
 */
- (id)detectWithBlock:(PredicateBlock)block;
/** 
 @return The first key of the dictionary to match the conditions specified in the block paramter
 @param block - A block containing a test for the keys of this dictionary
 */
- (id)detectKeyWithBlock:(PredicateBlock)block;

@end

@interface NSMutableArray (SequenceUtils)

/** 
 Adds an object to the front of the array
 @param object - The object to add to the front of the array
 */
- (void)addObjectToFront:(id)object;
/**
 Removes the object at index 0
 */
- (void)removeFirstObject;

@end

@interface NSNumber (SimpleMath)

/** 
 Sums all the parameters
 @return NSNumber which is the sum of all the parameters */
+ (NSNumber *)numberByAddingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
/** 
 Subtracts every parameter from the first parameter
 @return NSNumber which is the sum of the first parameter and the negation of every other
 */
+ (NSNumber *)numberBySubtractingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
/**
 Multiplies all numbers specified as paramters
 @return NSNumber which is the product of all parameters
 */
+ (NSNumber *)numberByMultiplyingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;
/** 
 Divides the first parameter by the product of every other parameter
 @return NSNumber which is the quotient of the first parameter and the rest of the parameters' product
 */
+ (NSNumber *)numberByDividingNumbers:(NSNumber *)firstNumber, ... NS_REQUIRES_NIL_TERMINATION;

@end