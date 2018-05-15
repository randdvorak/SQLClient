#import <Foundation/Foundation.h>
#import "SQLClient.h"

#define USER @"test"
#define PASS @"password"
#define SERVER @"server"
#define DATABASE @"master"

int main(int argc, const char * argv[]) {
	@autoreleasepool {
	
	SQLClient* client = [SQLClient sharedInstance];
	[client connect:SERVER username:USER password:PASS database:DATABASE];
	
	NSString* data = @"THIS IS TEST DATA";
	NSData* bin = [data dataUsingEncoding:NSUTF8StringEncoding];
	
	NSArray* args = @[@{@"@intin %d":@123},@{@"@intout out %d":[NSNull null]},@{@"@fltin %f":@3.14159},
					  @{@"@fltout out %f":[NSNull null]}, @{@"@bitin %b":@0}, @{@"@bitout out %b":[NSNull null]},
					   @{@"@datein %D":[NSDate date]}, @{@"@dateout out %D":[NSNull null]}, @{@"@stringin %s":@"TEST STRING"},
					    @{@"@stringout out %s":[NSNull null]}, @{@"@datain %B":bin}, @{@"@dataout out %B":[NSNull null]}];
		
	NSArray* results = [client call:@"rpctest" withArguments:args];
	NSLog(@"RESULTS: %@", results);
	NSData* rslt = [[results objectAtIndex:0] objectForKey:@"@dataout"];
	data = [[NSString alloc] initWithData:rslt encoding:NSUTF8StringEncoding];
	NSLog(@"DATA: %@", data);

	}
	return 0;
}
