#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *(^readData)() = ^{
            return [[[NSString alloc] initWithData:[[NSFileHandle fileHandleWithStandardInput] readDataToEndOfFile] encoding:NSUTF8StringEncoding] autorelease];
        };
        void (^writeData)(NSString *) = ^(NSString *str){
            [[NSFileHandle fileHandleWithStandardOutput] writeData:[str dataUsingEncoding:NSUTF8StringEncoding]];
        };
        NSString *str = [readData() stringByReplacingOccurrencesOfString:@"\n" withString:@""];
        NSInteger num = str.integerValue;
        for (NSInteger idx = 0; idx < str.length; idx++) {
            num += [str characterAtIndex:idx] - '0';
        }
        writeData([@(num).stringValue stringByAppendingString:@"\n"]);
        return EXIT_SUCCESS;
    }
}
