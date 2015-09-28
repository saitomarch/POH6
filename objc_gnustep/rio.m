#import <Foundation/Foundation.h>

@interface Coffee : NSObject {
@private
    float _powder;
    float _water;
}
@property float powder;
@property float water;
@property (readonly) float total;
@property (readonly) float consentration;
- (void)taste: (float)quantity;
@end

@implementation Coffee
@synthesize powder = _powder;
@synthesize water = _water;
- (float)total {
    return _powder + _water;
}
- (float)consentration {
    return _powder / self.total;
}
- (void)taste:(float)quantity {
    float total = self.total;
    _powder -= quantity * _powder / total;
    _water -= quantity * _water / total;
}
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *(^readData)() = ^{
            return [[[NSString alloc] initWithData:[[NSFileHandle fileHandleWithStandardInput] readDataToEndOfFile] encoding:NSUTF8StringEncoding] autorelease];
        };
        void (^writeData)(NSString *) = ^(NSString *str){
            [[NSFileHandle fileHandleWithStandardOutput] writeData:[str dataUsingEncoding:NSUTF8StringEncoding]];
        };

        Coffee *coffee = [[[Coffee alloc] init] autorelease];
        NSArray *lines = [readData() componentsSeparatedByString:@"\n"];
        NSInteger times = [[lines objectAtIndex:0] integerValue];
        for (int count = 1; count <= times; count++) {
            NSArray *actArr = [[lines objectAtIndex:count] componentsSeparatedByString:@" "];
            NSInteger action = [[actArr objectAtIndex:0] integerValue];
            float quantity = [[actArr objectAtIndex:1] floatValue];
            switch (action) {
                case 1:
                    coffee.water += quantity;
                    break;
                case 2:
                    coffee.powder += quantity;
                    break;
                case 3:
                    [coffee taste:quantity];
                    break;
                default:
                    break;
            }
        }
        writeData([NSString stringWithFormat:@"%ld\n", (long)(coffee.consentration * 100.0)]);
        return EXIT_SUCCESS;
    }
}
