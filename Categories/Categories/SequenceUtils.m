//
//  SequenceUtils.m
//  BaseProject
//
//  Created by Zachary Noe on 1/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "SequenceUtils.h"

@implementation NSArray (SequenceUtils)

- (id)firstObject {
  return self.count > 0 ? [self objectAtIndex:0] : nil;
}

- (NSArray *)mapWithBlock:(SequenceBlock)block {
  NSMutableArray *mAry = [[NSMutableArray alloc] initWithCapacity:[self count]];
  
  for (id element in self) {
    [mAry addObject:block(element)];
  }
  
  return [NSArray arrayWithArray:mAry];
}

- (NSArray *)filterWithBlock:(PredicateBlock)block {
  NSMutableArray *mAry = [[NSMutableArray alloc] initWithCapacity:[self count]];
  
  for (id element in self) {
    if (block(element)) {
      [mAry addObject:element];
    }
  }
  
  return [NSArray arrayWithArray:mAry];
}

- (BOOL)anyWithBlock:(PredicateBlock)block {
  for (id element in self) {
    if (block(element)) {
      return YES;
    }
  }
  
  return NO;
}

- (id)detectWithBlock:(PredicateBlock)block {
  for (id element in self) {
    if (block(element)) {
      return element;
    }
  }
  
  return nil;
}

+ (NSArray *)arrayWithNumbersFromInts:(int)first, ... {
  NSMutableArray *mAry = [[NSMutableArray alloc] init];
  
  va_list args;
  va_start(args, first);
  int value;
  if (first) {
    [mAry addObject:[NSNumber numberWithInt:first]];
  }
  while ((value = va_arg(args, int))) {
    [mAry addObject:[NSNumber numberWithInt:value]];
  }
  va_end(args);
  
  return [NSArray arrayWithArray:mAry];
}

@end

@implementation NSSet (SequenceUtils)

- (NSSet *)mapWithBlock:(SequenceBlock)block {
  NSMutableSet *mSet = [[NSMutableSet alloc] initWithCapacity:[self count]];
  
  for (id element in self) {
    [mSet addObject:block(element)];
  }
  
  return [NSSet setWithSet:mSet];
}

- (NSSet *)filterWithBlock:(PredicateBlock)block {
  NSMutableSet *mSet = [[NSMutableSet alloc] initWithCapacity:[self count]];
  
  for (id element in self) {
    if (block(element)) {
      [mSet addObject:element];
    }
  }
  
  return [NSSet setWithSet:mSet];
}

- (BOOL)anyWithBlock:(PredicateBlock)block {
  for (id element in self) {
    if (block(element)) {
      return YES;
    }
  }
  
  return NO;
}

- (id)detectWithBlock:(PredicateBlock)block {
  for (id element in self) {
    if (block(element)) {
      return element;
    }
  }
  
  return nil;
}

@end

@implementation NSDictionary (SequenceUtils)

- (NSDictionary *)mapWithBlock:(SequenceBlock)block {
  NSMutableDictionary *mDict = [[NSMutableDictionary alloc] initWithCapacity:[self count]];
  
  for (id key in [self keyEnumerator]) {
    [mDict setObject:block([self objectForKey:key]) forKey:key];
  }
  
  return [NSDictionary dictionaryWithDictionary:mDict];
}

- (NSDictionary *)mapKeysWithBlock:(SequenceBlock)block {
  NSMutableDictionary *mDict = [[NSMutableDictionary alloc] initWithCapacity:[self count]];
  
  for (id key in [self keyEnumerator]) {
    [mDict setObject:[self objectForKey:key] forKey:block(key)];
  }
  
  return [NSDictionary dictionaryWithDictionary:mDict];
}

- (NSDictionary *)filterWithBlock:(PredicateBlock)block {
  NSMutableDictionary *mDict = [[NSMutableDictionary alloc] initWithCapacity:[self count]];
  
  for (id key in [self keyEnumerator]) {
    if (block([self objectForKey:key])) {
      [mDict setObject:[self objectForKey:key] forKey:key];
    }
  }
  
  return [NSDictionary dictionaryWithDictionary:mDict];
}

- (NSDictionary *)filterByKeyWithBlock:(PredicateBlock)block {
  NSMutableDictionary *mDict = [[NSMutableDictionary alloc] initWithCapacity:[self count]];
  
  for (id key in [self keyEnumerator]) {
    if (block(key)) {
      [mDict setObject:[self objectForKey:key] forKey:key];
    }
  }
  
  return [NSDictionary dictionaryWithDictionary:mDict];
}

- (BOOL)anyWithBlock:(PredicateBlock)block {
  for (id obj in [self objectEnumerator]) {
    if (block(obj)) {
      return YES;
    }
  }
  
  return NO;
}

- (BOOL)anyKeyWithBlock:(PredicateBlock)block {
  for (id key in [self keyEnumerator]) {
    if (block(key)) {
      return YES;
    }
  }
  
  return NO;
}

- (id)detectWithBlock:(PredicateBlock)block {
  for (id obj in [self objectEnumerator]) {
    if (block(obj)) {
      return obj;
    }
  }
  
  return nil;
}

- (id)detectKeyWithBlock:(PredicateBlock)block {
  for (id key in [self keyEnumerator]) {
    if (block(key)) {
      return key;
    }
  }
  
  return nil;
}

@end

@implementation NSMutableArray (SequenceUtils)

- (void)addObjectToFront:(id)object {
  [self insertObject:object atIndex:0];
}

- (void)removeFirstObject {
  [self removeObjectAtIndex:0];
}

@end

@implementation NSNumber (SimpleMath)

+ (NSNumber *)numberByAddingNumbers:(NSNumber *)firstNumber, ... {
  NSNumber *newNumber = firstNumber;
  
  va_list args;
  va_start(args, firstNumber);
  
  for (NSNumber *argNumber = va_arg(args, NSNumber *); argNumber != nil; argNumber = va_arg(args, NSNumber *)) {
    newNumber = [NSNumber numberWithDouble:[newNumber doubleValue] + [argNumber doubleValue]];
  }
  
  va_end(args);
  
  return newNumber;
}

+ (NSNumber *)numberBySubtractingNumbers:(NSNumber *)firstNumber, ... {
  NSNumber *newNumber = firstNumber;
  
  va_list args;
  va_start(args, firstNumber);
  
  for (NSNumber *argNumber = va_arg(args, NSNumber *); argNumber != nil; argNumber = va_arg(args, NSNumber *)) {
    newNumber = [NSNumber numberWithDouble:[newNumber doubleValue] - [argNumber doubleValue]];
  }
  
  va_end(args);
  
  return newNumber;
}

+ (NSNumber *)numberByMultiplyingNumbers:(NSNumber *)firstNumber, ... {
  NSNumber *newNumber = firstNumber;
  
  va_list args;
  va_start(args, firstNumber);
  
  for (NSNumber *argNumber = va_arg(args, NSNumber *); argNumber != nil; argNumber = va_arg(args, NSNumber *)) {
    newNumber = [NSNumber numberWithDouble:[newNumber doubleValue] * [argNumber doubleValue]];
  }
  
  va_end(args);
  
  return newNumber;
}

+ (NSNumber *)numberByDividingNumbers:(NSNumber *)firstNumber, ... {
  NSNumber *newNumber = firstNumber;
  
  va_list args;
  va_start(args, firstNumber);
  
  for (NSNumber *argNumber = va_arg(args, NSNumber *); argNumber != nil; argNumber = va_arg(args, NSNumber *)) {
    newNumber = [NSNumber numberWithDouble:[newNumber doubleValue] / [argNumber doubleValue]];
  }
  
  va_end(args);
  
  return newNumber;
}

@end