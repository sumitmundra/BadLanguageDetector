// BadWordList.h
//
// Copyright (c) 2013 Konstant Info Private Limited
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.


#import <Foundation/Foundation.h>


@interface CharacterNode : NSObject {
	char c;
	bool leaf;
	uint8_t numChildren;
	CharacterNode *children;
}
@property (nonatomic, readonly) char c;
@property (nonatomic, readonly) CharacterNode *children;
@property (nonatomic, assign) bool leaf;
- (id)initWithUnichar:(char)cc;
- (void)addNode:(CharacterNode *)node;
+ (CharacterNode *)nodeWithUnichar:(char)cc;
- (CharacterNode *)nodeAtIndex:(uint8_t)index;
- (CharacterNode *)lastNode;
- (CharacterNode *)nodeContainingUnichar:(char)cc;
- (void)freeChildren;
@end




@interface RootCharacterNode : CharacterNode
- (id)initWithFilePath:(NSString *)filePath;
- (void)addWord:(NSString *)word;
- (BOOL)isWord:(NSString *)word;
@end




@interface BadWordList : NSObject{
	RootCharacterNode *root;
}
- (id)init;
- (NSString *)detectBadWordsOn:(NSString *)string;
@end
