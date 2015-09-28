
#import <Foundation/Foundation.h>

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSString *(^readData)() = ^{
            return [[[NSString alloc] initWithData:[[NSFileHandle fileHandleWithStandardInput] readDataToEndOfFile] encoding:NSUTF8StringEncoding] autorelease];
        };
        void (^writeData)(NSString *) = ^(NSString *str){
            [[NSFileHandle fileHandleWithStandardOutput] writeData:[str dataUsingEncoding:NSUTF8StringEncoding]];
        };

        NSInteger offset = 0;

        NSArray *lines = [readData() componentsSeparatedByString:@"\n"];
        NSInteger numOfCells = [[lines objectAtIndex:offset++] integerValue];
        NSInteger goal = numOfCells - 1;

        NSArray *cells = [[lines objectAtIndex:offset++] componentsSeparatedByString:@" "];

        NSInteger numOfActs = [[lines objectAtIndex:offset++] integerValue];

        enum State {
            CURRENT = 0,
            FINISHED,
            DEAD,
        };

        for (NSInteger count = 0; count < numOfActs; count++) {
            NSInteger actNum = [[lines objectAtIndex:count + offset] integerValue];
            NSMutableArray *moveLog = [NSMutableArray array];
            enum State status = CURRENT;
            while (status == CURRENT) {
                if (actNum == goal) {
                    status = FINISHED;
                }else if(actNum < 1 || goal < actNum) {
                    status = DEAD;
                }else{
                    NSInteger moves = [[cells objectAtIndex:actNum] integerValue];
                    if (moves == 0) {
                        status = DEAD;
                    }else{
                        actNum += moves;
                        for (NSString *moved in moveLog) {
                            if (actNum == moved.integerValue) {
                                status = DEAD;
                                break;
                            }
                        }
                        if (status != DEAD) {
                            [moveLog addObject:@(actNum)];
                        }
                    }
                }
            }
            writeData(status == FINISHED ? @"Yes\n" : @"No\n");
        }
        return EXIT_SUCCESS;
    }
}
